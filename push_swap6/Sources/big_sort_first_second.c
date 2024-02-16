/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort_first_second.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:33:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 23:47:14 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	do_first_first(t_stack **a, t_stack **b, int max_b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			clock_wise;
	int			length;

	current_a = *a;
	current_b = *b;
	length = ps_find_length(b);
	clock_wise = clck_while_nb_small(b, current_a->value);
	current_b = *b;
	if (current_b->value == max_b)
		clock_wise += clck_while_nb_big(b, current_a->value);
	if (length - clock_wise > clock_wise)
	{
		rotate_still_small(b, current_a->value, 'b');
		current_b = *b;
		if (current_b->value == max_b)
			rotate_still_big(b, current_a->value, 'b');
	}
	else
	{
		reverse_rotate_still_small(b, current_a->value, 'b');
		ps_rotate(b, "b");
	}
	ps_push(a, b, "b");
}

void	do_first_second(t_stack **a, t_stack **b, int min_b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			clock_wise;
	int			length;

	current_a = *a;
	clock_wise = clck_while_nb_big(b, current_a->value);
	current_b = *b;
	length = ps_find_length(b);
	if (length - clock_wise > clock_wise)
		rotate_still_big(b, current_a->value, 'b');
	else
	{
		reverse_rotate_still_big(b, current_a->value, 'b');
		current_b = *b;
		if (current_b->value == min_b)
		{
			reverse_rotate_still_small(b, current_a->value, 'b');
			ps_rotate(b, "b");
		}
	}
	ps_push(a, b, "b");
}

void	do_second_first(t_stack **a, t_stack **b, int max_a)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			clock_wise;
	int			length;

	current_a = *a;
	current_b = *b;
	clock_wise = clck_while_nb_small(a, current_b->value);
	length = ps_find_length(a);
	if (length - clock_wise > clock_wise)
		rotate_still_small(a, current_b->value, 'a');
	else
	{
		reverse_rotate_still_small(a, current_b->value, 'a');
		current_a = *a;
		if (current_a->value == max_a)
		{
			reverse_rotate_still_big(a, current_b->value, 'a');
			ps_rotate(a, "a");
		}
	}
	ps_push(b, a, "a");
}

void	do_second_second(t_stack **a, t_stack **b, int min_a)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			clock_wise;
	int			length;

	current_a = *a;
	current_b = *b;
	clock_wise = clck_while_nb_big(a, current_b->value);
	if (current_a->value == min_a)
		clock_wise += clck_while_nb_small(a, current_b->value);
	current_a = *a;
	length = ps_find_length(a);
	if (length - clock_wise > clock_wise)
	{
		rotate_still_big(a, current_b->value, 'a');
		current_a = *a;
		if (current_a->value == min_a)
			rotate_still_small(a, current_b->value, 'a');
	}
	else
	{
		reverse_rotate_still_big(a, current_b->value, 'a');
		ps_rotate(a, "a");
	}
	ps_push(b, a, "a");
}
