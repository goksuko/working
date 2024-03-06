/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 13:53:50 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/07 00:36:31 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	make_pos(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	find_big(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	do_cash_job(t_stack **a, t_stack **b, t_stack *best_b)
{
	bool		second_half_a;
	bool		second_half_b;

	second_half_a = find_index_a(a, &best_b);
	second_half_b = find_index_b(&best_b);
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

void	find_best_and_cash(t_stack **a, t_stack **b)
{
	t_stack		*current_b;
	int			length_a;
	int			length_b;
	t_stack		*best_b;
	bool		second_half_a;
	bool		second_half_b;
	int			price;
	int			old_price;

	old_price = INT_MAX;
	current_b = *b;
	length_a = ps_find_length(a);
	length_b = ps_find_length(b);
	best_b = NULL;
	while (current_b)
	{
		second_half_a = find_index_a(a, &current_b);
		second_half_b = find_index_b(&current_b);
		if ((!second_half_a && !second_half_b) || (second_half_a && second_half_b))
			price = find_big(current_b->index, current_b->index_a);
		else if (!second_half_a && second_half_b)
			price = make_pos((length_b - current_b->index) + current_b->index_a);
		else if (second_half_a && !second_half_b)
			price = make_pos(current_b->index + (length_a - current_b->index_a));
		if (price < old_price)
		{
			old_price = price;
			best_b = current_b;
		}
		current_b = current_b->next;
	}
	do_cash_job(a, b, best_b);
}

void	do_new_sort(t_stack **a, int length)
{
	t_stack		*b;
	int			times;

	b = NULL;
	times = length - 3;
	while (times--)
		ps_push(a, &b, "b");
	if(!ps_check_if_sorted(a))
		do_for_three(a);
	while (b)
	{
		give_position_index(a);
		give_position_index(&b);
		find_index_a(a, &b);
		find_best_and_cash(a, &b);
	}
	sort_eff_a(a);
}
