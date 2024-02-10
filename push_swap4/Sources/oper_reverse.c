/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_reverse.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/10 14:41:26 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// //reverse rotate a: Shift down all elements of stack a by 1.
// //The last element becomes the first one.
// void	ps_rra(t_stack **a)
// {
// 	t_stack	*current;
// 	t_stack	*temp;

// 	current = *a;
// 	if (current == NULL || current->next == NULL)
// 		return ;
// 	else
// 	{
// 		while (current->next->next != NULL)
// 			current = current->next;
// 		temp = current->next;
// 		current->next = NULL;
// 		temp->next = *a;
// 		*a = temp;
// 	}
// 	ft_printf("rra\n");
// }

void	ps_rra_function(t_stack **a);

//reverse rotate a: Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	ps_rra(t_stack **a)
{
	ps_rra_function(a);
	ft_printf("rra\n");
}

void	ps_rra_function(t_stack **a)
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

// //reverse rotate b: Shift down all elements of stack b by 1.
// //The last element becomes the first one.
// void	ps_rrb(t_stack **b)
// {
// 	t_stack	*current;
// 	t_stack	*temp;

// 	current = *b;
// 	if (current == NULL || current->next == NULL)
// 		return ;
// 	else
// 	{
// 		while (current->next->next != NULL)
// 			current = current->next;
// 		temp = current->next;
// 		current->next = NULL;
// 		temp->next = *b;
// 		*b = temp;
// 	}
// 	ft_printf("rrb\n");
// }

void	ps_rrb_function(t_stack **b);

//reverse rotate b: Shift down all elements of stack b by 1.
//The last element becomes the first one.
void	ps_rrb(t_stack **b)
{
	ps_rrb_function(b);
	ft_printf("rrb\n");
}

void	ps_rrb_function(t_stack **b)
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

//reverse rotate a and b
void	ps_rrr(t_stack **a, t_stack **b)
{
	ps_rra_function(a);
	ps_rrb_function(b);
	ft_printf("rrr\n");
}
