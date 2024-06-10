/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 15:05:37 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/10 22:42:09 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*monitor(void *param)
{
	t_table	*table;
	int		i;
	int		full;

	table = (t_table *)param;
	i = 0;
	full = 0;
	while (!to_finish(table) && table->NO_OF_PHILOS > 1)
	{
		if (check_if_died(&table->philos[i]))
			break ;
		if (check_if_full(&table->philos[i]))
			full++;
		// else
		// 	full = 0;
		if (full == table->NO_OF_PHILOS)
		{
			pthread_mutex_lock(&table->dead_lock);
			table->dead_flag = 1;
			pthread_mutex_unlock(&table->dead_lock);
		}		
		if (++i == table->NO_OF_PHILOS)
			i = 0;
	}
	return (NULL);
}

void table_init(t_table *table, int argc, char **argv)
{
	int i;

	i = 0;
	table->dead_flag = 0;
	table->NO_OF_PHILOS = ft_atoi(argv[1]);
	// ft_printf("argv1: %s\n", argv[1]);
	// ft_printf("no of philos in table init: %d\n", table->NO_OF_PHILOS);
	table->DIE_TIME = ft_atoi(argv[2]);
	table->EAT_TIME = ft_atoi(argv[3]);
	table->SLEEP_TIME = ft_atoi(argv[4]);
	if (argc == 6)
		table->NO_OF_EAT = ft_atoi(argv[5]);
	else
		table->NO_OF_EAT = MAX_EATEN;
	table->philos = (t_philo *)ft_calloc(sizeof(t_philo), table->NO_OF_PHILOS);
	if (errno == ENOMEM || !table->philos)
		ft_exit_perror(ERROR_ALLOCATION, "Philos in Table Init");
	// table->threads = (pthread_t *)ft_calloc(sizeof(pthread_t), table->NO_OF_PHILOS);
	// printf("sizeof(pthread_t) = %zu bytes\n", sizeof(pthread_t));
	// table->threads = NULL;
	// if (errno == ENOMEM || !table->threads)
	// {
	// 	free(table->philos);
	// 	free(table->forks);
	// 	ft_exit_perror(ERROR_ALLOCATION, "Philo in Table Init");
	// }
	if (pthread_mutex_init(&table->dead_lock, NULL) < 0)
	{
		free(table->philos);
		// free(table->threads);
		ft_exit_perror(ERROR_MUTEX_INIT, "Dead Lock in Table Init");
	}
	if (pthread_mutex_init(&table->meal_lock, NULL) < 0)
	{
		free(table->philos);
		// free(table->threads);
		pthread_mutex_destroy(&table->dead_lock);
		ft_exit_perror(ERROR_MUTEX_INIT, "Meal Lock in Table Init");
	}
	if (pthread_mutex_init(&table->print_lock, NULL) < 0)
	{
		free(table->philos);
		// free(table->threads);
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->meal_lock);
		ft_exit_perror(ERROR_MUTEX_INIT, "Print Lock in Table Init");
	}
	table->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), table->NO_OF_PHILOS);
	if (errno == ENOMEM || !table->forks)
	{
		free(table->philos);
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->meal_lock);
		pthread_mutex_destroy(&table->print_lock);
		ft_exit_perror(ERROR_ALLOCATION, "Forks in Table Init");
	}
	while (i < table->NO_OF_PHILOS)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) < 0)
		{
			free(table->philos);
			free(table->forks);
			pthread_mutex_destroy(&table->dead_lock);
			pthread_mutex_destroy(&table->meal_lock);
			pthread_mutex_destroy(&table->print_lock);
			ft_exit_perror(ERROR_MUTEX_INIT, "Forks in Table Init");
		}
		i++;
	}

}

void monitor_init(t_table *table)
{
	int i;

	i = 0;	
	if(pthread_create(&table->monitor_thread, NULL, &monitor, table))
	{
		free(table->philos);
		free(table->forks);
		// free(table->threads);
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->meal_lock);
		pthread_mutex_destroy(&table->print_lock);
		while (i < table->NO_OF_PHILOS)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i++;
		}
		ft_exit_perror(ERROR_THREAD, "Monitor thread creation");
	}
}