/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_radix_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/02 22:30:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/03 16:57:56 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	send_descending(t_stack **src, t_stack **dest, char *src_letter, char *dest_letter, int place)
{
	int			times;
	t_stack		*current_src;
	int			nb;
	
	nb = 9;
	while (nb >= 0 && src)
	{
		times = ps_find_length(src);
		while (times--)
		{
			current_src = *src;
			if (current_src->value < 0 && -(current_src->value / place) % 10 == nb)
				ps_push(src, dest, dest_letter);
			else
				ps_rotate(src, src_letter);
		}
		// printf("%d finished\n", nb);
		nb--;
	}
}

void	send_descending_pos(t_stack **src, t_stack **dest, char *src_letter, char *dest_letter, int place)
{
	int			times;
	t_stack		*current_src;
	int			nb;
	
	nb = 9;
	while (nb >= 0 && src)
	{
		times = ps_find_length(src);
		while (times--)
		{
			current_src = *src;
			if (current_src->value >= 0 && (current_src->value / place) % 10 == nb)
				ps_push(src, dest, dest_letter);
			else
				ps_rotate(src, src_letter);
		}
		// printf("%d finished\n", nb);
		nb--;
	}
}

void	send_ascending(t_stack **src, t_stack **dest, char *src_letter, char *dest_letter, int place)
{
	int			times;
	t_stack		*current_src;
	int			nb;
	
	nb = 0;
	// printf("entered ascending\n");
	while (nb <= 9)
	{
		times = ps_find_length(src);
			// printf("%d times\n", times);
	
		while (times--)
		{
			current_src = *src;
			if (current_src->value < 0 && -(current_src->value / place) % 10 == nb)
				ps_push(src, dest, dest_letter);
			else
				ps_rotate(src, src_letter);
		}
		// printf("%d finished\n", nb);
		nb++;
	}
}

void	send_ascending_pos(t_stack **src, t_stack **dest, char *src_letter, char *dest_letter, int place)
{
	int			times;
	t_stack		*current_src;
	int			nb;
	
	nb = 0;
	// printf("entered ascending\n");
	while (nb <= 9)
	{
		times = ps_find_length(src);
			// printf("%d times\n", times);
	
		while (times--)
		{
			current_src = *src;
			if (current_src->value >= 0 && (current_src->value / place) % 10 == nb)
				ps_push(src, dest, dest_letter);
			else
				ps_rotate(src, src_letter);
		}
		// printf("%d finished\n", nb);
		nb++;
	}
}

void	do_negatives(t_stack **a, t_stack **b)
{
	int			min;
	int			place;
	
	min = find_min(a);
	min *= -1;
	place = 1;
	while (min)
	{
		send_descending(a, b, "a", "b", place);
		// printf("place %d finished\n", place);
		place *= 10;
		min /= 10;
		if (min)
		{
			// printf("===Printing Stack A BEFORE ASC===\n");
			// ps_print_stack(*a);
			// printf("===Printing Stack B BEFORE ASC===\n");
			// ps_print_stack(*b);
			// printf("%d\n", place);			
			send_ascending(b, a, "b", "a", place);
			// printf("===Printing Stack A AFTER ASC===\n");
			// ps_print_stack(*a);
			// printf("===Printing Stack B AFTER ASC===\n");
			// ps_print_stack(*b);
			place *= 10;
			min /= 10;
		}
	}
}

void	do_positives(t_stack **a, t_stack **b)
{
	int			max;
	int			place;
	
	max = find_max(a);
	place = 1;
	while (max)
	{
		send_ascending_pos(a, b, "a", "b", place);
		// printf("place %d finished\n", place);
		place *= 10;
		max /= 10;
		if (max)
		{
			// printf("===Printing Stack A BEFORE ASC===\n");
			// ps_print_stack(*a);
			// printf("===Printing Stack B BEFORE ASC===\n");
			// ps_print_stack(*b);
			// printf("%d\n", place);			
			send_descending_pos(b, a, "b", "a", place);
			// printf("===Printing Stack A AFTER ASC===\n");
			// ps_print_stack(*a);
			// printf("===Printing Stack B AFTER ASC===\n");
			// ps_print_stack(*b);
			place *= 10;
			max /= 10;
		}
	}
}

void	make_numbers_negative(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		current->value *= -1;		
		current = current->next;
	}
}

int	find_neg_nums(t_stack **a)
{
	t_stack	*current;
	int		neg;

	current = *a;
	neg = 0;
	while (current)
	{
		if (current->value < 0)
			neg++;
		current = current->next;
	}
	return (neg);
}

int	find_pos_nums(t_stack **a)
{
	t_stack	*current;
	int		pos;

	current = *a;
	pos = 0;
	while (current)
	{
		if (current->value >= 0)
			pos++;
		current = current->next;
	}
	return (pos);
}

void	do_radix_sort(t_stack **a)
{
	// int	min;
	// int	max;

	// min = find_min(a);
	// max = find_max(a);
	int			neg;
	int			pos;
	t_stack		*b;

	// make_numbers_negative(a);
	b = NULL;

	// printf("===Printing Stack A AFTER NEG===\n");
	// ps_print_stack(*a);

	neg = find_neg_nums(a);
	pos = find_pos_nums(a);
	do_negatives(a, &b);
	// printf("===Printing Stack A AFTER DO NEG===\n");
	// ps_print_stack(*a);
	if (pos && b == NULL)
	{
		while (neg--)
			ps_push(a, &b, "b");	
	}
	do_positives(a, &b);

	while (b != NULL)
		ps_push(&b, a, "a");	

}
