/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 11:20:50 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/21 19:46:22 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

bool	take_forks(t_philo *philo)
{
	if (to_finish(philo->table))
		return (false);
	pthread_mutex_lock(philo->forks_lock);
	if (philo->table->forks_available >= 2)
	{
		philo->table->forks_available--;
		philo->table->forks_available--;
		pthread_mutex_unlock(philo->forks_lock);
		print_status(philo, FORK);
		print_status(philo, FORK);
		return (true);
	}
	else
	{
		pthread_mutex_unlock(philo->forks_lock);
		return (false);
	}
}

bool	leave_forks(t_philo *philo)
{
	if (to_finish(philo->table))
		return (false);
	pthread_mutex_lock(philo->forks_lock);
	philo->table->forks_available++;
	philo->table->forks_available++;
	pthread_mutex_unlock(philo->forks_lock);
	return (true);
}
