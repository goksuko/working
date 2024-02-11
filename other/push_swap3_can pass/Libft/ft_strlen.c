/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 11:25:44 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/11/04 16:46:41 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n++;
	return (n);
}
/*
int	main(void)
{
	const char	*s = "test";

	printf("%zu\n", ft_strlen(s));
	printf("%lu\n", strlen(s));
	return (0);
}
*/