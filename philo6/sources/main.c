/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 12:19:43 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/25 12:51:49 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->no_of_philos)
	{
		// if (pthread_join(table->philos[i].thread, NULL))
		pthread_join(table->philos[i].thread, NULL);
			// ft_exit_perror(ERROR_JOIN, "Thread join");
		i++;
	}
	// if (pthread_join(table->monitor_thread, NULL))
	pthread_join(table->monitor_thread, NULL);
		// ft_exit_perror(ERROR_JOIN, "Thread join");
}

void	finish_program(t_table *table)
{
	if (table->dead_flag > 0)
	{
		pthread_mutex_lock(&table->print_lock);
		printf("%lld %d %s\n", get_current_time(), table->dead_flag,
			"died");
		pthread_mutex_unlock(&table->print_lock);
	}
	clean_all(table);
	return ;
}

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (check_argument_count_problem(argc))
		return (ft_print_error(ERROR_ARGUMENT_COUNT));
	if (check_argument_problem(argc, argv))
		return (ft_print_error(ERROR_INVALID_ARGUMENTS));
	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	if (errno == ENOMEM || !table)
		ft_exit_perror(ERROR_ALLOCATION, "Table in Main");
	table_init(table, argc, argv);
	philos_init(table);
	forks_init(table, table->philos);
	monitor_init(table);
	threads_init(table, table->philos);
	join_threads(table);
	if (to_finish(table))
	{
		finish_program(table);
		return (0);
	}
	return (1);
}
