/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:48 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/05 23:08:27 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

t_stack	*ps_write_in_stack_a(t_stack **a, int nb)
{
	t_stack		*new_t_stack;
	t_stack		*current;

	new_t_stack = malloc(1 * sizeof(t_stack));
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

	array = ft_split(string, ' ');
	i = 0;
	while (array[i])
	{
		nb = (int)ps_atoi_matrix(array[i], array, a);
		*a = ps_write_in_stack_a(a, nb);
		i++;
	}
	free_matrix(array);
	return (*a);
}

t_stack	*ps_arguments_to_stack_a(char *string, t_stack **a)
{
	int			nb;

	nb = (int)ps_atoi(string);
	*a = ps_write_in_stack_a(a, nb);
	return (*a);
}

int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
