/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_index.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 23:48:19 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/07 00:07:33 by akaya-oz      ########   odam.nl         */
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

int	find_index_a_helper(t_stack **a, t_stack **b, int max_a, int min_a)
{
	int			temp;
	t_stack		*current_a;
	int			length_a;

	current_a = *a;
	length_a = ps_find_length(a);
	if ((*b)->value > max_a || (*b)->value < min_a)
	{
		while (current_a->value != max_a && current_a->next)
			current_a = current_a->next;
		temp = current_a->index + 1;
		if (temp == length_a)
			temp = 0;
	}
	else
	{
		while ((*b)->value < current_a->value && current_a->next)
			current_a = current_a->next;
		while ((*b)->value > current_a->value && current_a->next)
			current_a = current_a->next;
		temp = current_a->index;
	}
	return (temp);
}

bool	find_index_a(t_stack **a, t_stack **b)
{
	t_stack		*current_b;
	int			max_a;
	int			min_a;
	bool		second_half_a;
	int			length_a;

	length_a = ps_find_length(a);
	max_a = find_max(a);
	min_a = find_min(a);
	current_b = *b;
	second_half_a = 0;
	current_b->index_a = find_index_a_helper(a, b, max_a, min_a);
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
