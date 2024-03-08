/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unused_func.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:50:12 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/08 12:17:04 by akaya-oz      ########   odam.nl         */
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

long	*stack_to_array(t_stack **a, long *array)
{
	int		i;
	t_stack	*current;

	current = *a;
	i = 0;
	while (current != NULL)
	{
		array[i] = (long)current->value;
		current = current->next;
		i++;
	}
	return (array);
}

long	*sort_array(long *array)
{
	int		length;
	int		i;
	long	temp;
	int		length2;

	length = 0;
	while (array[length] != LONG_MAX)
		length++;
	length2 = length;
	while (length2--)
	{
		i = 0;
		while (i < length)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			i++;
		}
	}
	return (array);
}

long	*fill_array(int length, t_stack **a)
{
	long	*array;
	int		i;

	array = malloc((length + 1) * sizeof(long));
	if (array == NULL)
	{
		if (*a != NULL)
			*a = ps_free_list(*a);
		return (0);
	}
	i = 0;
	while (i < length + 1)
	{
		array[i] = LONG_MAX;
		i++;
	}
	return (array);
}

int	find_median(t_stack **a)
{
	long	*array;
	int		nb;
	int		length;

	length = ps_find_length(a);
	array = fill_array(length, a);
	array = stack_to_array(a, array);
	array = sort_array(array);
	nb = (int)array[length / 2];
	free(array);
	return (nb);
}
