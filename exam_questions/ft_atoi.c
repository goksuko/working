// #include <stdio.h>

// int	ft_atoi(const char *str)
// {
// 	int	sign;
// 	int	i;
// 	int	nb;

// 	nb = 0;
// 	i = 0;
// 	sign = 1;
// 	if (str[0] == '-' || str[0] == '+')
// 	{
// 		if (str[0] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i])
// 	{
// 		nb = nb * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (nb * sign);
// }

// // int main()
// // {
// // 	printf("%d\n", ft_atoi("-016"));
// // 	return (0);
// // }

// // Assignment name  : ft_atoi
// // Expected files   : ft_atoi.c
// // Allowed functions: None
// // --------------------------------------------------------------------------------

// // Write a function that converts the string argument str to an integer (type int)
// // and returns it.

// // It works much like the standard atoi(const char *str) function, see the man.

// // Your function must be declared as follows:

// // int	ft_atoi(const char *str);
