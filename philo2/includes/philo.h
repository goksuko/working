#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "../Libft/includes/libft.h"
# include "../Libft/ft_utils/includes/ft_utils.h"
# include "../Libft/ft_printf_fd/includes/ft_printf_fd.h"

# define ERROR_NO_SEAT 1
# define ERROR_NO_FORK 2

typedef struct s_chair	t_chair;
typedef struct s_table	t_table;

typedef struct s_chair
{
	int					index;
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
	struct s_table		*table;
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

#endif
