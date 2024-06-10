/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 12:19:43 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/10 21:53:44 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void join_threads(t_table *table)
{
	int i;

	i = 0;
	// pthread_mutex_lock(&table->print_lock);
	// ft_printf_fd(1, "loop finished\n");
	// pthread_mutex_unlock(&table->print_lock);
	while (i < table->NO_OF_PHILOS)
	{
		// pthread_mutex_lock(&table->print_lock);
		// ft_printf_fd(1, "i: %d\n", i);
		// pthread_mutex_unlock(&table->print_lock);
		// pthread_mutex_lock(&table->print_lock);
		if (pthread_join(table->philos[i].thread, NULL))
			ft_exit_perror(ERROR_JOIN, "Thread join");
		// pthread_mutex_unlock(&table->print_lock);
		i++;
	}
	// pthread_mutex_lock(&table->print_lock);
	if (pthread_join(table->monitor_thread, NULL))
		ft_exit_perror(ERROR_JOIN, "Thread join");
	// ft_printf_fd(1, "joined monitor thread\n");
	// pthread_mutex_unlock(&table->print_lock);
}

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (check_argument_count_problem(argc))
		return (ft_print_error(ERROR_ARGUMENT_COUNT));
	if (check_argument_problem(argc, argv))
		return (ft_print_error(ERROR_INVALID_ARGUMENTS));
	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	if(errno == ENOMEM || !table)
		ft_exit_perror(ERROR_ALLOCATION, "Table in Main");
	table_init(table, argc, argv);
	ft_printf("table init finished\n");
	// ft_printf("argv1: %s\n", argv[1]);
	philos_init(table);
	ft_printf("philos init finished\n");
	// ft_usleep(1000);
	forks_init(table, table->philos);
	ft_printf("forks init finished\n");
	// ft_usleep(1000);
	monitor_init(table);
	pthread_mutex_lock(&table->print_lock);
	ft_printf("monitor init finished\n");
	pthread_mutex_unlock(&table->print_lock);
	threads_init(table, table->philos);
	
	// pthread_mutex_lock(&table->print_lock);
	// ft_printf("threads init finished\n");
	// pthread_mutex_unlock(&table->print_lock);

	// start_eating(table, table->philos);
	// ft_printf("philos initialization finished\n");
	// print_status(table->philos, table->philos->status);

	// joining threads
	// i = 0;
	// while (i < table->NO_OF_PHILOS)
	// {
	// 	pthread_mutex_lock(&table->print_lock);
	// 	if (pthread_join(table->philos[i].thread, NULL))
	// 		ft_exit_perror(ERROR_JOIN, "Thread join");
	// 	ft_printf_fd(1, "joined thread for %d\n", i + 1);
	// 	pthread_mutex_unlock(&table->print_lock);
	// 	i++;
	// }

	// pthread_mutex_lock(&table->print_lock);
	// printf("%d\n", to_finish(table));
	// pthread_mutex_unlock(&table->print_lock);
	join_threads(table);
	if (to_finish(table))
	{
		pthread_mutex_lock(&table->print_lock);
		printf("%d\n", to_finish(table));
		pthread_mutex_unlock(&table->print_lock);
		// join_threads(table);
		return(ft_printf("to be finished\n"), clean_all(table), 0);
	}
	// join_threads(table);
	// clean_all(table);
	// return (0);
}
