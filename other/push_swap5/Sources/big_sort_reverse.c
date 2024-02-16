/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort_reverse.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:32:26 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 23:49:00 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	reverse_rotate_till(t_stack **stack, int nb, char letter)
{
	t_stack	*current;
	char	str[2];

	current = *stack;
	str[0] = letter;
	str[1] = '\0';
	while (current->value != nb)
	{
		ps_reverse_rotate(stack, str);
		current = *stack;
	}
}

void	reverse_rotate_still_small(t_stack **stack, int big, char letter)
{
	t_stack	*current;
	char	str[2];

	current = *stack;
	str[0] = letter;
	str[1] = '\0';
	while (current->value < big)
	{
		ps_reverse_rotate(stack, str);
		current = *stack;
	}
}

void	reverse_rotate_still_big(t_stack **stack, int small, char letter)
{
	t_stack	*current;
	char	str[2];

	current = *stack;
	str[0] = letter;
	str[1] = '\0';
	while (current->value > small)
	{
		ps_reverse_rotate(stack, str);
		current = *stack;
	}
}
