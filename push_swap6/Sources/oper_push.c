/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   oper_push.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:31:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/03 15:39:52 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	ps_push_writer(char *str)
{
	if (*str == 'a')
		write(1, "pa\n", 3);
	else if (*str == 'b')
		write(1, "pb\n", 3);
}

//push: Take the first element at the top of src and put it at the top of dest.
//Do nothing if src is empty.
void	ps_push(t_stack **src, t_stack **dest, char *str)
{
	t_stack		*to_return;
	t_stack		*current;
	t_stack		*temp;

	current = *src;
	if (current == NULL)
		return ;
	else
	{
		to_return = current->next;
		temp = *src;
		*src = to_return;
	}
	if (*dest == NULL)
	{
		*dest = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dest;
		*dest = temp;
	}
	ps_push_writer(str);
}
