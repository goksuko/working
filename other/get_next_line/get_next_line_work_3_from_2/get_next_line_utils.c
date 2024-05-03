/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/21 12:36:07 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/15 10:46:27 by akaya-oz      ########   odam.nl         */
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

char	*ft_strdup(const char *s)
{
	char	*copy1;
	char	*copy2;
	size_t	i;

	copy1 = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!copy1)
		return (NULL);
	i = 0;
	copy2 = (char *)s;
	while (copy2[i] != '\0')
	{
		copy1[i] = copy2[i];
		i++;
	}
	copy1[i] = '\0';
	return (copy1);
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

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (0);
		}
		str++;
	}
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n++;
	return (n);
}
