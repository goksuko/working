/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 13:53:50 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/06 22:55:07 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	give_position_index(t_stack **a)
{
	t_stack	*current;
	int		index_no;
	
	index_no = 0;
	current = *a;
	while (current)
	{
		current->index = index_no;
		index_no++;
		current = current->next;
	}
}

bool	find_index_a(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			length_a;
	int			max_a;
	int			min_a;
	bool		second_half_a;

	max_a = find_max(a);
	min_a = find_min(a);
	length_a = ps_find_length(a);
	current_a = *a;
	current_b = *b;
	second_half_a = 0;
	if (current_b->value > max_a || current_b->value < min_a)
	{
		while (current_a->value != max_a && current_a->next)
			current_a = current_a->next;
		current_b->index_a = current_a->index + 1;
		if (current_b->index_a == length_a)
			current_b->index_a = 0;
	}
	else
	{
		while (current_b->value < current_a->value && current_a->next)
			current_a = current_a->next;
		while (current_b->value > current_a->value && current_a->next)
			current_a = current_a->next;
		current_b->index_a = current_a->index;
	}
	if (2 * current_b->index_a > length_a)
		second_half_a = 1;
	return (second_half_a);
}

bool	find_index_b(t_stack **b)
{
	t_stack		*current_b;
	int			length_b;
	bool		second_half_b;

	second_half_b = 0;
	length_b = ps_find_length(b);
	current_b = *b;
	if (2 * current_b->index > length_b)
		second_half_b = 1;
	return (second_half_b);
}

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

void	rotate_and_finish(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		i;

	i = 0;
	// printf("rotate_and_finish\n");
	while (i < best_b->index && i < best_b->index_a)
	{
		// ps_rotate_both(a, b);
		ps_rotate(a, "a");
		ps_rotate(b, "b");
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
	// printf("reverse_rotate_and_finish\n");
	// while (i < best_b->index && i < best_b->index_a)
	while (i < (length_b - best_b->index) && i < (length_a - best_b->index_a))
	{
		ps_reverse_rotate_both(a, b);
		i++;
	}
	while (i < (length_a - best_b->index_a))
	{
		ps_reverse_rotate(b, "b");
		i++;
	}
	while (i < (length_b - best_b->index))
	{
		ps_reverse_rotate(a, "a");
		i++;
	}
}

void	a_first_b_second(t_stack **a, t_stack **b, t_stack *best_b)
{
	int		length_b;
	int		i;

	i = 0;
	length_b = ps_find_length(b);
	// printf("a_first_b_second\n");
	while (i < best_b->index_a)
	{
		ps_rotate(a, "a");
		i++;
	}
	i = 0;
	while (i < (length_b - best_b->index))
	// while (i < best_b->index)
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
	// printf("a_second_b_first\n");

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

void	do_cash_job(t_stack **a, t_stack **b, t_stack *best_b, bool second_half_a, bool second_half_b)
{
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

void	find_best_b(t_stack **a, t_stack **b)
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
	second_half_a = find_index_a(a, &best_b);
	second_half_b = find_index_b(&best_b);
	// printf("best_b->value = %d\n", best_b->value);
	// printf("best_b->index_a = %d\n", best_b->index_a);
	// printf("second_half_a: %d\n", second_half_a);
	// printf("second_half_b: %d\n", second_half_b);
	do_cash_job(a, b, best_b, second_half_a, second_half_b);
}

// void	do_cash_calculation(t_stack **a, t_stack **b)
// {
// 	t_stack		*current_a;
// 	t_stack		*current_b;
// 	t_stack		*best_b;
// 	int			from_begin;
// 	int			from_end;

// 	current_a = *a;
// 	current_b = *b;

// }


void	do_new_sort(t_stack **a, int length)
{
	t_stack		*b;
	int			times;

	b = NULL;
	times = length - 3;
	while (times--)
		ps_push(a, &b, "b");

	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);
	
	if(!ps_check_if_sorted(a))
		do_for_three(a);

	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);

	while (b)
	{
		give_position_index(a);
		give_position_index(&b);
		find_index_a(a, &b);
		find_best_b(a, &b);

		// do_cash_calculation(a, &b);
	}
	sort_eff_a(a);
}
