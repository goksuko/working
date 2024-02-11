/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/10 14:40:02 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

//If you intend to modify the original pointer passed to the function, 
//you should use the first code where the function takes a pointer to a pointer.

// //Swap the first 2 elements at the top of stack a.
// //Do nothing if there is only one or no elements.
// void	ps_sa(t_stack **a)
// {
// 	t_stack	*current;
// 	t_stack	*t_stack1;
// 	t_stack	*t_stack2;
// 	t_stack	*temp1;
// 	t_stack	*temp2;

// 	current = *a;
// 	if (current == NULL || current->next == NULL)
// 		return ;
// 	t_stack1 = current;
// 	t_stack2 = current->next;
// 	temp1 = t_stack2->next;
// 	t_stack1->next = temp1;
// 	temp2 = t_stack1;
// 	t_stack2->next = temp2;
// 	current = t_stack2;
// 	*a = current;
// 	ft_printf("sa\n");
// }

void	ps_sa_function(t_stack **a);

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void	ps_sa(t_stack **a)
{
	ps_sa_function(a);
	ft_printf("sa\n");
}

void	ps_sa_function(t_stack **a)
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
}

// //Swap the first 2 elements at the top of stack b.
// //Do nothing if there is only one or no elements.
// void	ps_sb(t_stack **b)
// {
// 	t_stack	*current;
// 	t_stack	*t_stack1;
// 	t_stack	*t_stack2;
// 	t_stack	*temp1;
// 	t_stack	*temp2;

// 	current = *b;
// 	if (current == NULL || current->next == NULL)
// 		return ;
// 	t_stack1 = current;
// 	t_stack2 = current->next;
// 	temp1 = t_stack2->next;
// 	t_stack1->next = temp1;
// 	temp2 = t_stack1;
// 	t_stack2->next = temp2;
// 	current = t_stack2;
// 	*b = current;
// 	ft_printf("sb\n");
// }

void	ps_sb_function(t_stack **b);

//Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void	ps_sb(t_stack **b)
{
	ps_sb_function(b);
	ft_printf("sb\n");
}

void	ps_sb_function(t_stack **b)
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
}

void	ps_ss(t_stack **a, t_stack **b)
{
	ps_sa_function(a);
	ps_sb_function(b);
	ft_printf("ss\n");
}
