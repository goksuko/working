/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 00:22:53 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/25 12:44:36 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	destroy_forks_mutex(t_table *table)
{
	int	i;

	// i = 0;
	// while (i < table->no_of_philos)
	// {
	// 	pthread_mutex_unlock(&table->forks[i]);
	// 	i++;
	// }
	i = 0;
	while (i < table->no_of_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}

void	clean_all(t_table *table)
{
	// int	i;

	// pthread_mutex_unlock(&table->print_lock);
	// pthread_mutex_unlock(&table->meal_lock);
	// pthread_mutex_unlock(&table->dead_lock);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->dead_lock);
	// i = 0;
	// while (i < table->no_of_philos)
	// {
	// 	pthread_mutex_unlock(&table->forks[i]);
	// 	i++;
	// }
	// i = 0;
	// while (i < table->no_of_philos)
	// {
	// 	pthread_mutex_destroy(&table->forks[i]);
	// 	i++;
	// }
	destroy_forks_mutex(table);
	free(table->philos);
	free(table->forks);
	free(table);
	return ;
}
