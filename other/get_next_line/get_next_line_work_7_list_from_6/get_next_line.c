/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 16:05:13 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/01/04 16:07:01 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[read_bytes] = '\0';
	return (buffer);
}

t_node	*string_to_list(char *string)
{
	t_node	*head;
	t_node	*temp;
	t_node	*new_node;
	int		i;

	if (string == NULL)
		return (NULL);
	head = NULL;
	temp = NULL;
	i = 0;
	head = (t_node *)malloc(sizeof(t_node));
	if (head == NULL)
		return (NULL);
	head->value = string[i];
	head->next = NULL;
	i++;
	temp = head;
	while (string[i] != '\0')
	{
		new_node = malloc(sizeof(t_node));
		if (new_node == NULL)
			return (NULL);
		new_node->value = string[i];
		new_node->next = NULL;
		temp->next = new_node;
		temp = temp->next;
		i++;
	}
	return (head);
}

int	search_value(t_node **head, int value)
{
	t_node	*current;
	int		i;

	i = 0;	
	current = *head;
	while (current != NULL)
	{
		if (current->value == value)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

t_node	*return_new_line(t_node **buffer_list)
{
	t_node	*current;
	int		new_line_node;
	int		i;

	new_line_node = search_value(buffer_list, '\n');
	if (new_line_node == -1)
		return (NULL);
	else
	{
		i = 0;
		current = *buffer_list;
		while (i < new_line_node)
		{
			current = current->next;
			i++;
		}
		current->next = NULL;
		return (*buffer_list); //memory leak beacuse of this line
	}
}

char	*list_to_string(t_node **list)
{
	char	*string;
	char	*temp;
	t_node	*current;
	char	temp_string[2];

	current = *list;
	if (current == NULL)
		return (NULL);
	// string = malloc(sizeof(char) * 1);
	// if (string == NULL)
	// 	return (NULL);
	// string[0] = '\0';
	string = "";
	while (current != NULL)
	{
		temp_string[0] = current->value;
		temp_string[1] = '\0';
		temp = ft_strjoin(string, temp_string);
		current = current->next;
		string = temp;
	}
	return (string);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*new_line;
	t_node	*buffer_list;
	t_node	*new_line_list;
	t_node	*new_buffer_list;
	t_node	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &new_line, 0) < 0)
		return (NULL);
	buffer = read_buffer(fd);
	buffer_list = string_to_list(buffer);
	temp = duplicate_list_recursive(buffer_list);
	new_line_list = return_new_line(&temp);
	delete_list(buffer_list);
	buffer_list = rest_list(&temp, &new_line_list);
	while (new_line_list == NULL)
	{
		new_buffer_list = string_to_list(read_buffer(fd));
		buffer_list = append_list(&buffer_list, &new_buffer_list);
		new_buffer_list = NULL;
		temp = duplicate_list_recursive(buffer_list);
		printf("temp: %s\n", list_to_string(&temp));
		new_line_list = return_new_line(&buffer_list);
		delete_list(buffer_list);
		buffer_list = rest_list(&temp, &new_line_list);
		delete_list(temp);
	}
	printf("test\n");
	new_line = list_to_string(&new_line_list);
	return (new_line);
}
