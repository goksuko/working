/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:44:00 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/03 16:32:54 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	*free_matrix(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	if (string)
	{
		free(string);
		string = NULL;
	}
	return (NULL);
}

// void	*free_array(int *array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		free(&array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (NULL);
// }

// void	*free_there(void **db_ptr)
// {
// 	if (*db_ptr || db_ptr)
// 		free(*db_ptr);
// 	*db_ptr = NULL;
// 	return (NULL);
// }

// void	ps_error_exit(t_stack **a, t_stack **b)
// {
// 	write(1, "Error\n", 6);
// 	if (a != NULL)
// 		a = ps_free_list(*a);
// 	if (b != NULL)
// 		b = ps_free_list(*b);
// 	exit(1);
// }

void	ps_print_stack(t_stack *a)
{
	t_stack		*current;
	int			i;

	current = a;
	i = 0;
	if (current == NULL)
		ft_printf("Stack is empty.\n");
	else
	{
		while (current != NULL)
		{
			// ft_printf("Stack %d: %d\n", i, current->value);
			ft_printf("%d ", current->value);
			i++;
			current = current->next;
		}
	}
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
	int		i;
	t_stack	*current;

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

void	ps_write_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
