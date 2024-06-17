/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 12:42:46 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/17 23:16:21 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// int	check_if_died(t_table *table)
// {
// 	// int	dead_flag;
// 	int i;
// 	long long last_meal_time;
	
// 	// dead_flag = 0;
// 	i = 0;
// 	// pthread_mutex_lock(&table->dead_lock);
// 	// dead_flag = table->dead_flag;
// 	// if (dead_flag > 0)
// 	// {
// 	// 	print_status(&table->philos[dead_flag - 1], DIED);
// 	// 	pthread_mutex_unlock(&table->dead_lock);
// 	// 	return (dead_flag);
// 	// }
// 	// pthread_mutex_unlock(&table->dead_lock);
// 	// return (0);
// 	// pthread_mutex_lock(&table->dead_lock);
// 	while (i < table->NO_OF_PHILOS)
// 	{
// 		pthread_mutex_lock(&table->meal_lock);
// 		last_meal_time = table->philos[i].last_meal_time;
// 		pthread_mutex_unlock(&table->meal_lock);		
// 		if (last_meal_time != table->start_time && get_current_time() - last_meal_time > table->DIE_TIME)
// 		{
// 			// pthread_mutex_lock(&table->print_lock);
// 			// printf("%lld %d died\n", get_current_time() - table->start_time, table->philos[i].index + 1);
// 			// pthread_mutex_unlock(&table->print_lock);
			
// 			pthread_mutex_lock(&table->dead_lock);
// 			table->dead_flag = table->philos[i].index + 1;
// 			pthread_mutex_unlock(&table->dead_lock);
// 			return (i);
// 		}
// 		i++;
// 	}
// 	// pthread_mutex_unlock(&table->dead_lock);
// 	return (0);
// }

int	check_if_full(t_table *table)
{
	int	full_flag;
	int i;
	int j;	

	i = 0;
	j = 0;
	full_flag = 0;
	pthread_mutex_lock(&table->meal_lock);
	while (i < table->NO_OF_PHILOS)
	{
		if (table->philos[i].has_eaten >= table->NO_OF_EAT)
			j++;
		i++;
	}
	if (j == table->NO_OF_PHILOS)
		full_flag = 1;
	pthread_mutex_unlock(&table->meal_lock);
	return (full_flag);
}

int check_if_died(t_table *table)
{
	int i;
	long long last_meal_time;
	
	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		pthread_mutex_lock(&table->meal_lock);
		last_meal_time = table->philos[i].last_meal_time;
		pthread_mutex_unlock(&table->meal_lock);		
		if (last_meal_time != table->start_time && get_current_time() - last_meal_time > table->DIE_TIME)
		{
			pthread_mutex_lock(&table->dead_lock);
			table->dead_flag = table->philos[i].index + 1;
			pthread_mutex_unlock(&table->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	to_finish(t_table *table)
{
	if (check_if_full(table))
		return(1);
	if (check_if_died(table))
		return (1);
	return (0);
}
