/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 15:06:13 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/10 14:15:31 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"	

void philos_init(t_table *table)
{
	int	i;

	// ft_printf("no of philos in philos init: %d\n", table->NO_OF_PHILOS);
	i = 0;
	while (i < table->NO_OF_PHILOS)
	{
		// ft_printf("no of philos in loop: %d\n", table->NO_OF_PHILOS);
		// ft_printf("i: %d\n", i);
		table->philos[i].index = i;
		table->philos[i].print_lock = &table->print_lock;
		table->philos[i].dead_lock = &table->dead_lock;
		table->philos[i].meal_lock = &table->meal_lock;
		table->philos[i].has_eaten = 0;
		table->philos[i].last_meal_time = 0;
		table->philos[i].dead_flag = &table->dead_flag;
		table->philos[i].right_fork = &table->forks[i];
		table->philos[i].left_fork = &table->forks[(i + 1) % table->NO_OF_PHILOS];
		table->philos[i].status = THINKING;
		table->philos[i].table = table;
		// if (pthread_mutex_init(&table->philos[i].eat_mutex, NULL) < 0)
		// {
		// 	while (i > 0)
		// 	{
		// 		i--;
		// 		pthread_mutex_destroy(&table->philos[i].eat_mutex);
		// 	}
		// 	clean_table(table);
		// 	ft_exit_perror(ERROR_MUTEX_INIT, "Eat Mutex in Philos Init");
		// }
		// ft_printf_fd(1, "Philos[%d] is ready\n", i);
		// print_status(&table->philos[i], table->philos[i].status);
		i++;
	}
}