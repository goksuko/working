/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_rotate.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/10 14:41:04 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// //rotate a: Shift up all elements of stack a by 1.
// //The first element becomes the last one.
// void	ps_ra(t_stack **a)
// {
// 	t_stack	*current;
// 	t_stack	*temp;

// 	current = *a;
// 	if (current == NULL || current->next == NULL)
// 		return ;
// 	else
// 	{
// 		temp = current;
// 		*a = current->next;
// 		temp->next = NULL;
// 		current = *a;
// 		while (current->next != NULL)
// 			current = current->next;
// 		current->next = temp;
// 	}
// 	ft_printf("ra\n");
// }

void	ps_ra_function(t_stack **a);

//rotate a: Shift up all elements of stack a by 1.
//The first element becomes the last one.
void	ps_ra(t_stack **a)
{
	ps_ra_function(a);
	ft_printf("ra\n");
}

void	ps_ra_function(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

	current = *a;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		temp = current;
		*a = current->next;
		temp->next = NULL;
		current = *a;
		while (current->next != NULL)
			current = current->next;
		current->next = temp;
	}
}

// //rotate b: Shift up all elements of stack b by 1.
// //The first element becomes the last one.
// void	ps_rb(t_stack **b)
// {
// 	t_stack	*current;
// 	t_stack	*temp;

// 	current = *b;
// 	if (current == NULL || current->next == NULL)
// 		return ;
// 	else
// 	{
// 		temp = current;
// 		*b = current->next;
// 		temp->next = NULL;
// 		current = *b;
// 		while (current->next != NULL)
// 			current = current->next;
// 		current->next = temp;
// 	}
// 	ft_printf("rb\n");
// }

void	ps_rb_function(t_stack **b);

//rotate b: Shift up all elements of stack b by 1.
//The first element becomes the last one.
void	ps_rb(t_stack **b)
{
	ps_rb_function(b);
	ft_printf("rb\n");
}

void	ps_rb_function(t_stack **b)
{
	t_stack	*current;
	t_stack	*temp;

	current = *b;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		temp = current;
		*b = current->next;
		temp->next = NULL;
		current = *b;
		while (current->next != NULL)
			current = current->next;
		current->next = temp;
	}
}

void	ps_rr(t_stack **a, t_stack **b)
{
	ps_ra_function(a);
	ps_rb_function(b);
	ft_printf("rr\n");
}
