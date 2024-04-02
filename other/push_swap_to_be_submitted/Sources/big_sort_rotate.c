/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort_rotate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:32:44 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 23:48:34 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	rotate_till(t_stack **stack, int nb, char letter)
{
	t_stack	*current;
	char	str[2];

	current = *stack;
	str[0] = letter;
	str[1] = '\0';
	while (current->value != nb)
	{
		ps_rotate(stack, str);
		current = *stack;
	}
}

void	rotate_still_small(t_stack **stack, int big, char letter)
{
	t_stack	*current;
	char	str[2];

	current = *stack;
	str[0] = letter;
	str[1] = '\0';
	while (current->value < big)
	{
		ps_rotate(stack, str);
		current = *stack;
	}
}

void	rotate_still_big(t_stack **stack, int small, char letter)
{
	t_stack	*current;
	char	str[2];

	current = *stack;
	str[0] = letter;
	str[1] = '\0';
	while (current->value > small)
	{
		ps_rotate(stack, str);
		current = *stack;
	}
}
