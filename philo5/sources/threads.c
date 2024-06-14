/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:21:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/12 00:00:41 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	*my_thread_func(void *ptr)
// {
// 	// pthread_t tid;
// 	t_philo *philo;

// 	philo = (t_philo *)ptr;
// 	// tid = pthread_self();
// 	// pthread_mutex_lock(&philo->table->print_lock);
// 	// printf("Thread [%ld] has started\n", tid);
// 	// pthread_mutex_unlock(&philo->table->print_lock);
// 	if (philo->index % 2 == 0)
// 	{
// 		if (left_fork(philo))
// 		{
// 			if (right_fork(philo) && philo->table->NO_OF_PHILOS > 1)
// 			{
// 				pthread_mutex_lock(&philo->table->meal_lock);
// 				print_status(philo, EATING);
// 				philo->last_meal_time = get_current_time();
// 				philo->has_eaten++;
// 				pthread_mutex_unlock(&philo->table->meal_lock);
// 				ft_usleep(philo->table->EAT_TIME);
// 				pthread_mutex_unlock(philo->right_fork);
// 				pthread_mutex_unlock(philo->left_fork);
// 				ft_usleep(philo->table->SLEEP_TIME);
// 				if (!to_finish(philo->table))
// 				{
// 					print_status(philo, SLEEPING);
// 				}
// 				if (!to_finish(philo->table))
// 					print_status(philo, THINKING);
// 			}
// 		}
// 	}
// 	else
// 	{
// 		ft_usleep(philo->table->EAT_TIME / 2);
// 		print_status(philo, THINKING);
// 		if (left_fork(philo) && right_fork(philo))
// 		{
// 			pthread_mutex_lock(&philo->table->meal_lock);
// 			print_status(philo, EATING);
// 			philo->last_meal_time = get_current_time();
// 			philo->has_eaten++;
// 			pthread_mutex_unlock(&philo->table->meal_lock);
// 			ft_usleep(philo->table->EAT_TIME);
// 			pthread_mutex_unlock(philo->right_fork);
// 			pthread_mutex_unlock(philo->left_fork);
// 			ft_usleep(philo->table->SLEEP_TIME);
// 			if (!to_finish(philo->table))
// 			{
// 				print_status(philo, SLEEPING);
// 			}
// 			if (!to_finish(philo->table))
// 				print_status(philo, THINKING);
// 		}
// 	}
// 	if (philo->table->NO_OF_PHILOS == 1)
// 	{
// 		ft_usleep(philo->table->DIE_TIME);
// 		pthread_mutex_lock(philo->dead_lock);
// 		philo->table->dead_flag = 1;
// 		print_status(philo, DIED);
// 		pthread_mutex_unlock(philo->dead_lock);
// 	}
// 	while(!to_finish(philo->table) && philo->table->NO_OF_PHILOS > 1)
// 	{
// 		eat_and_sleep(philo->table, philo, philo->index);
// 	}
// 	return (NULL); // The thread ends here.
// }

bool eat(t_philo *philo)
{
	// pthread_mutex_lock(&philo->table->print_lock);
	// printf("philo %d has eaten %d times\n", philo->index + 1, philo->has_eaten);
	// pthread_mutex_unlock(&philo->table->print_lock);
	
	if (philo->index % 2 == 0)
	{
		if (left_fork(philo))
		{
			pthread_mutex_lock(&philo->table->print_lock);
			printf("test 1 loop\n");
			pthread_mutex_unlock(&philo->table->print_lock);

			if (right_fork(philo) && philo->table->NO_OF_PHILOS > 1)
			{
				pthread_mutex_lock(&philo->table->print_lock);
				printf("test 2 loop\n");
				pthread_mutex_unlock(&philo->table->print_lock);

				pthread_mutex_lock(&philo->table->meal_lock);
				print_status(philo, EATING);
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
			else
			{

				pthread_mutex_lock(&philo->table->print_lock);
				printf("test 3 loop\n");
				pthread_mutex_unlock(&philo->table->print_lock);
					
				pthread_mutex_unlock(philo->left_fork);
				if (philo->table->NO_OF_PHILOS == 1)
				{
					pthread_mutex_lock(&philo->table->print_lock);
					printf("inside 1 loop\n");
					pthread_mutex_unlock(&philo->table->print_lock);
					
					ft_usleep(philo->table->DIE_TIME);
					pthread_mutex_lock(philo->dead_lock);
					philo->table->dead_flag = philo->index + 1;
					print_status(philo, DIED);
					pthread_mutex_unlock(philo->dead_lock);
					// return (false);
				}
				return (false);
			}
		}
		else
			return (false);
	}
	else
	{
		ft_usleep(philo->table->EAT_TIME / 2);
		print_status(philo, THINKING);
		if (right_fork(philo))
		{
			if (left_fork(philo))
			{
				pthread_mutex_lock(&philo->table->meal_lock);
				print_status(philo, EATING);
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
			else
			{
				pthread_mutex_unlock(philo->right_fork);
				return (false);
			}
		}
		else
			return (false);
	}
	
	pthread_mutex_lock(&philo->table->print_lock);
	printf("lastly philo %d has eaten %d times\n", philo->index + 1, philo->has_eaten);
	pthread_mutex_unlock(&philo->table->print_lock);
	
	return (true);
}


void	*philos_thread(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		if (!eat(philo))
			break ;
		// if(!sleep(philo))
		// 	break ;
		// if (!think(philo))
		// 	break ;
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
		// pthread_mutex_lock(&table->print_lock);
		// printf("creating thread for %d\n", i + 1);
		// pthread_mutex_unlock(&table->print_lock);

		// if (pthread_create(&philos[i].thread, NULL, &my_thread_func, &table->philos[i]))
		if (pthread_create(&philos[i].thread, NULL, &philos_thread, &table->philos[i]))
			ft_exit_perror(ERROR_THREAD, "Philo threads creation");
		ft_usleep(250);
		
		// pthread_mutex_lock(&table->print_lock);
		// ft_printf_fd(1, "created thread for %d\n", i + 1);
		// pthread_mutex_unlock(&table->print_lock);
		i++;
	}
	// pthread_mutex_lock(&table->print_lock);
	// ft_printf_fd(1, "loop finished\n");
	// pthread_mutex_unlock(&table->print_lock);
	
	// table->threads = &philos[0].thread;

	// pthread_mutex_lock(&table->print_lock);
	// ft_printf_fd(1, "gonna join\n");
	// pthread_mutex_unlock(&table->print_lock);
	
	// join_threads(table);
	// pthread_mutex_lock(&table->print_lock);
	// printf("joined threads\n");
	// pthread_mutex_unlock(&table->print_lock);
	
	return ;
}

// void	eat_and_sleep(t_table *table, t_philo *philos, int i)
// {
	
// 	pthread_mutex_lock(&table->print_lock);
// 	printf("%p is for %d\n", &philos[i].right_fork, i + 1);
// 	pthread_mutex_unlock(&table->print_lock);

// 	if (left_fork(&philos[i]) && right_fork(&philos[i]) && table->NO_OF_PHILOS > 1)
// 	{
// 		pthread_mutex_lock(&table->meal_lock);
// 		print_status(&philos[i], EATING);
// 		philos[i].last_meal_time = get_current_time();
// 		philos[i].has_eaten++;
// 		pthread_mutex_unlock(&table->meal_lock);
// 		// pthread_mutex_lock(&philos[i].eat_mutex);
// 		ft_usleep(table->EAT_TIME);
// 		// pthread_mutex_unlock(&philos[i].eat_mutex);
// 		// pthread_mutex_lock(&table->print_lock);
// 		// printf("waiting for eating\n");
// 		// pthread_mutex_unlock(&table->print_lock);
// 	}
// 	pthread_mutex_unlock(philos[i].right_fork);
// 	pthread_mutex_unlock(philos[i].left_fork);
// 	ft_usleep(table->SLEEP_TIME);
// 	if (!to_finish(table))
// 	{
// 		print_status(&philos[i], SLEEPING);
// 	}
// 	if (!to_finish(table))
// 		print_status(&philos[i], THINKING);
// 	return ;
// }