#include <unistd.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1 && s2)
		i++;
	return (s1[i] - s2[i]);
}


// Assignment name  : ft_strcmp
// Expected files   : ft_strcmp.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strcmp (man strcmp).

// Your function must be declared as follows:

// int    ft_strcmp(char *s1, char *s2);