/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/30 22:40:09 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/30 23:38:10 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*free_there(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*read_buffer(int fd)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
		return (NULL);
	buffer[read_bytes] = '\0';
	return (buffer);
}

char	*return_new_line(char **line)
{
	char	*new_line;
	int		i;

	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	new_line = ft_substr(*line, 0, i + 1);
	return (new_line);
}

char	*take_leftover(char *line)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(line);
	if (line[0] == '\n')
		return (ft_substr(line, 1, len));
	while (line[i] && line[i] != '\n')
	{
		i++;
		if (line[i] == '\n')
			return (ft_substr(line, i, len - i + 1));
	}
	if (line[i] == '\0' && line[i] != EOF)
		return (NULL);
	return (ft_substr(line, 0, len + 1));
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*leftover;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &new_line, 0) < 0)
		return (NULL);
	leftover = NULL;
	buffer = NULL;
	if ((line && ft_strchr(line, '\n')) || (line && ft_strchr(line, '\0')))
	{
		new_line = return_new_line(&line);
		leftover = take_leftover(line);
		free_there(&line);
		line = leftover;
		return (new_line);
	}
	buffer = read_buffer(fd);
	line = "";
	line = ft_strjoin(line, buffer);
	free_there(&buffer);
	new_line = return_new_line(&line);
	while (new_line == NULL)
	{
		buffer = read_buffer(fd);
		line = ft_strjoin(line, buffer);
		free_there(&buffer);
		new_line = return_new_line(&line);
	}
	if (new_line != NULL)
	{
		leftover = take_leftover(line);
		free_there(&line);
		line = leftover;
	}
	return (new_line);
}
