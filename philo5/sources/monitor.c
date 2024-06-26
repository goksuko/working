/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 15:11:59 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/19 11:37:20 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor(void *param)
{
	t_table	*table;

	table = (t_table *)param;
	while (1)
	{
		if (to_finish(table))
			break ;
	}
	return (NULL);
}

void	monitor_init(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_create(&table->monitor_thread, NULL, &monitor, table))
	{
		free(table->philos);
		free(table->forks);
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->meal_lock);
		pthread_mutex_destroy(&table->print_lock);
		while (i < table->no_of_philos)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		ft_exit_perror(ERROR_THREAD, "Monitor thread creation");
	}
	return ;
}
