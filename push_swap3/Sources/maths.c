/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 20:26:16 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/07 22:00:44 by akaya-oz      ########   odam.nl         */
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

// int	find_median(t_stack **a)
// {
// 	t_stack	*copy;
// 	t_stack	*current;

// 	current = *a;

// }


int	*stack_to_array(t_stack **a)
{
	int		**array;
	int		i;
	t_stack	*current;

	current = *a;
	i = 0;
	array = malloc(sizeof(int*) * 1024);
	if (array == NULL)
		return (NULL);
	while (current != NULL)
	{
		array[i] = (int *)malloc(sizeof(int *) * 1);
		if (array[i] == NULL)
			return (free_array(*array));
		*array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array[0]);
}

int	*sort_array(int *array)
{
	int	length;
	int	i;
	int	temp;
	int	length2;

	length = sizeof(*array) / sizeof(array[0]);
	length2 = length;
	while (length2--)
	{
		i = 0;
		while (length--)
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
	return (&array[0]);
}

int	find_median(t_stack **a)
{
	int	*array;
	int	nb;
	int	length;

	length = ps_find_length(a);
	array = stack_to_array(a);
	array = sort_array(array);
	nb = array[length / 2];
	free_array(array);
	return (nb);
}