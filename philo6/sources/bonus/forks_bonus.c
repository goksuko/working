/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 11:20:50 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/27 19:51:21 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

bool	take_forks(t_philo *philo)
{
	if (to_finish(philo->table))
		return (false);
	mutex_treasure_lock(philo->forks_lock);
	if (philo->table->forks_available >= 2)
	{
		philo->table->forks_available--;
		philo->table->forks_available--;
		mutex_treasure_unlock(philo->forks_lock);
		print_status(philo, FORK);
		print_status(philo, FORK);
		return (true);
	}
	else
	{
		mutex_treasure_unlock(philo->forks_lock);
		return (false);
	}
}

bool	leave_forks(t_philo *philo)
{
	mutex_treasure_lock(philo->forks_lock);
	philo->table->forks_available++;
	philo->table->forks_available++;
	mutex_treasure_unlock(philo->forks_lock);
	return (true);
}
