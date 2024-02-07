/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:48 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/05 00:24:07 by akaya-oz      ########   odam.nl         */
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

int	ps_check_alpha(char *string)
{
	int	i;

	i = 0;
	while(string[i])
	{
		if ((string[i] >= 'a' && string[i] <= 'z' ) || (string[i] >= 'A' && string[i] <= 'Z' ))
			return (1);
		i++;
	}
	return (0);
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
		if (ps_check_alpha(array[i]))
		{
			free_matrix(array);
			ps_write_error();		
		}
		nb = (int)ps_atoi_matrix(array[i], array, a);
		new_t_stack = calloc(1, sizeof(t_stack));
		if (new_t_stack == NULL)
			return (NULL);
		new_t_stack->value = nb;
		current = *a;
		if (current == NULL)
		{
			*a = new_t_stack;
			new_t_stack->next = NULL;
		}
		else
		{
			new_t_stack->next = current;
			*a = new_t_stack;
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

	if (ps_check_alpha(string))
	{
		ps_write_error();		
	}
	nb = (int)ps_atoi(string);
	new_t_stack = calloc(1, sizeof(t_stack));
	if (new_t_stack == NULL)
		return (NULL);
	new_t_stack->value = nb;
	new_t_stack->next = NULL;
	current = *a;
	if (current == NULL)
	{
		*a = new_t_stack;
		new_t_stack->next = NULL;
	}
	else
	{
		new_t_stack->next = current;
		*a = new_t_stack;
	}
	return	(*a);	
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}


long	ps_atoi(const char *string)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (string[i] != '\0')
	{
		while (ft_isspace(string[i]) == 1)
			i++;
		if (string[i] == '-')
			sign = -1;
		if (string[i] == '-' || string[i] == '+')
			i++;
		while (string[i] >= '0' && string[i] <= '9')
		{
			nb = (10 * nb) + (string[i] - '0');
			i++;
		}
	}
	if (sign * nb > 2147483647 || sign * nb < -2147483648)
		ps_write_error();
	return (sign * nb);
}

long	ps_atoi_matrix(const char *string, char **array, t_stack **a)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (string[i] != '\0')
	{
		while (ft_isspace(string[i]) == 1)
			i++;
		if (string[i] == '-')
			sign = -1;
		if (string[i] == '-' || string[i] == '+')
			i++;
		while (string[i] >= '0' && string[i] <= '9')
		{
			nb = (10 * nb) + (string[i] - '0');
			i++;
		}
	}
	if (sign * nb > 2147483647 || sign * nb < -2147483648)
	{
		free_matrix(array);
		*a = ps_free_list(*a);
		ps_write_error();
	}
	return (sign * nb);
}