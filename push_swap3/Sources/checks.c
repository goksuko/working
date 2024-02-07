/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 18:36:28 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/07 11:34:01 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ps_check_alpha(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if ((string[i] >= 'a' && string[i] <= 'z' )
			|| (string[i] >= 'A' && string[i] <= 'Z' ))
			return (1);
		i++;
	}
	return (0);
}

int	ps_check_if_sorted(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

	current = *a;
	while (current->next != NULL)
	{
		temp = current->next;
		if (current->value > temp->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ps_check_duplicates(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

	current = *a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->value == temp->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
