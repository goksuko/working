/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:54 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/05 23:07:59 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_stack	*ps_two_arguments(t_stack **a, char *str)
{
	char		*temp;

	if (!ps_check_digit_or_space(str))
		return (NULL);
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
	if (ps_check_duplicates(a))
	{
		ps_write_error();
		*a = ps_free_list(*a);
		return (NULL);
	}
	return (*a);
}

int	ps_take_numbers(t_stack **a, char **args)
{
	int			i;

	i = 0;
	while (args[i])
	{
		*a = ps_arguments_to_stack_a(args[i], a);
		i++;
	}
	return (1);
}

bool	ps_check_probs(char **str)
{
	if (ps_check_non_num(str))
		return (1);
	if (ps_big_num(str))
		return (1);
	if (ps_check_dupp(str))
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	char	**args;

	if (ps_initial_probs(argc, argv))
		return (1);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	if (ps_check_probs(args))
	{
		if (argc == 2)
			free_matrix(args);
		ps_write_error();
		return (1);
	}
	a = NULL;
	ps_take_numbers(&a, args);
	if (a && !ps_check_if_sorted(&a))
		ps_sort(&a);
	if (a)
		a = ps_free_list(a);
	if (argc == 2)
		free_matrix(args);
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