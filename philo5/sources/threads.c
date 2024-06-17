/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:21:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/17 23:55:50 by akaya-oz      ########   odam.nl         */
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
	ft_usleep(philo->table->EAT_TIME);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	if (!to_finish(philo->table))
		print_status(philo, SLEEPING);
	ft_usleep(philo->table->SLEEP_TIME);
	if (!to_finish(philo->table))
		print_status(philo, THINKING);
}

bool eat_sleep_think(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		if (left_fork(philo))
		{
			if (right_fork(philo))
				do_the_job(philo);
			else
			{
				pthread_mutex_unlock(philo->left_fork);
				return (false);
			}
		}
		else
			return (false);
	}
	else
	{
		ft_usleep(50);
		print_status(philo, THINKING);
		if (right_fork(philo))
		{
			if (left_fork(philo))
				do_the_job(philo);
			else
			{
				pthread_mutex_unlock(philo->right_fork);
				return (false);
			}
		}
		else
			return (false);
	}
	
	// pthread_mutex_lock(&philo->table->print_lock);
	// printf("lastly philo %d has eaten %d times\n", philo->index + 1, philo->has_eaten);
	// pthread_mutex_unlock(&philo->table->print_lock);
	
	return (true);
}

void one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_lock);
	printf("inside 1 loop\n");
	pthread_mutex_unlock(&philo->table->print_lock);
	
	left_fork(philo);
	// ft_usleep(philo->table->DIE_TIME);

	// pthread_mutex_lock(&philo->table->print_lock);
	// printf("waited loop\n");
	// pthread_mutex_unlock(&philo->table->print_lock);

	pthread_mutex_unlock(philo->left_fork);

	// pthread_mutex_lock(&philo->table->print_lock);
	// printf("%lld %d %s\n", get_current_time(), 1, "died");
	// pthread_mutex_unlock(&philo->table->print_lock);
	pthread_mutex_lock(philo->dead_lock);
	philo->table->dead_flag = philo->index + 1;
	// pthread_mutex_lock(&philo->table->print_lock);
	// printf("dead flag loop\n");
	// pthread_mutex_unlock(&philo->table->print_lock);	
	// // print_status(philo, DIED);
	pthread_mutex_unlock(philo->dead_lock);

	// pthread_mutex_lock(&philo->table->print_lock);
	// printf("unlocked loop\n");
	// printf("dead flag: %d\n", philo->table->dead_flag);
	// pthread_mutex_unlock(&philo->table->print_lock);
	return ;
}

void	*philos_thread(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->table->NO_OF_PHILOS == 1)
	{
		one_philo(philo);

		pthread_mutex_lock(&philo->table->print_lock);
		printf("inside loop of 1 philo\n");
		pthread_mutex_unlock(&philo->table->print_lock);
		ft_usleep(philo->table->DIE_TIME);
		return (NULL);
	}
	while (1)
	{
		if (!eat_sleep_think(philo))
			break ;
		if (to_finish(philo->table))
			break ;
	}
	return (NULL);
}

void	threads_init(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		if (pthread_create(&philos[i].thread, NULL, &philos_thread, &table->philos[i]))
			ft_exit_perror(ERROR_THREAD, "Philo threads creation");
		ft_usleep(50);
		i++;
	}
	return ;
}