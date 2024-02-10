/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_push.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/10 14:38:36 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//push a: Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void	ps_pa(t_stack **a, t_stack **b)
{
	t_stack		*to_return;
	t_stack		*current;
	t_stack		*temp;

	current = *b;
	if (current == NULL)
		return ;
	else
	{
		to_return = current->next;
		temp = *b;
		*b = to_return;
	}
	if (*a == NULL)
	{
		*a = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *a;
		*a = temp;
	}
	ft_printf("pa\n");

}

//push b: Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
void	ps_pb(t_stack **a, t_stack **b)
{
	t_stack		*to_return;
	t_stack		*current;
	t_stack		*temp;

	current = *a;
	if (current == NULL)
		return ;
	else
	{
		to_return = current->next;
		temp = *a;
		*a = to_return;
	}
	if (*b == NULL)
	{
		*b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *b;
		*b = temp;
	}
	ft_printf("pb\n");
}

