/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 00:22:53 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/20 14:00:00 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	clean_all(t_table *table)
{
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->forks_lock);
	free(table->philos);
	free(table);
	return ;
}
