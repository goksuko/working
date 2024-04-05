/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/07 15:44:00 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/05 14:38:41 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	*free_matrix(char **string)
{
	int	i;

	i = 0;
	while (string && string[i])
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
	write(2, "Error\n", 6);
	exit(1);
}

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
			ft_printf("Stack %d: %d\n", i, current->value);
			i++;
			current = current->next;
		}
	}
}
