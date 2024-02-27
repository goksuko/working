#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (reject[k])
		{		
			if (s[i] == reject[k])
				return (i);
			k++;
		}
		i++;
		k = 0;
	}
	return (i);
}

// int	main()
// {
// 	char *str1 = "Adanaya";
// 	// char *str2 = "aya";
// 	// char	*str2 = "ne";
// 	char	*str2 = "f";
// 	// char	*str2 = "en";

// 	printf("my: %ld\n", ft_strcspn(str1, str2));
// 	printf("org: %ld\n", strcspn(str1, str2));
// 	return (0);
// }



// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);