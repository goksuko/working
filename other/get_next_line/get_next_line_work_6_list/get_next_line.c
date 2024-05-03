# include "get_next_line.h"

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

Node *string_to_list2(char *string)
{
	Node	*head;
	Node	*temp;
	int		i;
	
	if (string == NULL)
		return (NULL);
	head = NULL;
	temp = NULL;
	i = 0;
	while (string[i] != '\0')
	{
		head = (Node *)malloc(sizeof(Node));
		if (head == NULL)
		{
			printf("Memory not allocated");
			exit(0);
		}
		head->value = string[i];
		head->next = NULL;
		i++;
		while (string[i] != '\0')
		{
			temp = (Node *)malloc(sizeof(Node));
			if (temp == NULL)
			{
				printf("Memory not allocated");
				exit(0);
			}
			temp->value = string[i];
			temp->next = NULL;
			head->next = temp;
			i++;
		}
	}
	return (head);
}

t_list	*string_to_list(char *buffer)
{
	t_list	*s_list;
	
	if (!buffer)
		return (NULL);
	s_list = ft_lstnew(buffer);
	// printf("content is: %s\n", (char *)s_list->content);
	if (!s_list)
		return (NULL);
	return (s_list);
}

Node *return_new_line(Node **buffer_list)
{
	Node *next;
	Node *temp;

	next = NULL;
	next = split_from_value(buffer_list, '\n');
	if (next == *buffer_list)
		return (NULL);
	else
	{
		temp = *buffer_list;
		while (temp->next != next)
			temp = temp->next;
		temp->next = NULL;
		return (*buffer_list);
	}
}

t_list	*play_with_list(t_list *s_list, int fd)
{
	t_list	*list;
	char	*temp;
	size_t		i;

	i = 0;
	temp = s_list->content;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		i++;
		if (ft_strlen(temp) == i)
			s_list->next = string_to_list(read_buffer(fd));
	}	
	list = s_list;
	return (list);
}

char	*list_to_string(t_list *s_list)
{
	char	*new_line;

	new_line = s_list->content;
	while (s_list->next != NULL)
	{
		ft_lstadd_back(s_list->content, s_list->next);
		new_line = ft_strjoin(new_line, s_list->next->content);
	}
	return (new_line);
}

char	*list_to_string2(Node **list)
{
	char	*string;
	Node	*temp;
	char	c;

	string = NULL;
	temp = *list;
	while (temp != NULL)
	{
		c = temp->value;
		string = ft_strjoin(string, &c);
		temp = temp->next;
	}
	return (string);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*new_line;
	Node 	*buffer_list;
	Node	*new_line_list;
	Node	*new_buffer_list;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &new_line, 0) < 0)
		return (NULL);
	buffer = read_buffer(fd);
	buffer_list = string_to_list2(buffer);
	new_line_list = return_new_line(&buffer_list);
	while (new_line_list == NULL)
	{
		new_buffer_list = string_to_list2(read_buffer(fd));
		buffer_list = append_list(&buffer_list, &new_buffer_list);
		new_line_list = return_new_line(&buffer_list);
	}
	new_line = list_to_string2(&new_line_list);
	return (new_line);
}