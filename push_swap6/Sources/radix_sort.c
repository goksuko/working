/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:33:24 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/16 22:39:16 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int		power_of_ten(int power)
{
	int nb;

	nb = 1;
	while (power--)
	{
		nb *= 10;
	}
	return (nb);
}

void	do_loop(t_stack **src, char *str_src, t_stack **dest, char *str_dest, int length, int power, int rest)
{
	t_stack	*current_src;
	// t_stack	*current_dest;
	int		num;

	while (length--)
	{
		current_src = *src;
		if (current_src == NULL)
			break ;
		num = current_src->value / power_of_ten(power);
		printf("%d, num: %d, power: %d, rest: %d\n", current_src->value, num, power, rest);
		if (num % 10 == rest)
			ps_push(src, dest, str_dest);
		else
			ps_rotate(src, str_src);
	}
}

int		find_neg_power(t_stack **a)
{
	int		min_a;
	int		neg_power;

	min_a = find_min(a);
	neg_power = 0;
	if (min_a < 0)
	{
		min_a = min_a / 10;
		neg_power++;
	}
	return(neg_power);
}

int		find_pos_power(t_stack **a)
{
	int		max_a;
	int		pos_power;

	max_a = find_max(a);
	pos_power = 0;
	if (max_a > 0)
	{
		max_a = max_a / 10;
		pos_power++;
	}
	return(pos_power);
}

int		find_power_max(t_stack **a)
{
	int		power_max;
	int		neg_power;
	int		pos_power;

	neg_power = find_neg_power(a);
	pos_power = find_pos_power(a);
	power_max = neg_power;
	if (pos_power > neg_power)
		power_max = pos_power;
	return (power_max);
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
	int		times;
	int		neg_num;
	// int		power_max;
	int		neg_power;
	int		pos_power;
	// int		max_a;
	// int		min_a;


	
	neg_num = 0;
	current_a = *a;
	while (current_a != NULL)
	{
		if (current_a->value < 0)
			neg_num++;
		current_a = current_a->next;
	}
	b = NULL;
	// power_max = find_power_max(a);
	neg_power = find_neg_power(a);
	pos_power = find_pos_power(a);

	//first for negative numbers
	power = 0;
	while (power <= neg_power)
	{
		// printf("T1===\n");
		rest = 9;
		while (rest >= 0)
		{
			times = neg_num;
			while (times--)
			{
				current_a = *a;
				if (current_a == NULL)
					break ;
				num = current_a->value;
				if (num < 0)
				{
					do_loop(a, "a", &b, "b", 1, power, rest);
				}
				else
					ps_rotate(a, "a");
			}
			rest--;
		}
		power++;

	printf("===Printing Stack A===\n");
	ps_print_stack(*a);
	printf("===Printing Stack B===\n");
	ps_print_stack(b);

		rest = 0;
		while (rest <= 9)
		{
			times = neg_num;
			while (times--)
			{
				current_b = b;
				if (current_b == NULL)
					break ;
				num = current_b->value;
				if (num < 0)
				{
					do_loop(&b, "b", a, "a", 1, power, rest);
				}
				else
					ps_rotate(&b, "b");
			}
			rest++;
		}
		power++;

	printf("===Printing Stack A===\n");
	ps_print_stack(*a);
	printf("===Printing Stack B===\n");
	ps_print_stack(b);
	}

	//if neg numbers are on the top of a, send them to the b
	if (!b)
	{
		times = neg_num;
		while (neg_num--)
		{
			ps_push(a, &b, "b");
		}
	}		

	length = ps_find_length(a);
	//second for positive numbers
	power = 0;
	while (power <= pos_power)
	{
		// printf("T2===\n");
		rest = 0;
		while (rest <= 9)
		{
			times = length;
			while (times--)
			{
				current_a = *a;
				if (current_a == NULL)
					break ;
				num = current_a->value;
				do_loop(a, "a", &b, "b", 1, power, rest);
			}
			rest++;
		}
		power++;
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);

	// 	sort_eff_b(&b);
	// printf("b efficient sorted\n");

	printf("===Printing Stack A===\n");
	ps_print_stack(*a);
	printf("===Printing Stack B===\n");
	ps_print_stack(b);

		rest = 9;
		while (rest >= 0)
		{
			times = length;
			while (times--)
			{
				current_b = b;
				if (current_b == NULL)
					break ;
				num = current_b->value;
				do_loop(&b, "b", a, "a", 1, power, rest);
			}
			rest--;
		}
		power++;

	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);

	// 	sort_eff_a(a);

	// printf("a efficient sorted\n");

		printf("===Printing Stack A===\n");
		ps_print_stack(*a);
		printf("===Printing Stack B===\n");
		ps_print_stack(b);
		
	}


	// while (power < 2)
	// {
	// 	rest = 0;
	// 	while (rest < 10)
	// 	{
	// 		length = ps_find_length(a);
	// 		while (length--)
	// 		{
	// 			current_a = *a;
	// 			num = current_a->value % (10 ^ power);
	// 			if (num % 10 == rest)
	// 				ps_push(a, &b, "b");
	// 			else
	// 				ps_rotate(a, "a");
	// 		}
	// 		rest++;
	// 	}
	// 	power++;

	// 	printf("power is %d\n", power);
	// 	printf("===Printing Stack A===\n");
	// 	ps_print_stack(*a);
	// 	printf("===Printing Stack B===\n");
	// 	ps_print_stack(b);

	// 	rest = 9;
	// 	while (rest >= 0)
	// 	{
	// 		length = ps_find_length(&b);
	// 		while (length--)
	// 		{
	// 			current_b = b;
	// 			num = current_b->value % (10 ^ power);
	// 			if (current_b->value / 10 % 10 == rest)
	// 				ps_push(&b, a, "a");
	// 			else
	// 				ps_rotate(&b, "b");
	// 		}
	// 		rest--;
	// 	}
	// 	power++;

	// 	printf("power is %d\n", power);
	// 	printf("===Printing Stack A===\n");
	// 	ps_print_stack(*a);
	// 	printf("===Printing Stack B===\n");
	// 	ps_print_stack(b);

	// }
	
	length = ps_find_length(&b);
	while (length--)
	{
		ps_push(&b, a, "a");
	}
}
