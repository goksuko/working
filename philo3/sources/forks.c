/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 11:20:50 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/03 12:58:33 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	forks_init(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		philos[i].right_fork = &table->forks[i];
		philos[i].left_fork = &table->forks[(i + 1) % table->NO_OF_PHILOS];
		i++;
	}
	table->forks = philos[0].right_fork;
}

void start_eating(t_table *table, t_philo *philos)
{
	int i;

	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		if (i % 2 == 0)
		{
			pthread_mutex_lock(philos[i].right_fork);
			pthread_mutex_lock(&table->print_lock);
			ft_printf_fd(1, "philo[%d] has taken right fork\n", i);
			pthread_mutex_unlock(&table->print_lock);
		}
		i++;
	}

// 	while (i < table->NO_OF_PHILOS)
// 	{
// 		pthread_mutex_lock(&philos[i].right_fork);
// 		pthread_mutex_lock(&philos[i].left_fork);
// 		pthread_mutex_lock(&table->print_lock);
// 		ft_printf_fd(1, "Philosopher %d is eating\n", i + 1);
// 		pthread_mutex_unlock(&table->print_lock);
// 		usleep(table->EAT_TIME * 1000);
// 		pthread_mutex_unlock(&philos[i].right_fork);
// 		pthread_mutex_unlock(&philos[i].left_fork);
// 		i++;
// 	}
}