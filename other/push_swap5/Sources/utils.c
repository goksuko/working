/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:48 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/16 10:32:40 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

// // ===Printing Stack A===
// // Stack 0: 3
// // Stack 1: 2
// // Stack 2: 1
// t_stack	*ps_write_in_stack_a(t_stack **a, int nb)
// {
// 	t_stack		*new_t_stack;
// 	t_stack		*current;

// 	new_t_stack = calloc(1, sizeof(t_stack));
// 	if (new_t_stack == NULL)
// 		return (NULL);
// 	new_t_stack->value = nb;
// 	current = *a;
// 	if (current == NULL)
// 	{
// 		*a = new_t_stack;
// 		new_t_stack->next = NULL;
// 	}
// 	else
// 	{
// 		new_t_stack->next = current;
// 		*a = new_t_stack;
// 	}
// 	return (*a);
// }

// ===Printing Stack A===
// Stack 0: 1
// Stack 1: 2
// Stack 2: 3
t_stack	*ps_write_in_stack_a(t_stack **a, int nb)
{
	t_stack		*new_t_stack;
	t_stack		*current;

	new_t_stack = calloc(1, sizeof(t_stack));
	if (new_t_stack == NULL)
		return (NULL);
	new_t_stack->value = nb;
	new_t_stack->next = NULL;
	current = *a;
	if (current == NULL)
		*a = new_t_stack;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_t_stack;
	}
	return (*a);
}

t_stack	*ps_one_arg_to_stack_a(char *string, t_stack **a)
{
	char		**array;
	int			i;
	int			nb;
	// char		*temp;

	array = ft_split(string, ' ');
	i = 0;
	// printf("T3\n");
	// if (array[1] == NULL)
	// {
	// 	temp = ft_strtrim(array[0], "\"");
	// 	printf("%s\n", temp);
	// 	nb = (int)ps_atoi_matrix(temp, array, a);
	// 	// printf("T7\n");
	// 	*a = ps_write_in_stack_a(a, nb);
	// 	free(temp);
	// 	temp = NULL;
	// }
	// else
	// {
		while (array[i])
		{
			if (!ps_check_digit(array[i]))
			{
				// printf("T4\n");
				free_matrix(array);
				ps_write_error();
			}
			// printf("T5\n");
			nb = (int)ps_atoi_matrix(array[i], array, a);
			// printf("T6\n");
			*a = ps_write_in_stack_a(a, nb);
			i++;
		}
	// }
	free_matrix(array);
	return (*a);
}

t_stack	*ps_arguments_to_stack_a(char *string, t_stack **a)
{
	int			nb;

	if (!ps_check_digit(string))
	{
		ps_write_error();
	}
	nb = (int)ps_atoi(string);
	*a = ps_write_in_stack_a(a, nb);
	return (*a);
}
