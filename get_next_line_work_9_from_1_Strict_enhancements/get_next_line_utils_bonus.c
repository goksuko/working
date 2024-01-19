/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 12:36:07 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/01/19 11:32:29 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_there(char **line)
{
	if (*line || line)
		free(*line);
	*line = NULL;
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n++;
	return (n);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*full_s;
	int		i;

	if (ft_strlen(s1) + ft_strlen(s2) == 0)
		return (free_there(&s1));
	full_s = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1)
			* sizeof(char));
	if (!full_s)
		return (free_there(&s1));
	i = 0;
	while (s1[i])
	{
		full_s[i] = s1[i];
		i++;
	}
	while (*s2)
		full_s[i++] = *(s2++);
	full_s[i] = '\0';
	free_there(&s1);
	return (full_s);
}

char	*gnl_strdup(const char *s)
{
	char	*temp;
	size_t	i;

	if (!s)
		return (NULL);
	temp = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
