/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 12:19:43 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/03 13:20:44 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	forks_init(table, table->philos);
	ft_printf("forks init finished\n");
	threads_init(table, table->philos);
	ft_printf("threads init finished\n");
	start_eating(table, table->philos);
	// ft_printf("philos initialization finished\n");
	// print_status(table->philos, table->philos->status);
	if (monitor(table))
		return(ft_printf("monitor finished\n"), clean_all(table), 0);
	clean_all(table);
	return (0);
}
