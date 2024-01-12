/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvan-ess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:16:04 by mvan-ess          #+#    #+#             */
/*   Updated: 2023/10/24 16:16:06 by mvan-ess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*pnt;
	size_t	len;

	len = ft_strlen(s);
	pnt = malloc(sizeof(char) * len + 1);
	if (!pnt)
		return (NULL);
	ft_strlcpy(pnt, s, len + 1);
	return (pnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		strl_1;
	int		strl_2;

	if (!s1 || !s2)
		return (NULL);
	strl_1 = ft_strlen(s1);
	strl_2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (strl_1 + strl_2 + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, strl_1 + 1);
	ft_strlcpy(ptr + strl_1, s2, strl_2 + 1);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	if (len >= 1)
		ft_strlcpy(ptr, &s[start], len + 1);
	ptr[len] = 0;
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s + ft_strlen(s));
	else
		return (0);
}
