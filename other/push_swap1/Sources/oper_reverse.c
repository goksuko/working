/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_reverse.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/02 14:47:55 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//reverse rotate a: Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	ps_rra(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

	current = *a;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		while (current->next->next != NULL)
			current = current->next;
		temp = current->next;
		current->next = NULL;
		temp->next = *a;
		*a = temp;
	}
}

//reverse rotate b: Shift down all elements of stack b by 1.
//The last element becomes the first one.
void	ps_rrb(t_stack **b)
{
	t_stack	*current;
	t_stack	*temp;

	current = *b;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		while (current->next->next != NULL)
			current = current->next;
		temp = current->next;
		current->next = NULL;
		temp->next = *b;
		*b = temp;
	}
}

void	ps_rrr(t_stack **a, t_stack **b)
{
	ps_rra(a);
	ps_rrb(b);
}
