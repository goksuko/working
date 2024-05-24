/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/03 15:05:37 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/03 15:10:10 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_table_and_others(t_table *table, int number_of_philosophers)
{
	t_seating	*seating;
	t_seating	*next;

	seating = table->seating;
	while (number_of_philosophers--)
	{
		next = seating->next;
		free(seating->chair);
		free(seating);
		seating = next;
	}
	free(table);
}

void	make_seating(t_table *table)
{
	int			i;
	t_seating	*current;
	t_seating	*head;

	i = 0;
	head = malloc(sizeof(t_seating));
	// printf("t_seating malloc\n");
	if (!head)
	{
		printf("Error: Seating malloc failed\n");
		exit(3);
	}
	current = head;
	while (i < table->number_of_philosophers)
	{
		current->chair = malloc(sizeof(t_chair));
		// printf("t_chair malloc\n");
		if (!current->chair)
		{
			printf("Error: Chair malloc failed\n");
			exit(4);
		}
		current->chair->index = i;
		current->chair->left_fork_index = i;
		current->chair->time_to_die = table->time_to_die;
		current->chair->time_to_eat = table->time_to_eat;
		current->chair->time_to_sleep = table->time_to_sleep;
		current->chair->number_of_times_each_philosopher_must_eat = table->number_of_times_each_philosopher_must_eat;
		if (i == table->number_of_philosophers - 1)
		{
			current->chair->right_fork_index = 0;
			current->next = head;
		}
		else
		{
			current->chair->right_fork_index = i + 1;
			current->next = malloc(sizeof(t_seating));
			// printf("t_seating malloc\n");
			if (!current->next)
			{
				printf("Error: New chair malloc failed\n");
				exit(5);
			}
		}
		i++;
		current = current->next;
	}
	table->seating = head;
}

t_table	*table_init(char *number_of_philosophers, char *time_to_die,
		char *time_to_eat, char *time_to_sleep,
		char *number_of_times_each_philosopher_must_eat)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	// printf("t_table malloc\n");
	if (!table)
	{
		printf("Error: Table malloc failed\n");
		exit(2);
	}
	table->number_of_philosophers = ft_atoi(number_of_philosophers);
	if (table->number_of_philosophers < 1)
	{
		printf("Error: Number of philosophers must be at least 1\n");
		exit(3);
	}
	table->time_to_die = ft_atoi(time_to_die);
	table->time_to_eat = ft_atoi(time_to_eat);
	table->time_to_sleep = ft_atoi(time_to_sleep);
	if (number_of_times_each_philosopher_must_eat)
		table->number_of_times_each_philosopher_must_eat = ft_atoi(number_of_times_each_philosopher_must_eat);
	else
		table->number_of_times_each_philosopher_must_eat = -1;
	// printf("number_of_philosophers: %d\n", table->number_of_philosophers);
	// printf("time_to_die: %d\n", table->time_to_die);
	// printf("time_to_eat: %d\n", table->time_to_eat);
	// printf("time_to_sleep: %d\n", table->time_to_sleep);
	// printf("number_of_times_each_philosopher_must_eat: %d\n",
	// 	table->number_of_times_each_philosopher_must_eat);
	return (table);
}
