/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_sort_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 00:16:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/09 16:24:23 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	rotate_and_finish(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		i;

	i = 0;
	while (i < best_b->index && i < best_b->index_a)
	{
		ps_rotate_both(a, b);
		i++;
	}
	while (i < best_b->index_a)
	{
		ps_rotate(a, "a");
		i++;
	}
	while (i < best_b->index)
	{
		ps_rotate(b, "b");
		i++;
	}
}

void	reverse_rotate_and_finish(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		length_a;
	int		length_b;
	int		i;

	i = 0;
	length_a = ps_find_length(a);
	length_b = ps_find_length(b);
	while (i < (length_b - best_b->index) && i < (length_a - best_b->index_a))
	{
		ps_reverse_rotate_both(a, b);
		i++;
	}
	while (i < (length_a - best_b->index_a))
	{
		ps_reverse_rotate(a, "a");
		i++;
	}
	while (i < (length_b - best_b->index))
	{
		ps_reverse_rotate(b, "b");
		i++;
	}
}

void	a_first_b_second(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		length_b;
	int		i;

	i = 0;
	length_b = ps_find_length(b);
	while (i < best_b->index_a)
	{
		ps_rotate(a, "a");
		i++;
	}
	i = 0;
	while (i < (length_b - best_b->index))
	{
		ps_reverse_rotate(b, "b");
		i++;
	}
}

void	a_second_b_first(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		length_a;
	int		max_a;
	int		i;

	i = 0;
	length_a = ps_find_length(a);
	max_a = find_max(a);
	while (i < (length_a - best_b->index_a))
	{
		ps_reverse_rotate(a, "a");
		i++;
	}
	i = 0;
	while (i < best_b->index)
	{
		ps_rotate(b, "b");
		i++;
	}
	if ((*a)->value < (*b)->value && (*b)->value < max_a)
		ps_rotate(a, "a");
}
