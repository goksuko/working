/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks_new.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 18:36:28 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/12 15:22:21 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

bool	ps_check_in_array(long *array, long temp)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (temp == array[i])
			return (1);
		i++;
	}
	return (0);
}

bool	ps_check_dupp(char **str)
{
	int		i;
	long	temp;
	long	array[1000];

	i = 0;
	while (i < 1000)
	{
		array[i] = LONG_MAX;
		i++;
	}
	i = 0;
	while (str[i])
	{
		temp = ps_string_to_long(str[i]);
		if (ps_check_in_array(array, temp))
			return (1);
		array[i] = temp;
		i++;
	}
	return (0);
}

bool	ps_check_non_num(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-')
			j++;
		if (str[i][j] == '\0')
			return (1);
		while (str[i][j])
		{
			if (str[i][j] <= '9' && str[i][j] >= '0')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

bool	ps_big_num(char **str)
{
	int		i;
	long	temp;

	i = 0;
	while (str[i])
	{
		temp = ps_string_to_long(str[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

bool	ps_initial_probs(int argc, char *argv[])
{
	if (argc < 2)
		return (1);
	if (argc == 2 && (!argv[1] || argv[1][0] == '\0'))
	{
		ps_write_error();
		return (1);
	}
	return (0);
}
