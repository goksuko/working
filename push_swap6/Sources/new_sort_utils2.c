/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_sort_utils2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/07 00:16:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/12 00:56:47 by akaya-oz      ########   odam.nl         */
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

void	sort_eff_a(t_stack **a)
{
	int clock_wise;
	int min_a;
	int length;

	min_a = find_min(a);
	length = ps_find_length(a);
	clock_wise = clck_while_nb_edge(a, min_a);
	if (length - clock_wise > clock_wise)
		rotate_till(a, min_a, 'a');
	else
		reverse_rotate_till(a, min_a, 'a');
}