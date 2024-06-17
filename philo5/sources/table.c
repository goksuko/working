/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 15:05:37 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/18 00:38:08 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	table_init_continue1(t_table *table)
{
	if (pthread_mutex_init(&table->dead_lock, NULL) < 0)
	{
		free(table->philos);
		ft_exit_perror(ERROR_MUTEX_INIT, "Dead Lock in Table Init");
	}
	if (pthread_mutex_init(&table->meal_lock, NULL) < 0)
	{
		free(table->philos);
		pthread_mutex_destroy(&table->dead_lock);
		ft_exit_perror(ERROR_MUTEX_INIT, "Meal Lock in Table Init");
	}
	if (pthread_mutex_init(&table->print_lock, NULL) < 0)
	{
		free(table->philos);
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->meal_lock);
		ft_exit_perror(ERROR_MUTEX_INIT, "Print Lock in Table Init");
	}
}

void	table_init_continue2(t_table *table)
{
	table->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t),
			table->NO_OF_PHILOS);
	if (errno == ENOMEM || !table->forks)
	{
		free(table->philos);
		pthread_mutex_destroy(&table->dead_lock);
		pthread_mutex_destroy(&table->meal_lock);
		pthread_mutex_destroy(&table->print_lock);
		ft_exit_perror(ERROR_ALLOCATION, "Forks in Table Init");
	}
}

void	table_init_continue3(t_table *table)
{
	int	i;

	i = 0;
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
	table->forks = &table->forks[0];
}

void	table_init(t_table *table, int argc, char **argv)
{
	table->dead_flag = 0;
	table->full_flag = 0;
	table->NO_OF_PHILOS = ft_atoi(argv[1]);
	table->DIE_TIME = ft_atoi(argv[2]);
	table->EAT_TIME = ft_atoi(argv[3]);
	table->SLEEP_TIME = ft_atoi(argv[4]);
	table->start_time = get_current_time();
	if (argc == 6)
		table->NO_OF_EAT = ft_atoi(argv[5]);
	else
		table->NO_OF_EAT = MAX_EAT;
	table->philos = (t_philo *)ft_calloc(sizeof(t_philo), table->NO_OF_PHILOS);
	if (errno == ENOMEM || !table->philos)
		ft_exit_perror(ERROR_ALLOCATION, "Philos in Table Init");
	table_init_continue1(table);
	table_init_continue2(table);
	table_init_continue3(table);
}
