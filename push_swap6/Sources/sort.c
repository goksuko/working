/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:50:23 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/02 23:37:49 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ps_sort(t_stack **a, int median)
{
	int		length;

	length = ps_find_length(a);
	if (length <= 1)
		return ;
	else if (length == 2)
		ps_rotate(a, "a");
	else if (length == 3)
		do_for_three(a, median);
	else if (length == 4)
		do_for_four(a, length);
	else if (length == 5)
		do_for_five(a, median, length);
	else
		do_big_sort(a, median, length);
		// do_radix_sort(a, length);
	return ;
}

void	do_for_three(t_stack **a, int median)
{
	int		min;
	t_stack	*current;

	min = find_min(a);
	current = *a;
	if (current->value == min)
	{
		ps_swap(a, "a");
		ps_rotate(a, "a");
	}
	else if (current->value == median)
	{
		if (current->next->value == min)
			ps_swap(a, "a");
		else
			ps_reverse_rotate(a, "a");
	}
	else
	{
		if (current->next->value == min)
			ps_rotate(a, "a");
		else
		{
			ps_swap(a, "a");
			ps_reverse_rotate(a, "a");
		}
	}
}

void	do_for_four(t_stack **a, int length)
{
	t_stack	*b;
	t_stack	*current_a;
	int		min_a;
	int		max_a;

	b = NULL;
	min_a = find_min(a);
	max_a = find_max(a);
	current_a = *a;
	while (length--)
	{
		if (current_a->value == min_a || current_a->value == max_a)
			ps_push(a, &b, "b");
		else
			ps_rotate(a, "a");
		current_a = *a;
	}
	if (!ps_check_if_sorted(a))
		ps_swap(a, "a");
	if (b->value == max_a)
	{
		ps_push(&b, a, "a");
		ps_rotate(a, "a");
		ps_push(&b, a, "a");
	}
	else
	{
		ps_push(&b, a, "a");
		ps_push(&b, a, "a");
		ps_rotate(a, "a");
	}
}

void	do_for_five(t_stack **a, int median, int length)
{
	t_stack	*b;
	t_stack	*current_a;
	int		min_a;
	int		max_a;

	b = NULL;
	min_a = find_min(a);
	max_a = find_max(a);
	current_a = *a;
	while (length--)
	{
		if (current_a->value == min_a || current_a->value == max_a)
			ps_push(a, &b, "b");
		else
			ps_rotate(a, "a");
		current_a = *a;
	}
	if (!ps_check_if_sorted(a))
		do_for_three(a, median);
	if (b->value == max_a)
	{
		ps_push(&b, a, "a");
		ps_rotate(a, "a");
		ps_push(&b, a, "a");
	}
	else
	{
		ps_push(&b, a, "a");
		ps_push(&b, a, "a");
		ps_rotate(a, "a");
	}
}
