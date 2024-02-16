/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unused_func.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:50:12 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 23:51:05 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ps_make_bubble_sort(t_stack **a)
{
	int		start;
	t_stack	*current;
	int		length;

	current = *a;
	length = ps_find_length(a);
	while (length--)
	{
		if (current->value > current->next->value)
			ps_swap(a, "a");
		current = *a;
		start = current->value;
		ps_rotate(a, "a");
		current = *a;
		while (current->value != start)
		{
			if (current->value > current->next->value
				&& current->next->value != start)
				ps_swap(a, "a");
			ps_rotate(a, "a");
			current = *a;
		}
	}
}

void	do_for_three_in_b(t_stack **b, int median)
{
	int		max;
	t_stack	*current;

	max = find_max(b);
	current = *b;
	if (current->value == max)
	{
		ps_reverse_rotate(b, "b");
		ps_swap(b, "b");
	}
	else if (current->value == median)
	{
		if (current->next->value == max)
			ps_swap(b, "b");
		else
			ps_reverse_rotate(b, "b");
	}
	else
	{
		if (current->next->value == max)
			ps_rotate(b, "b");
		else
		{
			ps_swap(b, "b");
			ps_reverse_rotate(b, "b");
		}
	}
}