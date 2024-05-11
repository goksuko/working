/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   maths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 20:26:16 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/12 00:44:18 by akaya-oz      ########   odam.nl         */
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
