/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 12:19:43 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/25 17:31:15 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo(t_table *table)
{
	make_seating(table);
	// printf("seating made\n");

}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5 && argc != 6)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (1);
	}
	table = table_init(argv[1], argv[2], argv[3], argv[4], argv[5]);
	philo(table);
	free_table_and_others(table, ft_atoi(argv[1]));
	return (0);
}
