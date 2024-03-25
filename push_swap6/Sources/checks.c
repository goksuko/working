/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/06 18:36:28 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/25 11:44:12 by akaya-oz      ########   odam.nl         */
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
