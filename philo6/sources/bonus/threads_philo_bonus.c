/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads_philo_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/18 00:45:07 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/25 12:21:43 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	do_the_job(t_philo *philo)
{
	print_status(philo, EATING);
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal_time = get_current_time();
	philo->has_eaten++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->eat_time);
	leave_forks(philo);
	if (!to_finish(philo->table))
		print_status(philo, SLEEPING);
	ft_usleep(philo->table->sleep_time);
	if (!to_finish(philo->table))
		print_status(philo, THINKING);
}

bool	eat_sleep_think(t_philo *philo)
{
	if (take_forks(philo) && !to_finish(philo->table))
		do_the_job(philo);
	return (true);
}
