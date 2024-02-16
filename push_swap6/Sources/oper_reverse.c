/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_reverse.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 19:00:44 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//reverse rotate: Shift down all elements of stack by 1.
//The last element becomes the first one.
void	ps_reverse_rotate(t_stack **stack, char *str)
{
	t_stack	*current;
	t_stack	*temp;

	current = *stack;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		while (current->next->next != NULL)
			current = current->next;
		temp = current->next;
		current->next = NULL;
		temp->next = *stack;
		*stack = temp;
	}
	if (*str == 'a')
		write(1, "rra\n", 4);
	else if (*str == 'b')
		write(1, "rrb\n", 4);
}
