/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 12:42:46 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/27 19:50:56 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	check_if_full(t_table *table)
{
	int	full_flag;
	int	i;
	int	j;

	i = 0;
	j = 0;
	full_flag = 0;
	mutex_treasure_lock(&table->meal_lock);
	while (i < table->no_of_philos)
	{
		if (table->philos[i].has_eaten >= table->no_of_eat)
			j++;
		i++;
	}
	if (j == table->no_of_philos)
	{
		table->full_flag = 1;
		full_flag = 1;
	}
	mutex_treasure_unlock(&table->meal_lock);
	return (full_flag);
}

int	check_if_died(t_table *table)
{
	int			i;
	long long	last_meal_time;

	i = 0;
	while (i < table->no_of_philos)
	{
		mutex_treasure_lock(&table->meal_lock);
		last_meal_time = table->philos[i].last_meal_time;
		mutex_treasure_unlock(&table->meal_lock);
		if (get_current_time() - last_meal_time > table->die_time)
		{
			mutex_treasure_lock(&table->dead_lock);
			table->dead_flag = table->philos[i].index + 1;
			mutex_treasure_unlock(&table->dead_lock);
			print_dead(&table->philos[i], DIED);
			return (1);
		}
		i++;
	}
	mutex_treasure_lock(&table->dead_lock);
	if (table->dead_flag)
		return (mutex_treasure_unlock(&table->dead_lock), 1);
	return (mutex_treasure_unlock(&table->dead_lock), 0);
}

bool	check_if_starving(t_philo *philo)
{
	long long	last_meal_time;
	long long	current_time;

	current_time = get_current_time();
	ft_usleep(2);
	mutex_treasure_lock(philo->meal_lock);
	last_meal_time = philo->last_meal_time;
	mutex_treasure_unlock(philo->meal_lock);
	if (current_time - last_meal_time > philo->table->die_time)
	{
		mutex_treasure_lock(philo->dead_lock);
		if (!philo->table->dead_flag)
			philo->table->dead_flag = philo->index + 1;
		mutex_treasure_unlock(philo->dead_lock);
		return (true);
	}
	return (false);
}

int	to_finish(t_table *table)
{
	if (check_if_full(table))
		return (1);
	if (check_if_died(table))
		return (1);
	return (0);
}
