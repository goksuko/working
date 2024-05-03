#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_chair
{
	int			index;
	// int			philo_index;
	int			left_fork_index;
	int			right_fork_index;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}				t_chair;

typedef struct s_fork
{
	int			index;
}				t_fork;

typedef struct s_seating
{
	t_chair				*chair;
	struct s_seating	*next;
}				t_seating;

typedef struct s_table
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	t_seating	*seating;
}				t_table;

// utils.c

int				ft_atoi(const char *nptr);
char			*ft_itoa(int n);

#endif
