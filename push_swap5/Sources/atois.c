/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atois.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 18:38:01 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/10 09:39:26 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

long	ps_string_to_long(const char *string)
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
	return (sign * nb);
}

long	ps_atoi(const char *string)
{
	long	number;

	number = ps_string_to_long(string);
	if (number > INT_MAX || number < INT_MIN)
		ps_write_error();
	return (number);
}

long	ps_atoi_matrix(const char *string, char **array, t_stack **a)
{
	long	number;

	number = ps_string_to_long(string);
	if (number > INT_MAX || number < INT_MIN)
	{
		free_matrix(array);
		*a = ps_free_list(*a);
		ps_write_error();
	}
	return (number);
}
