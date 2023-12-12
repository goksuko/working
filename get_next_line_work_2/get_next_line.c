/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 14:17:20 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/12 14:24:15 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trim_leftover(char *temp)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (temp[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	while (temp[i] != '\0')
	{
		new_line[j] = temp[i];
		j++;
		i++;
	}
	new_line[j] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*leftover;
	char		*temp;
	char		*temp2;
	char		*new_line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	while (fd >= 0 && BUFFER_SIZE > 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		leftover = ft_strchr(buffer, '\n');
		if (!leftover)
		{
			temp2 = ft_strjoin(line, buffer);
			free(buffer);
			if (line)
				free(line);
			line = temp2;
		}
		else if (leftover)
		{
			temp = ft_strjoin(line, buffer);
			free(buffer);
			if (line)
				free(line);
			new_line = trim_leftover(temp);
			free(temp);
			return (new_line);
		}
	}
	return (NULL);
}
