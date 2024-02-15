/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 14:34:18 by akaya-oz      ########   odam.nl         */
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
		a = ps_one_arg_to_stack_a(argv[1], &a);
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

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		median;

	a = ps_take_numbers(argc, argv);
	median = find_median(&a);

	// printf("===Printing Stack A BEFORE SORT===\n");
	// ps_print_stack(a);

	if (!a || ps_check_duplicates(&a))
		ps_write_error();
	if (!ps_check_if_sorted(&a))
	{
		ps_sort(&a, median);
		// ft_printf("test\n");
	}
		// ps_make_bubble_sort(&a);

	// printf("===Printing Stack A AFTER SORT===\n");
	// ps_print_stack(a);

	if (a != NULL)
		a = ps_free_list(a);
	return (0);
}

// ./push_swap "1 2 3"  
// ===Printing Stack A BEFORE SORT===
// Stack 0: 1
// Stack 1: 2
// Stack 2: 3
// ===Printing Stack A AFTER SORT===
// Stack 0: 1
// Stack 1: 2
// Stack 2: 3

// ./push_swap "1 3 2" 
// ===Printing Stack A BEFORE SORT===
// Stack 0: 1
// Stack 1: 3
// Stack 2: 2
// sa
// ra
// ===Printing Stack A AFTER SORT===
// Stack 0: 1
// Stack 1: 2
// Stack 2: 3

// ./push_swap "1 3 2"  
// ===Printing Stack A BEFORE SORT===
// Stack 0: 1
// Stack 1: 3
// Stack 2: 2
// sa
// ===Printing Stack A AFTER SA===
// Stack 0: 3
// Stack 1: 1
// Stack 2: 2
// ra
// ===Printing Stack A AFTER RA===
// Stack 0: 1
// Stack 1: 2
// Stack 2: 3
// ===Printing Stack A AFTER SORT===
// Stack 0: 1
// Stack 1: 2
// Stack 2: 3

// time to push back
// ===Printing Stack A===
// Stack is empty.
// ===Printing Stack B===
// Stack 0: 942
// Stack 1: 834
// Stack 2: 585
// Stack 3: 555
// Stack 4: 532
// Stack 5: 529
// Stack 6: 280
// Stack 7: 247
// Stack 8: 156
// Stack 9: 154

//chmod +x test.sh && ./test.sh