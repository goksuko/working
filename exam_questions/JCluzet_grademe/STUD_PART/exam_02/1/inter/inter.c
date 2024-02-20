/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inter.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: galpers <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 19:33:45 by galpers       #+#    #+#                 */
/*   Updated: 2024/02/19 00:06:44 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int k;
	int l;
	char *s1;
	char *s2;

	i = 0;
	l = 0;
	if (ac == 3)
	{
		s1 = av[1];
		s2 = av[2];
		while (s1[i] != '\0')
		{
			k = 0;
			while (s2[k] != '\0')
			{
				if(s1[i] == s2[k])
				{ 
					l = 0;
					while (s1[l] != s1[i])
						l++;
					if (l == i)
					{
						l = 0;
						while (s2[l] != s2[k])
							l++;
						if (l == k)
							write(1, &s1[i], 1);
					}
				}
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}