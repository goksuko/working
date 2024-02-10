/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 20:26:16 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/10 14:23:44 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	find_max(t_stack **a)
{
	t_stack	*current;
	int		nb;

	current = *a;
	nb = current->value;
	while (current != NULL)
	{
		if (current->value > nb)
			nb = current->value;
		current = current->next;
	}
	return (nb);
}

int	find_min(t_stack **a)
{
	t_stack	*current;
	int		nb;

	current = *a;
	nb = current->value;
	while (current != NULL)
	{
		if (current->value < nb)
			nb = current->value;
		current = current->next;
	}
	return (nb);
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
			if (array[i] > array[i+1])
			{
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
			i++;
		}
	}
	return (array);
}

int	find_median(t_stack **a)
{
	long	*array;
	int		nb;
	int		length;
	int		i;

	length = ps_find_length(a);
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
	array = stack_to_array(a, array);
	// for (nb = 0; nb < 10; nb++)
	// 	ft_printf("array[%d] = %d\n", nb, (int)array[nb]);
	array = sort_array(array);
	nb = (int)array[length / 2];
	free(array);
	return (nb);
}


