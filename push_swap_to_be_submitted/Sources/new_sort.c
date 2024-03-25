/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 13:53:50 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/09 16:40:09 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_stack	*find_best_a(t_stack **a, t_stack *best_b)
{
	t_stack	*current_a;
	int		times;

	current_a = *a;
	times = best_b->index_a;
	while (times--)
		current_a = current_a->next;
	return (current_a);
}

void	do_cash_job(t_stack **a, t_stack **b, t_stack *best_a, t_stack *best_b)
{
	bool		second_half_a;
	bool		second_half_b;

	second_half_a = best_a->second_half;
	second_half_b = best_b->second_half;
	if (!second_half_a && !second_half_b)
		rotate_and_finish(a, b, best_b);
	else if (!second_half_a && second_half_b)
		a_first_b_second(a, b, best_b);
	else if (second_half_a && !second_half_b)
		a_second_b_first(a, b, best_b);
	else if (second_half_a && second_half_b)
		reverse_rotate_and_finish(a, b, best_b);
	ps_push(b, a, "a");
}

void	find_total_price(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			times;

	current_b = *b;
	while (current_b)
	{
		current_a = *a;
		times = current_b->index_a;
		while (times--)
			current_a = current_a->next;
		current_b->price += current_a->price;
		current_b = current_b->next;
	}
}

void	find_best_and_cash(t_stack **a, t_stack **b)
{
	t_stack		*current_b;
	t_stack		*best_a;
	t_stack		*best_b;
	int			total_price;
	int			old_price;

	old_price = INT_MAX;
	current_b = *b;
	best_b = NULL;
	while (current_b)
	{
		total_price = current_b->price;
		if (total_price < old_price)
		{
			old_price = total_price;
			best_b = current_b;
		}
		current_b = current_b->next;
	}
	best_a = find_best_a(a, best_b);
	do_cash_job(a, b, best_a, best_b);
}

void	do_new_sort(t_stack **a, int length)
{
	t_stack		*b;
	int			times;

	b = NULL;
	times = length - 3;
	while (times--)
		ps_push(a, &b, "b");
	if (!ps_check_if_sorted(a))
		do_for_three(a);
	while (b)
	{
		give_position_index(a);
		give_price(a);
		give_position_index(&b);
		give_price(&b);
		find_index_a(a, &b);
		find_total_price(a, &b);
		find_best_and_cash(a, &b);
	}
	sort_eff_a(a);
}
