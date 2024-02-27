/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:50:23 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/27 23:50:34 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// void	do_edge_nb(t_stack **a, t_stack **b)
// {
// 	int			clock_wise;
// 	int			max_b;
// 	int			length;

// 	max_b = find_max(b);
// 	clock_wise = clck_while_nb_edge(b, max_b);
// 	length = ps_find_length(b);
// 	if (length - clock_wise > clock_wise)
// 		rotate_till(b, max_b, 'b');
// 	else
// 		reverse_rotate_till(b, max_b, 'b');
// 	ps_push(a, b, "b");
// }

// void	do_edge2_nb(t_stack **a, t_stack **b)
// {
// 	int			clock_wise;
// 	int			min_a;
// 	int			length;

// 	min_a = find_min(a);
// 	clock_wise = clck_while_nb_edge(a, min_a);
// 	length = ps_find_length(a);
// 	if (length - clock_wise > clock_wise)
// 		rotate_till(a, min_a, 'a');
// 	else
// 		reverse_rotate_till(a, min_a, 'a');
// 	ps_push(b, a, "a");
// }

void	find_cost_effective(t_stack **a, t_stack **b, int median_index)
{
	int		clock_wise;
	// int		counter_wise_a;
	// int		clock_wise_b;
	// int		counter_wise_b;
	long	*array;
	long	*array_i;
	int		length;
	int		i;
	int		temp;
	int		nb;
	int		max_b;
	int		min_b;
	t_stack *current_a;
	t_stack	*current_b;

	current_a = *a;
	current_b = *b;
	// printf("T1\n");
	length = ps_find_length(a);
	array = fill_array(length, a);
	// printf("T2\n");
	array_i = fill_array(length, a);
	i = 0;
	printf("T3\n");
	max_b = find_max(b);
	min_b = find_min(b);
	// while (current_a)
	// {
	// 	clock_wise = current_a->index - current_b->index;
	// 	if (clock_wise < 0)
	// 		clock_wise *= -1;
	// 	printf("clck: %d\n", clock_wise);
	// 	array[current_a->index] = clock_wise + i;
	// 	array_i[current_a->index] = i;
	// 	current_a = current_a->next;
	// 	i++;
	// }
	while (current_a)
	{
	// printf("===Printing Stack B===\n");
	// ps_print_stack(*b);
		if (current_a->value > current_b->value && current_a->value < max_b)
		{
			clock_wise = calculate_small_max_b(&current_a, b, max_b);
			// printf("T5\n");
		}
		else if (current_a->value > max_b)
			clock_wise = clck_while_nb_edge(b, current_a->value);
		else if (current_a->value < min_b)
			clock_wise = clck_while_nb_big(b, current_a->value);
		else if (current_a->value < current_b->value && current_a->value > min_b)
			clock_wise = clck_while_nb_big(b, current_a->value);
		// else
		// {
		// 	clock_wise = current_a->index - current_b->index;
		// 		if (clock_wise < 0)
		// 			clock_wise *= -1;
		// }
		printf("clck: %d for %d\n", clock_wise, current_a->value);
		array[current_a->index] = (long)(clock_wise + i);
		array_i[current_a->index] = (long)i;
		current_a = current_a->next;
		i++;
	}
	printf("T4\n");
	clock_wise = INT_MAX; //to find min
	i = 0;
	temp = 0;
	while (length--)
	{
		if (array[i] < clock_wise && i < median_index)
		{
			clock_wise = (int)array[i];
			temp = i;
		}
		i++;
	}
	current_a = *a;
	printf("T5\n");
	printf("temp: %d\n", temp);
	printf("clock_wise: %d\n", clock_wise);
	nb = (int)array_i[temp];
	printf("nb: %d\n", nb);
	while (nb--)
		ps_rotate(a, "a");
	if (array)
		free(array);
	if (array_i)
		free(array_i);
}

// void	do_first_half(t_stack **a, t_stack **b, int median_index)
void	do_first_half(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			min_b;
	int			max_b;
	// int			median;

	// median = find_median(a);
	current_a = *a;
	current_b = *b;
	min_b = find_min(b);
	max_b = find_max(b);

	if (current_a->value > max_b || current_a->value < min_b)
	{
		sort_eff_b(b);
		ps_push(a, b, "b");
	}
	else if (current_a->value > current_b->value && current_a->value < max_b)
		do_first_first(a, b, max_b);
	else if (current_a->value < current_b->value && current_a->value > min_b)
		do_first_second(a, b, min_b);



	// if (current_a->value > current_b->value && current_a->value < max_b)
	// {
	// 	// find_cost_effective(a, b, median_index);
	// 	do_first_first(a, b, max_b);
	// }
	// else if (current_a->value > current_b->value && current_a->value > max_b)
	// {
	// 	sort_eff_b(b);
	// 	ps_push(a, b, "b");
	// }
	// else if (current_a->value < current_b->value && current_a->value < min_b)
	// {
	// 	// do_edge_nb(a, b);
	// 	sort_eff_b(b);
	// 	ps_push(a, b, "b");
	// }
	// else if (current_a->value < current_b->value && current_a->value > min_b)
	// 	do_first_second(a, b, min_b);
}

void	do_second_half(t_stack **a, t_stack **b)
{
	t_stack		*current_a;
	t_stack		*current_b;
	int			min_a;
	int			max_a;

	current_a = *a;
	current_b = *b;
	min_a = find_min(a);
	max_a = find_max(a);

	if (current_b->value > max_a || current_b->value < min_a)
	{
		sort_eff_a(a);
		ps_push(b, a, "a");
	}
	else if (current_b->value > current_a->value && current_b->value < max_a)
		do_second_first(a, b, max_a);
	else if (current_b->value < current_a->value && current_b->value > min_a)
		do_second_second(a, b, min_a);

	// if (current_b->value > current_a->value && current_b->value < max_a)
	// 	do_second_first(a, b, max_a);
	// else if (current_b->value > current_a->value && current_b->value > max_a)
	// {
	// 	sort_eff_a(a);
	// 	ps_push(b, a, "a");
	// }
	// else if (current_b->value < current_a->value && current_b->value < min_a)
	// {
	// 	// do_edge2_nb(a, b);
	// 	sort_eff_a(a);
	// 	ps_push(b, a, "a");
	// }
	// else if (current_b->value < current_a->value && current_b->value > min_a)
	// 	do_second_second(a, b, min_a);
}

void	do_big_sort(t_stack **a, int median, int length)
{
	t_stack		*current_a;
	t_stack		*current_b;
	t_stack		*b;
	int			times;
	// int			median_index;
	// printf("median: %d\n\n", median);
	
	// median_index = length / 2;

	//send two lower than median numbers to the b, if bigger, rotate a
	b = NULL;
	while (ps_find_length(&b) < 2)
	{
		current_a = *a;
		if (current_a->value < median)
			ps_push(a, &b, "b");
		else
			ps_rotate(a, "a");
	}

	//sort to values in b
	current_b = b;
	if (current_b->value < current_b->next->value)
		ps_rotate(&b, "b");

	//do sorting for lower values, if bigger, rotate
	times = length - 2;
	while (times--)
	{
		current_a = *a;
		current_b = b;
		if (current_a->value < median)
			do_first_half(a, &b);
			// do_first_half(a, &b, median_index);
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

	//take the bigger value up
	sort_eff_b(&b);

	//push bigger values to b exceptf for last 3
	length = ps_find_length(a);
	times = length - 3;
	while (times--)
	{
		ps_push(a, &b, "b");
	}

	// printf("sent to B except last 3\n");

	//sort 3 in a
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

//not sure if needed ???????????????????????????????????????????????
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
