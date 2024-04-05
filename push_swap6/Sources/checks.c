/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 18:36:28 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/05 14:57:09 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

int	ps_check_digit_or_space(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '-' || string[i] == '+' || string[i] == ' '
			|| (string[i] >= '0' && string[i] <= '9'))
		{
			if (string[i] == '-' || string[i] == '+')
			{
				if (string[i - 1] >= '0' && string[i - 1] <= '9')
					return (0);
			}
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	ps_check_digit(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '-' || string[i] == '+')
		{
			if (string[i + 1] < '0' || string[i + 1] > '9')
				return (0);
		}
		else if (string[i] < '0' || string[i] > '9' )
			return (0);
		i++;
	}
	return (1);
}

// // ===Printing Stack A===
// // Stack 0: 3
// // Stack 1: 2
// // Stack 2: 1
// int	ps_check_if_sorted(t_stack **a)
// {
// 	t_stack	*current;
// 	t_stack	*temp;

// 	current = *a;
// 	while (current->next != NULL)
// 	{
// 		temp = current->next;
// 		if (current->value < temp->value)
// 			return (0);
// 		current = current->next;
// 	}
// 	return (1);
// }

// ===Printing Stack A===
// Stack 0: 1
// Stack 1: 2
// Stack 2: 3
int	ps_check_if_sorted(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

	current = *a;
	while (current->next != NULL)
	{
		temp = current->next;
		if (current->value > temp->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ps_check_duplicates(t_stack **a)
{
	t_stack	*current;
	t_stack	*temp;

	current = *a;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->value == temp->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

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
	i = 1;
	while (str[i])
	{
		temp = ps_atoi(str[i]);
		if (ps_check_in_array(array, temp))
			return (1);
		array[i]  = temp;
		i++;
	}
	return (0);
}

bool ps_check_non_num(char **str)
{
	int	i;
	int	j;

	i = 1;
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

bool ps_big_num(char **str)
{
	int		i;
	long	temp;

	i = 0;
	while (str[i])
	{
		temp = ps_atoi(str[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}