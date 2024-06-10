/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:21:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/10 14:23:02 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*my_thread_func(void *ptr)
{
	pthread_t tid;
	t_philo *philosopher;

	philosopher = (t_philo *)ptr;
	tid = pthread_self();
	pthread_mutex_lock(&philosopher->table->print_lock);
	printf("Thread [%ld] has started\n", tid);
	pthread_mutex_unlock(&philosopher->table->print_lock);
	if (philosopher->index % 2 == 0)
	{
		pthread_mutex_lock(philosopher->left_fork);
		// pthread_mutex_lock(&table->print_lock);
		// ft_printf_fd(1, "philo[%d] has taken left fork\n", i);
		print_status(philosopher, FORK);
		// pthread_mutex_unlock(&table->print_lock);
	}
	else
	{
		ft_usleep(philosopher->table->EAT_TIME / 2);
		print_status(philosopher, THINKING);
	}
	while(!to_finish(philosopher->table))
	{
		eat_and_sleep(philosopher->table, philosopher, philosopher->index);
	}
	return (NULL); // The thread ends here.
}

void	threads_init(t_table *table, t_philo *philos)
{
	int	i;

	// printf("threads init started\n");
	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		pthread_mutex_lock(&table->print_lock);
		printf("creating thread for %d\n", i + 1);
		pthread_mutex_unlock(&table->print_lock);

		if (pthread_create(&philos[i].thread, NULL, &my_thread_func, &table->philos[i]))
			ft_exit_perror(ERROR_THREAD, "Philo threads creation");
		ft_usleep(100);
		
		pthread_mutex_lock(&table->print_lock);
		ft_printf_fd(1, "created thread for %d\n", i + 1);
		pthread_mutex_unlock(&table->print_lock);
		i++;
	}
	table->threads = &philos[0].thread;



	// i = 0;
	// while (i < table->NO_OF_PHILOS)
	// {
	// 	pthread_mutex_lock(&table->print_lock);
	// 	if (pthread_join(philos[i].thread, NULL))
	// 		ft_exit_perror(ERROR_JOIN, "Thread join");
	// 	ft_printf_fd(1, "joined thread for %d\n", i + 1);
	// 	pthread_mutex_unlock(&table->print_lock);
	// 	i++;
	// }
	return ;
}

void	eat_and_sleep(t_table *table, t_philo *philos, int i)
{
	pthread_mutex_lock(philos[i].right_fork);
	print_status(&philos[i], FORK);
	pthread_mutex_lock(philos[i].left_fork);
	print_status(&philos[i], FORK);
	if (!to_finish(table))
	{
		print_status(&philos[i], EATING);
		pthread_mutex_lock(&table->meal_lock);
		philos[i].last_meal_time = get_current_time();
		philos[i].has_eaten++;
		pthread_mutex_unlock(&table->meal_lock);
		// pthread_mutex_lock(&philos[i].eat_mutex);
		ft_usleep(table->EAT_TIME);
		// pthread_mutex_unlock(&philos[i].eat_mutex);
	}
	pthread_mutex_unlock(philos[i].right_fork);
	pthread_mutex_unlock(philos[i].left_fork);
	if (!to_finish(table))
	{
		print_status(&philos[i], SLEEPING);
		ft_usleep(table->SLEEP_TIME);
	}
	if (!to_finish(table))
		print_status(&philos[i], THINKING);
	return ;
}