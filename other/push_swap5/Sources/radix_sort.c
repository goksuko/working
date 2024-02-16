/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:33:24 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 23:37:35 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

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
