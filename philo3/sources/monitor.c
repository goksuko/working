/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 15:11:59 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/10 13:14:39 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int	monitor(t_table *table)
// {
// 	int	i;

// 	while (1)
// 	{
// 		i = 0;
// 		while (i < table->NO_OF_PHILOS)
// 		{
// 			pthread_mutex_lock(&table->dead_lock);
// 			if (table->dead_flag)
// 			{
// 				pthread_mutex_unlock(&table->dead_lock);
// 				return (1);
// 			}
// 			pthread_mutex_unlock(&table->dead_lock);
// 			if (table->philos[i].has_eaten > table->NO_OF_EAT)
// 			{
// 				pthread_mutex_lock(&table->meal_lock);
// 				table->philos[i].has_eaten = -1;
// 				pthread_mutex_unlock(&table->meal_lock);
// 				return (1);
// 			}
// 			eat_and_sleep(table, table->philos, i);
// 			i++;
// 		}
// 	}
// 	return (0);
// }