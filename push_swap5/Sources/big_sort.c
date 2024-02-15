/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:50:23 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 19:15:58 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	do_edge_nb(t_stack **a, t_stack **b)
{
	t_stack		*current_b;
	int			clock_wise;
	int			max_b;
	int			length;

	current_b = *b;
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
				ps_rotate(b, "b");
				current_b = *b;
			}
		}
		else
		{
			while (current_b->value != max_b)
			{
				ps_reverse_rotate(b, "b");
				current_b = *b;
			}
		}
		ps_push(a, b, "b");
}

void	do_edge2_nb(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	int			clock_wise;
	int			min_a;
	int			length;

	current_a = *a;
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
			ps_rotate(a, "a");
			current_a = *a;
		}
	}
	else
	{
		while (current_a->value != min_a)
		{
			ps_reverse_rotate(a, "a");
			current_a = *a;
		}
	}
	ps_push(b, a, "a");
}

void	do_first_half(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			clock_wise;
	int			min_b;
	int			max_b;
	int			length;

	current_a = *a;
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
				ps_rotate(b, "b");
				current_b = *b;
			}
			if (current_b->value == max_b)
			{
				while (current_a->value < current_b->value) 
				{
					ps_rotate(b, "b");
					current_b = *b;
				}
			}
		}
		else
		{
			while (current_a->value > current_b->value) 
			{
				ps_reverse_rotate(b, "b");
				current_b = *b;
			}
			ps_rotate(b, "b");
		}
		ps_push(a, b, "b");
	}
	else if (current_a->value > current_b->value && current_a->value > max_b)
	{
		sort_eff_b(b);
		ps_push(a, b, "b");
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
				ps_rotate(b, "b");
				current_b = *b;
			}
		}
		else
		{
			while (current_a->value < current_b->value) 
			{
				ps_reverse_rotate(b, "b");
				current_b = *b;
			}
			if (current_b->value == min_b)
			{
				while (current_a->value > current_b->value) 
				{
					ps_reverse_rotate(b, "b");
					current_b = *b;
				}
				ps_rotate(b, "b");
			}
		}
		ps_push(a, b, "b");
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
				ps_rotate(a, "a");
				current_a = *a;
			}
		}
		else
		{
			while (current_b->value > current_a->value) 
			{
				ps_reverse_rotate(a, "a");
				current_a = *a;
			}
			if (current_a->value == max_a)
			{
				while (current_b->value < current_a->value) 
				{
					ps_reverse_rotate(a, "a");
					current_a = *a;
				}
				ps_rotate(a, "a");
			}

		}
		ps_push(b, a, "a");
	}
	else if (current_b->value > current_a->value && current_b->value > max_a)
	{
		sort_eff_a(a);
		ps_push(b, a, "a");
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
				ps_rotate(a, "a");
				current_a = *a;
			}
			if (current_a->value == min_a)
			{
				while (current_b->value > current_a->value) 
				{
					ps_rotate(a, "a");
					current_a = *a;
				}
			}
		}
		else
		{
			while (current_b->value < current_a->value) 
			{
				ps_reverse_rotate(a, "a");
				current_a = *a;
			}
			ps_rotate(a, "a");
		}
		ps_push(b, a, "a");
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
			ps_push(a, &b, "b");
		else
			ps_rotate(a, "a");
	}

	current_b = b;
	if (current_b->value < current_b->next->value)
		ps_rotate(&b, "b");
	times = length - 2;
	while (times--)
	{
		current_a = *a;
		current_b = b;
		if (current_a->value < median)
			do_first_half(a, &b);
		else
			ps_rotate(a, "a");
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
		ps_push(a, &b, "b");
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
		ps_push(&b, a, "a");
}

void	do_radix_sort(t_stack **a)
{
	t_stack	*b;
	t_stack	*current_a;
	t_stack	*current_b;
	int		length;
	int		rest;
	int		num;
	int		power;
	
	b = NULL;
	power = 0;
	
	while (power < 2)
	{
		rest = 0;
		while (rest < 10)
		{
			length = ps_find_length(a);
			while (length--)
			{
				current_a = *a;
				num = current_a->value % (10 ^ power);
				if (num % 10 == rest)
					ps_push(a, &b, "b");
				else
					ps_rotate(a, "a");
			}
			rest++;
		}
		power++;

		printf("power is %d\n", power);
		printf("===Printing Stack A===\n");
		ps_print_stack(*a);
		printf("===Printing Stack B===\n");
		ps_print_stack(b);

		rest = 9;
		while (rest >= 0)
		{
			length = ps_find_length(&b);
			while (length--)
			{
				current_b = b;
				num = current_b->value % (10 ^ power);
				if (current_b->value / 10 % 10 == rest)
					ps_push(&b, a, "a");
				else
					ps_rotate(&b, "b");
			}
			rest--;
		}
		power++;

		printf("power is %d\n", power);
		printf("===Printing Stack A===\n");
		ps_print_stack(*a);
		printf("===Printing Stack B===\n");
		ps_print_stack(b);

	}
	
	length = ps_find_length(&b);
	while (length--)
	{
		ps_push(&b, a, "a");
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
			ps_rotate(a, "a");
			current_a = *a;
		}
	}
	else
		while (current_a->value != min_a)
		{
			ps_reverse_rotate(a, "a");
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
			ps_rotate(b, "b");
			current_b = *b;
		}
	}
	else
		while (current_b->value != max_b)
		{
			ps_reverse_rotate(b, "b");
			current_b = *b;
		}
}