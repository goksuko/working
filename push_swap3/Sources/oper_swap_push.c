/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_swap_push.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/08 12:31:17 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//If you intend to modify the original pointer passed to the function, 
//you should use the first code where the function takes a pointer to a pointer.

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	ps_sa(t_stack **a)
{
	t_stack	*current;
	t_stack	*t_stack1;
	t_stack	*t_stack2;
	t_stack	*temp1;
	t_stack	*temp2;

	current = *a;
	if (current == NULL || current->next == NULL)
		return ;
	t_stack1 = current;
	t_stack2 = current->next;
	temp1 = t_stack2->next;
	t_stack1->next = temp1;
	temp2 = t_stack1;
	t_stack2->next = temp2;
	current = t_stack2;
	*a = current;
	ft_printf("sa\n");
}

//Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void	ps_sb(t_stack **b)
{
	t_stack	*current;
	t_stack	*t_stack1;
	t_stack	*t_stack2;
	t_stack	*temp1;
	t_stack	*temp2;

	current = *b;
	if (current == NULL || current->next == NULL)
		return ;
	t_stack1 = current;
	t_stack2 = current->next;
	temp1 = t_stack2->next;
	t_stack1->next = temp1;
	temp2 = t_stack1;
	t_stack2->next = temp2;
	current = t_stack2;
	*b = current;
	ft_printf("sb\n");
}

void	ps_ss(t_stack **a, t_stack **b)
{
	ps_sa(a);
	ps_sb(b);
	ft_printf("ss\n");
}

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
