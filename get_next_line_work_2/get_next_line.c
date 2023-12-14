/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 14:17:20 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/14 22:54:46 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_buffer(int fd, char *buffer)
{
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free_there(&buffer));
	buffer[bytes_read] = '\0';
	return (buffer);
}

static char	*trim_leftover(char *temp)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// printf("trim: temp: %s\n", temp);
	while (temp[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	// printf("trim: i: %d\n", i);
	while (i--)
	{
		new_line[j] = temp[j];
		j++;
	}
	new_line[j] = '\0';
	// printf("trim: new_line: %s\n", new_line);
	return (new_line);
}


char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*leftover;
	char		*new_line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = "";
	leftover = NULL;
	while (fd >= 0 && BUFFER_SIZE > 0 && !leftover)
	{
		buffer = read_to_buffer(fd, buffer);
		printf("1: buffer: %s\n", buffer);
		if (!buffer)
		{
			new_line = ft_strdup(line);
			printf("4: line: %s\n", line);
			printf("5: new_line: %s\n", new_line);
			free_there(&line);
			return (new_line);
		}
		leftover = ft_strchr(buffer, '\n');
		printf("2: leftover: %s$\n", leftover);
		temp = ft_strjoin(line, buffer);
		printf("3: line: %s\n", line);
		free_there(&buffer);
		free_there(&line);
		line = ft_strdup(temp);
		free_there(&temp);
		if (leftover)
		{
			new_line = trim_leftover(line);
			// printf("line: %s\n", line);
			// printf("new_line: %s\n", new_line);
			free_there(&line);
			return (new_line);
		}
	}
	free_there(&line);
	return (NULL);
}
