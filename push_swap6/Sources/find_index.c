/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_index.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/06 23:48:19 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/09 16:15:42 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	give_position_index(t_stack **stack)
{
	t_stack	*current;
	int		index_no;

	index_no = 0;
	current = *stack;
	while (current)
	{
		current->index = index_no;
		index_no++;
		current = current->next;
	}
}

void	give_price(t_stack **stack)
{
	t_stack	*current;
	int		length;

	current = *stack;
	length = ps_find_length(stack);
	current = *stack;
	while (current)
	{
		if(2 * current->index < length)
		{
			current->price = current->index;
			current->second_half = 0;
		}
		else
		{
			current->price = length - current->index;
			current->second_half = 1;
		}
		current = current->next;
	}
}

int	find_index_a_helper(t_stack **a, t_stack *current_b, int max_a, int min_a)
{
	int			temp;
	t_stack		*current_a;
	int			length_a;

	current_a = *a;
	length_a = ps_find_length(a);
	if (current_b->value > max_a || current_b->value < min_a)
	{
		while (current_a->value != max_a && current_a->next)
			current_a = current_a->next;
		temp = current_a->index + 1;
	}
	else
	{
		while (current_b->value < current_a->value && current_a->next)
			current_a = current_a->next;
		while (current_b->value > current_a->value && current_a->next)
			current_a = current_a->next;
		temp = current_a->index;
		if (current_b->value > current_a->value)
			temp = 0;
	}
	if (temp == length_a)
		temp = 0;
	return (temp);
}

void	find_index_a(t_stack **a, t_stack **b)
{
	t_stack		*current_b;
	int			max_a;
	int			min_a;

	max_a = find_max(a);
	min_a = find_min(a);
	current_b = *b;
	while (current_b)
	{
		current_b->index_a = find_index_a_helper(a, current_b, max_a, min_a);
		current_b = current_b->next;
	}
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
