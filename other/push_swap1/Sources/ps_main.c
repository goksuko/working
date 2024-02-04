/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/04 17:02:02 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ps_print_stack(t_stack *a)
{
	t_stack		*current;
	int			i;

	current = a;
	i = 0;
	printf("\033[1;34m");
	if (current == NULL)
		printf("Stack is empty.\n");
	else
	{
		while (current != NULL)
		{
			printf("Stack %d: %d\n", i, current->value);
			i++;
			current = current->next;
		}
	}
	printf("\033[0m");
}

t_stack	*ps_free_list(t_stack *t_stack)
{
	if (t_stack != NULL)
	{
		ps_free_list(t_stack->next);
		free(t_stack);
	}
	return (NULL);
}

int	ps_find_length(t_stack **a)
{
	int 	i;
	t_stack *current;

	i = 0;
	current = *a;
	if (current == NULL)
		return (0);
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ps_make_bubble_sort(t_stack **a)
{
	int		start;
	t_stack	*current;
	int		length;
	// int		big;
	// int		small;

	// big = 0;
	// small = 0;
	current = *a;
	// start = current->value;
	// printf("start: %d\n", start);
	// ps_ra(a);
	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(*b);
	length = ps_find_length(a);
	// printf("length: %d\n", length);
	while(length--)
	{
		if (current->value > current->next->value)
		{
			// printf("===Printing Stack A===\n");
			// ps_print_stack(a);
			// big++;
			// printf("swap: %d for %d\n", big, current->value);
			ps_sa(a);
			// printf("===Printing Stack A===\n");
			// ps_print_stack(*a);
		}
		current = *a;
		start = current->value;
		// printf("start: %d\n", start);
		ps_ra(a);
		current = *a;
		// printf("===Printing Stack A===\n");
		// ps_print_stack(*a);
		while(current->value != start)
		{
			if (current->value > current->next->value && current->next->value != start)
			{
				// printf("===Printing Stack A before swap===\n");
				// ps_print_stack(*a);
				// big++;
				// printf("swap2: %d for %d\n", big, current->value);
				ps_sa(a);
				// printf("===Printing Stack A after swap===\n");
				// ps_print_stack(*a);
			}
			// else
			// {
			// 	small++;
			// 	printf("rotate: %d for %d\n", small, current->value);
				// printf("===Printing Stack A===\n");
				// ps_print_stack(a);
				ps_ra(a);
				current = *a;
				// printf("===Printing Stack A===\n");
				// ps_print_stack(*a);
			// }
			// printf("before value: %d\n", current->value);
			// printf("===Printing Stack A===\n");
			// ps_print_stack(*a);
			// printf("===Printing Stack B===\n");
			// ps_print_stack(*b);
			// printf("value: %d\n", current->value);
		}
		// printf("length: %d\n", length);
	}
}

void	ps_divide(t_stack **a, t_stack **b)
{
	int		start;
	// int		length;
	t_stack	*current;
	int		big;
	int		small;

	big = 0;
	small = 0;
	// length = ps_find_length(a);
	// printf("length: %d\n", length);
	current = *a;
	start = current->value;
	printf("start: %d\n", start);
	ps_ra(a);
	// printf("===Printing Stack A===\n");
	// ps_print_stack(*a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(*b);
	// length = ps_find_length(a);
	// printf("length: %d\n", length);
	current = *a;
	printf("first value: %d\n", current->value);
	while(current->value != start)
	{
		if (current->value > start)
		{
		// printf("===Printing Stack A===\n");
		// ps_print_stack(a);
			big++;
			printf("big: %d for %d\n", big, current->value);
			ps_pb(a, b);
		// printf("===Printing Stack A===\n");
		// ps_print_stack(a);
		}
		else
		{
			small++;
			printf("small: %d for %d\n", small, current->value);
			// printf("===Printing Stack A===\n");
			// ps_print_stack(a);
			ps_ra(a);

		// 	printf("===Printing Stack A===\n");
		// 	ps_print_stack(a);
		}
		current = *a;
		// printf("before value: %d\n", current->value);
		// printf("===Printing Stack A===\n");
		// ps_print_stack(*a);
		// printf("===Printing Stack B===\n");
		// ps_print_stack(*b);
		printf("value: %d\n", current->value);
	}
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 2)
		a = ps_string_to_stack_a(argv[1], &a);
	else if (argc > 2)
	{
		while (i < argc)
		{
			a = ps_arguments_to_stack_a(argv[i], &a);
			i++;
		}
	}
	// printf("===Printing Stack A===\n");
	// ps_print_stack(a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);
	ps_make_bubble_sort(&a);
	// printf("sort finished\n");
	// printf("===Printing Stack A===\n");
	// ps_print_stack(a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);
	// ps_pb(&a, &b);
	// printf("===Printing Stack A===\n");
	// ps_print_stack(a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);
	// ps_pb(&a, &b);
	// printf("===Printing Stack A===\n");
	// ps_print_stack(a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);
	// ps_rra(&a);
	// ps_rrb(&b);
	// printf("===Printing Stack A===\n");
	// ps_print_stack(a);
	// printf("===Printing Stack B===\n");
	// ps_print_stack(b);
	if (a != NULL)
		a = ps_free_list(a);
	if (b != NULL)
		b = ps_free_list(b);
	return (0);
}
