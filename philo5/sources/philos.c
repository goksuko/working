/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 15:06:13 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/18 00:47:00 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philos_init(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		table->philos[i].index = i;
		table->philos[i].print_lock = &table->print_lock;
		table->philos[i].dead_lock = &table->dead_lock;
		table->philos[i].meal_lock = &table->meal_lock;
		table->philos[i].has_eaten = 0;
		table->philos[i].last_meal_time = table->start_time;
		table->philos[i].dead_flag = &table->dead_flag;
		table->philos[i].full_flag = &table->full_flag;
		table->philos[i].status = THINKING;
		table->philos[i].table = table;
		i++;
	}
	table->philos = &table->philos[0];
	return ;
}
