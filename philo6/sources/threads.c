/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:21:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/27 09:38:25 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	one_philo(t_philo *philo)
// {
// 	left_fork(philo);
// 	pthread_mutex_unlock(philo->left_fork);
// 	return ;
// }

void	*philos_thread(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->table->no_of_philos == 1)
	{
		// one_philo(philo);
		left_fork(philo);
		pthread_mutex_unlock(philo->left_fork);
		ft_usleep(philo->table->die_time);
		print_dead(philo, DIED);
		return (NULL);
	}
	while (1)
	{
		if (!eat_sleep_think(philo))
			break ;
		if (to_finish(philo->table))
			break ;
	}
	return (NULL);
}

void	threads_init(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->no_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &philos_thread,
				&table->philos[i]))
			ft_exit_perror(ERROR_THREAD, "Philo threads creation");
		ft_usleep(4);
		i++;
	}
	return ;
}
