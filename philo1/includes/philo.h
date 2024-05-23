#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

# define ERROR_NO_SEAT 1
# define ERROR_NO_FORK 2


typedef struct s_chair
{
	int					index;
	// int			philo_index;
	int					left_fork_index;
	int					right_fork_index;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
}						t_chair;

typedef struct s_seating
{
	t_chair				*chair;
	struct s_seating	*next;
}						t_seating;

typedef struct s_table
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	t_seating			*seating;
}						t_table;

// table.c

void	free_table_and_others(t_table *table, int number_of_philosophers);
void	make_seating(t_table *table);
t_table	*table_init(char *number_of_philosophers, char *time_to_die,
		char *time_to_eat, char *time_to_sleep,
		char *number_of_times_each_philosopher_must_eat);

// utils.c

int						ft_atoi(const char *nptr);
char					*ft_itoa(int n);

#endif
