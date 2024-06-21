/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 12:42:46 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/11 22:18:17 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_if_died(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->last_meal_time != 0 && get_current_time() - philo->last_meal_time > philo->table->DIE_TIME)
	{
		print_status(philo, DIED);
		philo->table->dead_flag = 1;
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	check_if_full(t_philo *philo)
{
	int	check;
	int i;

	i = 0;
	check = 1;
	if (philo->table->NO_OF_EAT == -1)
		return (0);
	pthread_mutex_lock(philo->meal_lock);
	while (i < philo->table->NO_OF_PHILOS)
	{
		if (philo->table->philos[i].has_eaten < philo->table->NO_OF_EAT)
		{
			check = 0;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (check);
}

int	to_finish(t_table *table)
{
	int	check;

	pthread_mutex_lock(&(table->dead_lock));
	check = table->dead_flag;
	pthread_mutex_unlock(&(table->dead_lock));
	return (check);
}
