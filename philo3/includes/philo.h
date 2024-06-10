#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "../Libft/includes/libft.h"
# include "../Libft/ft_utils/includes/ft_utils.h"
# include "../Libft/ft_printf_fd/includes/ft_printf_fd.h"

# define MAX_EATEN 250

typedef enum e_action {
	THINKING,
	DIED,
	SLEEPING,
	EATING,
	FORK,
	TEST,
}	t_action;

typedef enum e_error {
	NO_ERROR,
	ERROR_ARGUMENT_COUNT,
	ERROR_INVALID_ARGUMENTS,
	ERROR_INVALID_PHILOS,
	ERROR_INVALID_DIE_TIME,
	ERROR_INVALID_EAT_TIME,
	ERROR_INVALID_SLEEP_TIME,
	ERROR_THREAD,
	ERROR_JOIN,
	ERROR_ALLOCATION,
	ERROR_INPUT,
	ERROR_MUTEX_INIT,
	ERROR_MUTEX_LOCK,
	ERROR_MUTEX_UNLOCK,
	ERROR_MUTEX_DESTROY,
	ERROR_USLEEP,
	UNDEFINED_ERROR,
}	t_error;

typedef struct s_philo {
	struct s_table	*table;
	int				*dead_flag;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*print_lock;
	int				index;
	pthread_t		thread;
	int				has_eaten;
	long long		last_meal_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	// pthread_mutex_t	eat_mutex;
	int				status;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos; //has the address of first philos
	// pthread_t		*threads;
	pthread_t		monitor_thread;
	pthread_mutex_t	*forks;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	print_lock;
	int				NO_OF_PHILOS;
	int				DIE_TIME;
	int				EAT_TIME;
	int				SLEEP_TIME;
	int				NO_OF_EAT;
}						t_table;

// table.c

void table_init(t_table *table, int argc, char **argv);
void monitor_init(t_table *table);

// philos.c

void philos_init(t_table *table);

// check.c

int	check_if_died(t_philo *philo);
int	check_if_full(t_philo *philo);
int	to_finish(t_table *table);

// monitor.c

// int	monitor(t_table *table);

// errors.c

char *ft_error(t_error code);
int	ft_print_error(t_error code);
bool check_argument_count_problem(int argc);
bool check_argument_problem(int argc, char **argv);
void ft_exit_perror(t_error code, char *s);
void ft_exit_print(t_error code);
// void clean_table(t_table *table);
void clean_all(t_table *table);

// print.c

void print_status(t_philo *philo, t_action status);
int	ft_usleep(size_t milliseconds);
long long	get_current_time(void);


// threads.c

void	threads_init(t_table *table, t_philo *philos);
void	eat_and_sleep(t_table *table, t_philo *philos, int i);

// forks.c

void	forks_init(t_table *table, t_philo *philos);
void start_eating(t_table *table, t_philo *philos);

// main.c

void join_threads(t_table *table);

#endif
