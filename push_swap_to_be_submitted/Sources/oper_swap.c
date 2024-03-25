/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 19:01:47 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//Swap the first 2 elements at the top of stack.
//Do nothing if there is only one or no elements.
void	ps_swap(t_stack **stack, char *str)
{
	t_stack	*current;
	t_stack	*t_stack1;
	t_stack	*t_stack2;
	t_stack	*temp1;
	t_stack	*temp2;

	current = *stack;
	if (current == NULL || current->next == NULL)
		return ;
	t_stack1 = current;
	t_stack2 = current->next;
	temp1 = t_stack2->next;
	t_stack1->next = temp1;
	temp2 = t_stack1;
	t_stack2->next = temp2;
	current = t_stack2;
	*stack = current;
	if (*str == 'a')
		write(1, "sa\n", 3);
	else if (*str == 'b')
		write(1, "sb\n", 3);
}
