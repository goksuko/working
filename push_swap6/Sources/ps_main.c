/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/03 16:58:14 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ps_take_numbers(t_stack **a, int argc, char *argv[])
{
	int			i;
	char		*temp;
	int			nb;


	i = 1;
	if (argc < 2)
	{
		return (0);
	}
	else if (argc == 2)
	{
		// if (*argv[1] == '\0')
		// 	ps_write_error();
		// else if (!ft_char_in_set(' ', argv[1]) && !ps_check_digit(argv[1]))
		if (!ft_char_in_set(' ', argv[1]) && !ps_check_digit(argv[1]))
		{
			temp = ft_strtrim(argv[1], "\"");
			// printf("%s\n", temp);
			if (!ps_check_digit(temp))
			{
				ps_write_error();
				return (0);
			}
			nb = (int)ps_atoi(temp);
			*a = ps_write_in_stack_a(a, nb);
			free(temp);
			temp = NULL;
		}
		else if (!ft_char_in_set(' ', argv[1]) && ps_check_digit(argv[1]))
		{
			nb = (int)ps_atoi(argv[1]);
			*a = ps_write_in_stack_a(a, nb);
		}
		else
			*a = ps_one_arg_to_stack_a(argv[1], a);
	}
	else if (argc > 2)
	{
		while (i < argc)
		{
			*a = ps_arguments_to_stack_a(argv[i], a);
			i++;
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	int		median;
	int		length;

	// printf("T1\n");
	// if (argc != 2)
	// {
	// 	ps_write_error();
	// 	return (0);
	// }
	a = NULL;
	if (ps_take_numbers(&a, argc, argv))
	{
		if (!a || ps_check_duplicates(&a))
		{
			ps_write_error();
			return (0);
		}
		give_index(&a);
	}
	else
		return (0);
	// printf("index of first %d\n", a->index);
	// printf("T2\n");

	length = ps_find_length(&a);
	if (length <= 2)
		median = 0;
	else
		median = find_median(&a);

	// printf("===Printing Stack A BEFORE SORT===\n");
	// ps_print_stack(a);


	if (a && !ps_check_if_sorted(&a))
		ps_sort(&a, median);

	// printf("===Printing Stack A AFTER SORT===\n");
	// ps_print_stack(a);

	if (a)
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