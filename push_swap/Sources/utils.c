/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:48 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/02 13:22:58 by akaya-oz      ########   odam.nl         */
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

t_stack	*ps_string_to_stack_a(char *string, t_stack **a)
{
	char		**array;
	t_stack		*new_t_stack;
	t_stack		*current;
	int			i;
	int			nb;

	array = ft_split(string, ' ');
	i = 0;
	while (array[i])
	{
		nb = ft_atoi(array[i]);
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
		i++;
	}
	free_matrix(array);
	return (*a);
}

t_stack	*ps_arguments_to_stack_a(char *string, t_stack **a)
{
	t_stack		*new_t_stack;
	t_stack		*current;
	int			nb;

	nb = ft_atoi(string);
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
	return	(*a);	
}
