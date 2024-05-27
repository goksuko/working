/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 15:05:37 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/27 12:37:16 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void table_init(t_table *table, int argc, char **argv)
{
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
		table->NO_OF_EAT = -1;
	table->philos = (t_philo *)ft_calloc(sizeof(t_philo), table->NO_OF_PHILOS);
	if (errno == ENOMEM || !table->philos)
		ft_exit_perror(ERROR_ALLOCATION, "Philos in Table Init");
	table->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), table->NO_OF_PHILOS);
	if (errno == ENOMEM || !table->forks)
	{
		free(table->philos);
		ft_exit_perror(ERROR_ALLOCATION, "Forks in Table Init");
	}
	table->threads = (pthread_t *)ft_calloc(sizeof(pthread_t), table->NO_OF_PHILOS);
	if (errno == ENOMEM || !table->threads)
	{
		free(table->philos);
		free(table->forks);
		ft_exit_perror(ERROR_ALLOCATION, "Philo in Table Init");
	}
	if (pthread_mutex_init(&table->dead_lock, NULL) < 0)
	{
		free(table->philos);
		free(table->forks);
		free(table->threads);
		ft_exit_perror(ERROR_MUTEX_INIT, "Dead Lock in Table Init");
	}
	if (pthread_mutex_init(&table->meal_lock, NULL) < 0)
	{
		free(table->philos);
		free(table->forks);
		free(table->threads);
		pthread_mutex_destroy(&table->dead_lock);
		ft_exit_perror(ERROR_MUTEX_INIT, "Meal Lock in Table Init");
	}
	if (pthread_mutex_init(&table->print_lock, NULL) < 0)
	{
		free(table->philos);
		free(table->forks);
		free(table->threads);
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->meal_lock);
		ft_exit_perror(ERROR_MUTEX_INIT, "Print Lock in Table Init");
	}
}