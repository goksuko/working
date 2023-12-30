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
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (NULL);
	// printf("trim: i: %d\n", i);
	while (j <= i)
	{
		new_line[j] = temp[j];
		j++;
	}
	new_line[j] = '\0';
	// printf("trim: new_line: %s$\n", new_line);
	return (new_line);
}


char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	char		*leftover;
	char		*new_line;
	char		*temp_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &new_line, 0) < 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	leftover = NULL;
	buffer = NULL;
	while (fd >= 0 && BUFFER_SIZE > 0 && !leftover)
	{
		temp_buffer = read_to_buffer(fd, buffer);
		// printf("temp_buffer: %s\n", temp_buffer);
		buffer = ft_strjoin(buffer, temp_buffer);
		// printf("buffer: %s\n", buffer);
		free_there(&temp_buffer);
		// printf("buffer: %s\n", buffer);
		if (!buffer && line[0] == '\0')
		{
			free_there(&line);
			return (NULL);
		}
		if (!buffer && line)
		{
			new_line = ft_strdup(line);
			free_there(&line);
			return (new_line);
		}
		leftover = take_leftover(buffer);
		line = ft_strjoin(line, buffer);
		if (leftover)
		{
			new_line = trim_leftover(line);
			buffer = ft_strdup(leftover);
			free_there(&line);
			return (new_line);
		}
	}
	free_there(&line);
	return (NULL);
}




//copilot below


// char	*ft_get_line(char **str)
// {
// 	char	*line;
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	while ((*str)[i] && (*str)[i] != '\n')
// 		i++;
// 	if ((*str)[i] == '\0')
// 	{
// 		line = ft_strdup(*str);
// 		free(*str);
// 		*str = NULL;
// 		return (line);
// 	}
// 	line = ft_substr(*str, 0, i + 1);
// 	tmp = ft_strdup(*str + i + 1);
// 	free(*str);
// 	*str = tmp;
// 	return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*str;
// 	char		*line;
// 	int			ret;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!(line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
// 		return (NULL);
// 	if (!str)
// 		str = ft_strdup("");
// 	while (!ft_strchr(str, '\n') && (ret = read(fd, line, BUFFER_SIZE)) > 0)
// 	{
// 		line[ret] = '\0';
// 		str = ft_strjoin(str, line);
// 	}
// 	free(line);
// 	if (ret < 0)
// 		return (NULL);
// 	return (ft_get_line(&str));
// }
