/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:21:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/03 11:52:22 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*my_thread_func(void *ptr)
{
	pthread_t tid;
	t_table *my_table;

	my_table = ptr;
	tid = pthread_self();
	pthread_mutex_lock(&my_table->print_lock);
	printf("Thread [%ld] has started\n", tid);
	pthread_mutex_unlock(&my_table->print_lock);
	return (NULL); // The thread ends here.
}

void	threads_init(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		if (pthread_create(&philos[i].thread, NULL, my_thread_func, &table))
			ft_exit_perror(ERROR_THREAD, "Thread creation");
		usleep(1000);
		pthread_mutex_lock(&table->print_lock);
		ft_printf_fd(1, "created thread for %d\n", i + 1);
		pthread_mutex_unlock(&table->print_lock);
		i++;
	}
	table->threads = &philos[0].thread;
	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		pthread_mutex_lock(&table->print_lock);
		if (pthread_join(philos[i].thread, NULL))
			ft_exit_perror(ERROR_JOIN, "Thread join");
		ft_printf_fd(1, "joined thread for %d\n", i + 1);
		pthread_mutex_unlock(&table->print_lock);
		i++;
	}
}