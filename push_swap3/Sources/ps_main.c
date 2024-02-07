/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/07 21:00:05 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ps_make_bubble_sort(t_stack **a)
{
	int		start;
	t_stack	*current;
	int		length;

	current = *a;
	length = ps_find_length(a);
	while (length--)
	{
		if (current->value > current->next->value)
			ps_sa(a);
		current = *a;
		start = current->value;
		ps_ra(a);
		current = *a;
		while (current->value != start)
		{
			if (current->value > current->next->value
				&& current->next->value != start)
				ps_sa(a);
			ps_ra(a);
			current = *a;
		}
	}
}

t_stack	*ps_take_numbers(int argc, char *argv[])
{
	t_stack		*a;
	int			i;

	a = NULL;
	i = 1;
	if (argc < 2)
		ps_write_error();
	else if (argc == 2)
		a = ps_string_to_stack_a(argv[1], &a);
	else if (argc > 2)
	{
		while (i < argc)
		{
			a = ps_arguments_to_stack_a(argv[i], &a);
			i++;
		}
	}
	return (a);
}

// int	main(int argc, char *argv[])
// {
// 	t_stack	*a;
// 	// t_stack	*b;

// 	// b = NULL;
// 	a = ps_take_numbers(argc, argv);
// 	printf("===Printing Stack A===\n");
// 	ps_print_stack(a);
// 	if (!a || ps_check_duplicates(&a))
// 		ps_write_error();
// 	// printf("===Printing Stack A===\n");
// 	// ps_print_stack(a);
// 	if (!ps_check_if_sorted(&a))
// 		ps_sort(&a);
// 		// ps_make_bubble_sort(&a);
// 	printf("===Printing Stack A===\n");
// 	ps_print_stack(a);
// 	if (a != NULL)
// 		a = ps_free_list(a);
// 	// if (b != NULL)
// 	// 	b = ps_free_list(b);	
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_stack	*a;
	// t_stack	*b;

	// b = NULL;
	a = ps_take_numbers(argc, argv);
	printf("===Printing Stack A===\n");
	ps_print_stack(a);
	// ps_sa(&a);
	ps_sort(&a);
	printf("===Printing Stack A===\n");
	ps_print_stack(a);
	if (a != NULL)
		a = ps_free_list(a);
	// if (b != NULL)
	// 	b = ps_free_list(b);	
	return (0);
}
