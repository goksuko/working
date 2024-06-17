/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 11:20:50 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/18 00:32:04 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	forks_init(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		philos[i].left_fork = &table->forks[i];
		philos[i].right_fork = &table->forks[(i + 1) % table->NO_OF_PHILOS];
		i++;
	}
	table->forks = philos[0].left_fork;
}

bool	left_fork(t_philo *philo)
{
	if (to_finish(philo->table))
		return (false);
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, FORK);
	return (true);
}

bool	right_fork(t_philo *philo)
{
	if (to_finish(philo->table))
		return (false);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, FORK);
	return (true);
}