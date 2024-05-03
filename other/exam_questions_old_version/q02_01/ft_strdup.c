#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *ft_strdup(char *src)
{
	char	*copy;
	int	i;

	i = 0;
	while (src[i])
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// int	main()
// {
// 	char *str1 = "Adanaya";
// 	// char *str2 = "aya";
// 	// char	*str2 = "ne";
// 	// char	*str2 = "f";
// 	// char	*str2 = "en";

// 	printf("my: %s\n", ft_strdup(str1));
// 	printf("org: %s\n", strdup(str1));
// 	return (0);
// }


// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);
