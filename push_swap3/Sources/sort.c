/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:50:23 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/09 23:43:38 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ps_sort(t_stack **a, int median)
{
	int		length;

	length = ps_find_length(a);
	if (length <= 1)
		return ;
	else if (length == 2)
		ps_ra(a);
	else if (length == 3)
		do_for_three(a, median);
	// else if (length <= 5)
	// 	do_for_five(a);
	// else
	// 	do_big_sort(a);
	return;			 
}

// ===Printing Stack A===
// Stack 0: 3
// Stack 1: 2
// Stack 2: 1
void	do_for_three(t_stack **a, int median)
{
	// int 	min;
	int		max;
	t_stack	*current;


	// min = find_min(a);
	max = find_max(a);
	current = *a;
	if (current->value == max)
	{
		ps_rra(a);
		ps_sa(a);
	}
	else if (current->value == median)
	{
		if (current->next->value == max)
			ps_sa(a);
		else
			ps_rra(a);
	}
	else
	{
		if (current->next->value == max)
			ps_ra(a);
		else
		{
			ps_sa(a);
			ps_rra(a);
		}
	}
	
}

// // ===Printing Stack A===
// // Stack 0: 1
// // Stack 1: 2
// // Stack 2: 3
// void	do_for_three(t_stack **a, int median)
// {
// 	int 	min;
// 	t_stack	*current;


// 	min = find_min(a);
// 	current = *a;
// 	if (current->value == min)
// 	{
// 		ps_sa(a);
// 		ps_ra(a);
// 	}
// 	else if (current->value == median)
// 	{
// 		if (current->next->value == min)
// 			ps_sa(a);
// 		else
// 			ps_rra(a);
// 	}
// 	else
// 	{
// 		if (current->next->value == min)
// 			ps_ra(a);
// 		else
// 		{
// 			ps_sa(a);
// 			ps_rra(a);
// 		}
// 	}
	
// }

// void	do_for_five(t_stack **a)
// void	do_big_sort(t_stack **a)