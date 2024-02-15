/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:50:23 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 11:10:42 by akaya-oz      ########   odam.nl         */
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
	else
		do_big_sort(a, median, length);
		// do_radix_sort(a);
	return;			 
}

// // ===Printing Stack A===
// // Stack 0: 3
// // Stack 1: 2
// // Stack 2: 1
// void	do_for_three(t_stack **a, int median)
// {
// 	// int 	min;
// 	int		max;
// 	t_stack	*current;


// 	// min = find_min(a);
// 	max = find_max(a);
// 	current = *a;
// 	if (current->value == max)
// 	{
// 		ps_rra(a);
// 		ps_sa(a);
// 	}
// 	else if (current->value == median)
// 	{
// 		if (current->next->value == max)
// 			ps_sa(a);
// 		else
// 			ps_rra(a);
// 	}
// 	else
// 	{
// 		if (current->next->value == max)
// 			ps_ra(a);
// 		else
// 		{
// 			ps_sa(a);
// 			ps_rra(a);
// 		}
// 	}
// }

// ===Printing Stack A===
// Stack 0: 1
// Stack 1: 2
// Stack 2: 3
void	do_for_three(t_stack **a, int median)
{
	int 	min;
	t_stack	*current;


	min = find_min(a);
	current = *a;
	if (current->value == min)
	{
		ps_sa(a);
		ps_ra(a);
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

void	do_for_three_in_b(t_stack **b, int median)
{
	int 	max;
	t_stack	*current;


	max = find_max(b);
	current = *b;
	if (current->value == max)
	{
		ps_rrb(b);
		ps_sb(b);
	}
	else if (current->value == median)
	{
		if (current->next->value == max)
			ps_sb(b);
		else
			ps_rrb(b);
	}
	else
	{
		if (current->next->value == max)
			ps_rb(b);
		else
		{
			ps_sb(b);
			ps_rrb(b);
		}
	}
}

// void	do_first_half(t_stack **a, t_stack **b)
// {
// 	t_stack		*current_a;
// 	t_stack		*current_b;
// 	int			clock_wise;
// 	// int			counter_cw;
// 	int			min_b;
// 	int			max_b;
// 	int			length;

// 	current_a = *a;
// 	current_b = *b;
// 	min_b = find_min(b);
// 	max_b = find_max(b);
// 	clock_wise = 0;
// 	// counter_cw = 0;
// 	if (current_a->value > current_b->value && current_a->value < max_b)
// 	{
// 		while (current_a->value > current_b->value) 
// 		{
// 			clock_wise++;
// 			current_b = current_b->next;
// 		}
// 		current_b = *b;
// 		length = ps_find_length(b);
// 		if (length > 2 * clock_wise)
// 		{
// 			while (current_a->value > current_b->value) 
// 			{
// 				ps_rrb(b);
// 				current_b = *b;
// 			}
// 			ps_rb(b);
// 			ps_pb(a, b);
// 		}
// 		else
// 		{
// 			while (current_a->value > current_b->value) 
// 			{
// 				ps_rb(b);
// 				current_b = *b;
// 			}
// 			ps_rrb(b);
// 			ps_pb(a, b);
// 		}
// 	}
// 	else if (current_a->value > current_b->value && current_a->value > max_b)
// 	{
// 		while (current_b->value != max_b)
// 		{
// 			ps_rb(b);
// 			current_b = *b;
// 		}
// 		ps_pb(a, b);
// 	}
// 	else if (current_a->value < current_b->value && current_a->value < min_b)
// 	{
// 		while (current_b->value != max_b)
// 		{
// 			ps_rb(b);
// 			current_b = *b;
// 		}
// 		ps_pb(a, b);
// 		ps_rb(b);
// 	}
// 	else if (current_a->value < current_b->value && current_a->value > min_b)
// 	{
// 		while (current_a->value < current_b->value)
// 		{
// 			ps_rb(b);
// 			current_b = *b;
// 		}
// 		ps_pb(a, b);
// 	}
// }

void	do_edge_nb(t_stack **a, t_stack **b)
{
	// t_stack		*current_a;
	t_stack		*current_b;
	int			clock_wise;
	// int			min_b;
	int			max_b;
	int			length;

	// current_a = *a;
	current_b = *b;
	// min_b = find_min(b);
	max_b = find_max(b);
		
		clock_wise = 0;
		while (current_b->value != max_b) 
		{
			clock_wise++;
			current_b = current_b->next;
		}
		current_b = *b;
		length = ps_find_length(b);
		if (length > 2 * clock_wise)
		{
			while (current_b->value != max_b)
			{
				ps_rb(b);
				current_b = *b;
			}
		}
		else
		{
			while (current_b->value != max_b)
			{
				ps_rrb(b);
				current_b = *b;
			}
		}
		ps_pb(a, b);
}

void	do_edge2_nb(t_stack **a, t_stack **b)
{
	// t_stack		*current_a;
	t_stack		*current_a;
	int			clock_wise;
	// int			min_b;
	int			min_a;
	int			length;

	// current_a = *a;
	current_a = *a;
	// min_b = find_min(b);
	min_a = find_min(a);
	clock_wise = 0;
	while (current_a->value != min_a) 
	{
		clock_wise++;
		current_a = current_a->next;
	}
	current_a = *a;
	length = ps_find_length(a);
	if (length - clock_wise > clock_wise)
	{
		while (current_a->value != min_a)
		{
			ps_ra(a);
			current_a = *a;
		}
	}
	else
	{
		while (current_a->value != min_a)
		{
			ps_rra(a);
			current_a = *a;
		}
	}
	ps_pa(a, b);
}

void	do_first_half(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			clock_wise;
	int			min_b;
	int			max_b;
	int			length;

	// ps_pb(a, b);
	// ps_pb(a, b);
	current_a = *a;
	// current_b = *b;
	// if (current_b->value < current_b->next->value)
	// 	ps_rb(b);
	min_b = find_min(b);
	max_b = find_max(b);
	current_b = *b;	
	if (current_a->value > current_b->value && current_a->value < max_b)
	{
		clock_wise = 0;
		while (current_a->value > current_b->value) 
		{
			clock_wise++;
			current_b = current_b->next;
		}
		if (current_b->value == max_b)
		{
			while (current_a->value < current_b->value && current_b->next != NULL)
			{
				clock_wise++;
				current_b = current_b->next;
			}
		}
		current_b = *b;
		length = ps_find_length(b);
		if (length - clock_wise > clock_wise)
		{
			while (current_a->value > current_b->value) 
			{
				ps_rb(b);
				current_b = *b;
			}
			if (current_b->value == max_b)
			{
				while (current_a->value < current_b->value) 
				{
					ps_rb(b);
					current_b = *b;
				}
			}
		}
		else
		{
			while (current_a->value > current_b->value) 
			{
				ps_rrb(b);
				current_b = *b;
			}
			ps_rb(b);
		}
		ps_pb(a, b);
	}
	else if (current_a->value > current_b->value && current_a->value > max_b)
	{
		do_edge_nb(a, b);
		// sort_eff_b(b);
		// ps_pb(a, b);
	}
	else if (current_a->value < current_b->value && current_a->value < min_b)
	{
		do_edge_nb(a, b);
	}
	else if (current_a->value < current_b->value && current_a->value > min_b)
	{
		clock_wise = 0;
		while (current_a->value < current_b->value) 
		{
			clock_wise++;
			current_b = current_b->next;
		}
		current_b = *b;
		length = ps_find_length(b);
		if (length - clock_wise > clock_wise)
		{
			while (current_a->value < current_b->value) 
			{
				ps_rb(b);
				current_b = *b;
			}
		}
		else
		{
			while (current_a->value < current_b->value) 
			{
				ps_rrb(b);
				current_b = *b;
			}
			if (current_b->value == min_b)
			{
				while (current_a->value > current_b->value) 
				{
					ps_rrb(b);
					current_b = *b;
				}
				ps_rb(b);
			}
		}
		ps_pb(a, b);
	}
}

void	do_second_half(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			clock_wise;
	int			min_a;
	int			max_a;
	int			length;

	current_a = *a;
	current_b = *b;
	min_a = find_min(a);
	max_a = find_max(a);
	if (current_b->value > current_a->value && current_b->value < max_a)
	{
		clock_wise = 0;
		while (current_b->value > current_a->value) 
		{
			clock_wise++;
			current_a = current_a->next;
		}
		current_a = *a;
		length = ps_find_length(a);
		if (length - clock_wise > clock_wise)
		{
			while (current_b->value > current_a->value) 
			{
				ps_ra(a);
				current_a = *a;
			}
		}
		else
		{
			while (current_b->value > current_a->value) 
			{
				ps_rra(a);
				current_a = *a;
			}
			if (current_a->value == max_a)
			{
				while (current_b->value < current_a->value) 
				{
					ps_rra(a);
					current_a = *a;
				}
				ps_ra(a);
			}

		}
		ps_pa(a, b);
	}
	else if (current_b->value > current_a->value && current_b->value > max_a)
	{
		sort_eff_a(a);
		ps_pa(a, b);
	}
	else if (current_b->value < current_a->value && current_b->value < min_a)
	{
		do_edge2_nb(a, b);
	}
	else if (current_b->value < current_a->value && current_b->value > min_a)
	{
		clock_wise = 0;
		while (current_b->value < current_a->value) 
		{
			clock_wise++;
			current_a = current_a->next;
		}
		if (current_a->value == min_a)
		{
			while (current_b->value > current_a->value && current_a->next != NULL)
			{
				clock_wise++;
				current_a = current_a->next;
			}
		}
		current_a = *a;
		length = ps_find_length(a);
		if (length - clock_wise > clock_wise)
		{
			while (current_b->value < current_a->value) 
			{
				ps_ra(a);
				current_a = *a;
			}
			if (current_a->value == min_a)
			{
				while (current_b->value > current_a->value) 
				{
					ps_ra(a);
					current_a = *a;
				}
			}
		}
		else
		{
			while (current_b->value < current_a->value) 
			{
				ps_rra(a);
				current_a = *a;
			}
			ps_ra(a);
		}
		ps_pa(a, b);
	}
}

void	do_big_sort(t_stack **a, int median, int length)
{
	t_stack		*current_a;
	t_stack		*current_b;
	t_stack		*b;
	int			times;

	// printf("median: %d\n\n", median);
	
	b = NULL;
	while (ps_find_length(&b) < 2)
	{
		current_a = *a;
		if (current_a->value < median)
			ps_pb(a, &b);
		else
			ps_ra(a);
	}

	current_b = b;
	if (current_b->value < current_b->next->value)
		ps_rb(&b);
	times = length - 2;
	while (times--)
	{
		current_a = *a;
		current_b = b;
		if (current_a->value < median)
			do_first_half(a, &b);
		else
			ps_ra(a);
	}

	// printf("first half finished\n");
	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);
	// sort_eff_b(&b);
	// printf("b is sorted\n");
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);

	sort_eff_b(&b);

	length = ps_find_length(a);
	times = length - 3;
	while (times--)
	{
		ps_pb(a, &b);
	}

	// printf("sent to B except last 3\n");

	median = find_median(a);
	if (!ps_check_if_sorted(a))
		do_for_three(a, median);

	// printf("3 sorted\n");
	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);

	times = length - 3;
	while (times--)
	{
		current_b = b;
		do_second_half(a, &b);
	}

	sort_eff_a(a);

	// printf("A should be in order\n");
	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);

	sort_eff_b(&b);

	// printf("B should be in order\n");
	// printf("time to push back\n");
	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);

	while (b != NULL)
		ps_pa(a, &b);
}

// // void	do_for_five(t_stack **a)
// void	do_big_sort(t_stack **a, int median)
// {
// 	t_stack		*current_a;
// 	t_stack		*b;
// 	int			start;
// 	int			new_median;
// 	int			max_b;

// 	b = NULL;
// 	ps_pb(a,&b);
// 	ps_pb(a,&b);
// 	ps_pb(a,&b);
// 	new_median = find_median(&b);
// 	printf("===Printing Stack B BEFORE SORT===\n");
// 	ps_print_stack(b);
// 	if (!ps_check_if_sorted(&b))
// 		do_for_three_in_b(&b, median);
// 	printf("===Printing Stack B AFTER SORT===\n");
// 	ps_print_stack(b);
// 	current_a = *a;
// 	start = current_a->value;
// 	ps_ra(a);
// 	current_a = *a;
// 	printf("start is known (%d). stack 0 of a: %d\n", start, current_a->value);
// 	while (current_a->value != start)
// 	{
// 		// current_a = *a;
// 		if (current_a->value < median)
// 			do_first_half(a, &b);
// 		else
// 			ps_ra(a);
// 		current_a = *a;
// 	}
// 	printf("first half finished. stack 0 of a: %d\n", current_a->value);
// 	current_a = *a;
// 	max_b = find_max(&b);
// 	while (current_a->next->next->next != NULL)
// 	{
// 		do_second_half(a, &b, max_b);
// 		current_a = *a;
// 	}
// 	printf("last 3 in stack A. stack 0 of a: %d\n", current_a->value);
// 	new_median = find_median(a);
// 	if (!ps_check_if_sorted(a))
// 		do_for_three(a, new_median);
// 	printf("time to push back\n");
// 	while (b != NULL)
// 		ps_pa(a, &b);
// }

void	do_radix_sort(t_stack **a)
{
	t_stack	*b;
	t_stack	*current_a;
	t_stack	*current_b;
	int		length;
	// int		length2;
	int		rest;
	
	current_a = *a;
	b = NULL;
	rest = 0;
	while (rest < 10)
	{
		length = ps_find_length(a);
		while (length-- && current_a != NULL)
		{
			if (current_a->value % 10 == rest)
				ps_pb(a, &b);
			else
				ps_ra(a);
			current_a = *a;
		}
		rest++;
	}
	rest = 10;
	while (rest < 91)
	{
		length = ps_find_length(&b);
		while (length--)
		{
			current_b = b;
			if (current_b->value % 100 == rest)
				ps_pa(a, &b);
			else
				ps_rb(&b);
		}
		rest += 10;
	}
	rest = 100;
	while (length-- && rest < 901)
	{
		length = ps_find_length(a);
		while (length--)
		{
			current_a = *a;
			if (current_a->value % 1000 == rest)
				ps_pb(a, &b);
			else
				ps_ra(a);
		}
		rest += 100;
	}
	length = ps_find_length(&b);
	while (length--)
	{
		ps_pa(a, &b);
	}
}


void	sort_eff_a(t_stack **a)
{
	t_stack	*current_a;
	int		clock_wise;
	int		min_a;
	int		length;

	clock_wise = 0;
	current_a = *a;
	min_a = find_min(a);
	length = ps_find_length(a);
	while (current_a->value != min_a)
	{
		clock_wise++;
		current_a = current_a->next;
	}
	current_a = *a;
	if (length - clock_wise > clock_wise)
	{
		while (current_a->value != min_a)
		{
			ps_ra(a);
			current_a = *a;
		}
	}
	else
		while (current_a->value != min_a)
		{
			ps_rra(a);
			current_a = *a;
		}
}

void	sort_eff_b(t_stack **b)
{
	t_stack	*current_b;
	int		clock_wise;
	int		max_b;
	int		length;

	clock_wise = 0;
	current_b = *b;
	max_b = find_max(b);
	length = ps_find_length(b);
	while (current_b->value != max_b)
	{
		clock_wise++;
		current_b = current_b->next;
	}
	current_b = *b;
	if (length - clock_wise > clock_wise)
	{
		while (current_b->value != max_b)
		{
			ps_rb(b);
			current_b = *b;
		}
	}
	else
		while (current_b->value != max_b)
		{
			ps_rrb(b);
			current_b = *b;
		}
}