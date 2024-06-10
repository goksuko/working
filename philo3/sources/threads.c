/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:21:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/10 22:37:51 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*my_thread_func(void *ptr)
{
	// pthread_t tid;
	t_philo *philo;

	philo = (t_philo *)ptr;
	// tid = pthread_self();
	// pthread_mutex_lock(&philo->table->print_lock);
	// printf("Thread [%ld] has started\n", tid);
	// pthread_mutex_unlock(&philo->table->print_lock);
	if (philo->index % 2 == 0)
	{
		// pthread_mutex_lock(philo->left_fork);
		// print_status(philo, FORK);

		// eat_and_sleep(philo->table, philo, philo->index);
		print_status(philo, TEST);

	}
	else
	{
		ft_usleep(philo->table->EAT_TIME / 2);
		print_status(philo, THINKING);
	}
	if (philo->table->NO_OF_PHILOS == 1)
	{
		ft_usleep(philo->table->DIE_TIME);
		pthread_mutex_lock(philo->dead_lock);
		philo->table->dead_flag = 1;
		print_status(philo, DIED);
		pthread_mutex_unlock(philo->dead_lock);
	}
	while(!to_finish(philo->table) && philo->table->NO_OF_PHILOS > 1)
	{
		eat_and_sleep(philo->table, philo, philo->index);
	}
	return (NULL); // The thread ends here.
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

		if (pthread_create(&philos[i].thread, NULL, &my_thread_func, &table->philos[i]))
			ft_exit_perror(ERROR_THREAD, "Philo threads creation");
		ft_usleep(100);
		
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

void	eat_and_sleep(t_table *table, t_philo *philos, int i)
{
	
	pthread_mutex_lock(&table->print_lock);
	printf("%p is for %d\n", &philos[i].right_fork, i + 1);
	pthread_mutex_unlock(&table->print_lock);

	if(pthread_mutex_lock(philos[i].right_fork) != 0)
	{
		clean_all(table);
		ft_exit_perror(ERROR_MUTEX_LOCK, "Right Fork");
	}
	print_status(&philos[i], FORK);
	if (pthread_mutex_lock(philos[i].left_fork) != 0)
	{
		clean_all(table);
		ft_exit_perror(ERROR_MUTEX_LOCK, "Left Fork");
	}
	print_status(&philos[i], FORK);
	if (!to_finish(table))
	{
		pthread_mutex_lock(&table->meal_lock);
		print_status(&philos[i], EATING);
		philos[i].last_meal_time = get_current_time();
		philos[i].has_eaten++;
		pthread_mutex_unlock(&table->meal_lock);
		// pthread_mutex_lock(&philos[i].eat_mutex);
		ft_usleep(table->EAT_TIME);
		// pthread_mutex_unlock(&philos[i].eat_mutex);
		// pthread_mutex_lock(&table->print_lock);
		// printf("waiting for eating\n");
		// pthread_mutex_unlock(&table->print_lock);
	}
	pthread_mutex_unlock(philos[i].right_fork);
	pthread_mutex_unlock(philos[i].left_fork);
	ft_usleep(table->SLEEP_TIME);
	if (!to_finish(table))
	{
		print_status(&philos[i], SLEEPING);
	}
	if (!to_finish(table))
		print_status(&philos[i], THINKING);
	return ;
}