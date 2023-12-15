/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 20:26:29 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/11 11:58:46 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	print_char(int i)
{
	char			c;
	static size_t	total;

	total = 0;
	c = (char)i;
	total += write(STDOUT_FD, &c, sizeof(char));
	return (total);
}

size_t	print_string(char *ptr)
{
	static size_t	total;
	char			*str;

	total = 0;
	if (ptr == NULL)
	{
		write(STDOUT_FD, "(nil)", 5);
		total += 5;
	}
	else
	{
		str = (char *)ptr;
		total += ft_strlen(str);
		while (*str != '\0')
		{
			write(STDOUT_FD, str, sizeof(char));
			str++;
		}
	}
	return (total);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n++;
	return (n);
}