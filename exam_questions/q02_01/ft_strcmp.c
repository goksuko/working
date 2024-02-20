#include <string.h>
#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1 && s2)
		i++;
	return (s1[i] - s2[i]);
}


// int	main()
// {
// 	char *str1 = "Adana";
// 	char *str2 = "Ankara";

// 	printf("my: %d\n", ft_strcmp(str1, str2));
// 	printf("org: %d\n", strcmp(str1, str2));
// 	return (0);
// }

// Assignment name  : ft_strcmp
// Expected files   : ft_strcmp.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcmp (man strcmp).

// Your function must be declared as follows:

// int    ft_strcmp(char *s1, char *s2);