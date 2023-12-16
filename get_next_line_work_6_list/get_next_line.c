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

char	*get_next_line(int fd)
{
	char	*buffer;
	t_list 	*s_list;
	t_list	*list;
	char	*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &new_line, 0) < 0)
		return (NULL);
	buffer = read_buffer(fd);
	s_list = string_to_list(buffer);
	list = play_with_list(s_list, fd);
	new_line = list_to_string(s_list);
	return (new_line);
}