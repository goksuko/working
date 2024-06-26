/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads_philo.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 00:45:07 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/27 00:47:31 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	do_the_job(t_philo *philo)
{
	print_status(philo, EATING);
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->has_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->eat_time);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (!to_finish(philo->table))
		print_status(philo, SLEEPING);
	else
		return ;
	ft_usleep(philo->table->sleep_time);
	print_status(philo, THINKING);
}

bool	even_philo(t_philo *philo)
{
	// if (check_if_starving(philo))
	// 	return (false);
	while (1)
	{
		if (to_finish(philo->table))
			return (false);
		if (check_if_starving(philo))
			return (false);
		if (left_fork(philo))
			break ;
	}
	// if (left_fork(philo))
	// {
	if (right_fork(philo))
	{
		do_the_job(philo);
		return (true);
	}
	else
	// {
		pthread_mutex_unlock(philo->left_fork);
	// 	return (false);
	// }
	// }
	// else
	// {		
	check_if_starving(philo);
	return (false);
	// }
}

bool	odd_philo(t_philo *philo)
{
	ft_usleep(1);
	// if (check_if_starving(philo))
	// 	return (false);
	while (1)
	{
		if (to_finish(philo->table))
			return (false);
		if (check_if_starving(philo))
			return (false);
		if (right_fork(philo))
			break ;
	}
	// if (right_fork(philo))
	// {
	if (left_fork(philo))
	{
		do_the_job(philo);
		return (true);
	}
	else
	// {
		pthread_mutex_unlock(philo->right_fork);
	// 	return (false);
	// }
	// }
	// else
	// {		
	check_if_starving(philo);
	return (false);
	// }
}

bool	eat_sleep_think(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		if (!even_philo(philo))
			return (false);
	}
	else
	{
		if (!odd_philo(philo))
			return (false);
	}
	return (true);
}
