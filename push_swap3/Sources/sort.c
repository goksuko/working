/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:50:23 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/07 21:03:34 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ps_sort(t_stack **a)
{
	int		length;

	length = ps_find_length(a);
	if (length <= 1)
		return ;
	else if (length == 2)
		ps_ra(a);
	else if (length == 3)
	{
		printf("===sor basi: Printing Stack A===\n");
		ps_print_stack(*a);
		do_for_three(a);
	}
	// else if (length <= 5)
	// 	do_for_five(a);
	// else
	// 	do_big_sort(a);
	return;			 
}

void	do_for_three(t_stack **a)
{
	int		median;
	int 	min;
	// int		max;
	t_stack	*current;


	median = find_median(a);
	min = find_min(a);
	// max= find_max(a);
	current = *a;
	printf("===do 3: Printing Stack A===\n");
	ps_print_stack(*a);
	if (current->value == min)
	{
		ps_sa(a);
		printf("===SA: Printing Stack A===\n");
		ps_print_stack(*a);
		ps_rra(a);
	}
	else if (current->value == median)
	{
		if (current->next->value == min)
			ps_sa(a);
		else
			ps_rra(a);
	}
	else
	{
		if (current->next->value == min)
			ps_ra(a);
		else
		{
			ps_sa(a);
			ps_rra(a);
		}
	}
	
}
// void	do_for_five(t_stack **a)
// void	do_big_sort(t_stack **a)