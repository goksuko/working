/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/17 14:42:07 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/09 16:38:52 by akaya-oz      ########   odam.nl         */
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

int		find_next_min(t_stack **a, int min_a)
{
	int		next_min_a;
	t_stack	*current;

	next_min_a = INT_MAX;
	current = *a;
	while (current)
	{
		if (current->value > min_a && current->value < next_min_a)
			next_min_a = current->value;
		current = current->next;
	}
	return (next_min_a);
}

void	give_index(t_stack **a)
{
	int		min_a;
	t_stack	*current;
	int		index_no;
	int		length;
	
	index_no = 0;
	length = ps_find_length(a);
	min_a = find_min(a);
	current = *a;
	while (index_no < length)
	{
		if (current == NULL)
			current = *a;		
		if (current->value == min_a)
		{
			current->index = index_no;
			min_a = find_next_min(a, min_a);
			index_no++;
		}
		current = current->next;
	}
}