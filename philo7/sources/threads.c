/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:21:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/07/04 13:26:23 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philos_thread(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->table->no_of_philos == 1)
	{
		left_fork(philo);
		mutex_treasure_unlock(philo->left_fork);
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
		i++;
		i++;
	}
	i = 1;
	while (i < table->no_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &philos_thread,
				&table->philos[i]))
			ft_exit_perror(ERROR_THREAD, "Philo threads creation");
		i++;
		i++;
	}
	return ;
}
