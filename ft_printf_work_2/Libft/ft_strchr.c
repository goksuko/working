/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 11:28:04 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/10/27 13:51:06 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*The strchr() function returns a pointer 
to the first occurrence of the 
character c in the string s.
The strchr() function returns a pointer 
to the first occurrence of the character 
c in the string s.*/

#include "libft.h"

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
/*
int	main(void)
{
	char	*s;
	char	ss[] = "tripouille";
	int		c;

	s = "Hello";
	c = 'l';
	printf("org code:%s\n", strchr(s, c));
	printf(" my code:%s\n", ft_strchr(s, c));
	printf("org code:%s\n", strchr(ss, 't' + 256));
	printf(" my code:%s\n", ft_strchr(ss, 't' + 256));
	return (0);
}
*/