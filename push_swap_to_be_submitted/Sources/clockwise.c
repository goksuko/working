/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clockwise.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:31:40 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/17 19:43:26 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	clck_while_nb_edge(t_stack **stack, int edge)
{
	t_stack	*current;
	int		clock_wise;

	clock_wise = 0;
	current = *stack;
	while (current->value != edge && current)
	{
		clock_wise++;
		current = current->next;
	}
	return (clock_wise);
}

int	clck_while_nb_small(t_stack **stack, int big)
{
	t_stack	*current;
	int		clock_wise;

	clock_wise = 0;
	current = *stack;
	while (current->value < big && current)
	{
		clock_wise++;
		current = current->next;
	}
	return (clock_wise);
}

int	clck_while_nb_big(t_stack **stack, int small)
{
	t_stack	*current;
	int		clock_wise;

	clock_wise = 0;
	current = *stack;
	while (current->value > small && current)
	{
		clock_wise++;
		current = current->next;
	}
	return (clock_wise);
}
