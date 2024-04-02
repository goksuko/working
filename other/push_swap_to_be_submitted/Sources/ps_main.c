/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/27 14:56:15 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_stack	*ps_two_arguments(t_stack **a, char *str)
{
	char		*temp;

	if (!ps_check_digit_or_space(str))
		return (0);
	if (!ft_char_in_set(' ', str))
	{
		temp = ft_strtrim(str, "\"");
		if (!ps_check_digit(temp))
			ps_write_error();
		free(temp);
		temp = NULL;
		return (*a);
	}
	else
		*a = ps_one_arg_to_stack_a(str, a);
	if (ps_check_duplicates(a)) ///eklendi
	{
		ps_write_error();
		*a = ps_free_list(*a);
		return (NULL);
	}
	return (*a);
}

int	ps_take_numbers(t_stack **a, int argc, char *argv[])
{
	int			i;
	int			test;

	i = 1;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (1);
		if (argv[1][0] == ' ' && argv[1][1] == '\0')
			return (1);
		// test = ps_two_arguments(a, argv[1]);
		// if (test)
		// 	return (0);	
		*a = ps_two_arguments(a, argv[1]);
		if (*a)
			return (0);
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

	a = NULL;
	if (ps_take_numbers(&a, argc, argv))
	{
		ft_printf("test\n"); //eklendi
		ps_print_stack(a); ///eklendi
		if (ps_check_duplicates(&a)) ///degisti
		{
			ps_write_error();
			a = ps_free_list(a);
			return (0);
		}
		if (!a)
		{
			ps_write_error();
			return (0);
		}
	}
	else
		return (0);
	if (a && !ps_check_if_sorted(&a))
		ps_sort(&a);
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


///f0r3s19% make && ./push_swap "2 15 5 58 0" 
// f0r3s19% make && ./push_swap "2 15 5 58 0 0" 
// f0r3s19% make && ./push_swap "2" 

