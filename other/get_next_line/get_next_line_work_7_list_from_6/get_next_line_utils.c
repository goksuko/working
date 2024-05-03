/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 16:05:00 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/01/04 16:08:32 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		join[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = '\0';
	return (join);
}

t_node	*split_from_value(t_node **head, int value)
{
	t_node    *current;
	t_node    *following;
	t_node	*temp;

	current = *head;
	if (current == NULL)
		return (NULL);
	temp = NULL;
	while (current != NULL)
	{
		if (current->value == value)
		{
			following = current->next;
			temp = current;
			break ;
		}
		current = current->next;
	}
	if (temp != NULL)
	{
		current = *head;
		while (current->next != following)
		{
			temp = current;
			current = current->next;
			free(temp);
		}
		current->next = NULL;
		free(current);
		return (following);
	}
	return (*head);
}


t_node	*append_list(t_node **head1, t_node **head2)
{
	t_node	*current;

	current = *head1;
	if (current == NULL)
		return (*head2);
	if (*head2 == NULL)
		return (*head1);
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = *head2;
		return (*head1);
	}
}

t_node*	insert_at_tail(t_node **head, int new_value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = calloc(1, sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = new_value;
	new_node->next = NULL;
	current = *head;
	if (current == NULL)
		return (new_node);
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		return (*head);
	}
}

t_node	*duplicate_list(t_node **head)
{
	t_node	*current;
	t_node	*new_head;

	current = *head;
	if (current == NULL)
		return (NULL);
	new_head = NULL;
	while (current != NULL)
	{
		new_head = insert_at_tail(&new_head, current->value);
		current = current->next;
	}
	return (new_head);
}


t_node	*duplicate_list_recursive(t_node *node)
{
	t_node	*new_node;

	//in order to finish the recursive at tail
	if (node == NULL)
		return (NULL);
	new_node = calloc(1, sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = node->value;
	new_node->next = duplicate_list_recursive(node->next);
	return (new_node);
}

t_node	*delete_list(t_node *node)
{
	if (node != NULL)
	{
		delete_list(node->next);
		free(node);
	}
	return (NULL);
}

int	length(t_node **head)
{
	t_node	*current;
	int		i;

	current = *head;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}  

void	print_list(t_node **head)
{
	t_node	*current;
	int		i;

	current = *head;
	i = 0;
	printf("===Printing List===\n");
	while (current != NULL)
	{
		printf("t_node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}

t_node	*rest_list(t_node **long_list, t_node **begin)
{
	t_node	*current_long;
	t_node	*current_begin;
	t_node	*new_head;
	t_node	*temp;

	current_long = *long_list;
	current_begin = *begin;
	if (current_long == NULL)
		return (NULL);
	if (current_begin == NULL)
		return (current_long);
	while (current_begin->next != NULL) // && current_begin->value != '\n')
	{
		temp = current_long;
		current_long = current_long->next;
		free(temp);
		temp = current_begin;
		current_begin = current_begin->next;
		free(temp);
	}
	new_head = current_long->next;
	free(current_long);
	free(current_begin);
	return (new_head);
}