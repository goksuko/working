// #include <stdio.h>

// //bence dogru, ayni ciktiyi veriyor ama sistem kabul etmiyor

// int	ft_atoi_base(const char *str, int str_base)
// {
// 	int		sign;
// 	int		i;
// 	int		nb;
// 	char	*digits;
// 	char	*digits2;
// 	int	j;

// 	nb = 0;
// 	i = 0;
// 	sign = 1;
// 	digits = "0123456789abcdef";
// 	digits2 = "0123456789ABCDEF";
// 	if (str[0] == '-' || str[0] == '+')
// 	{
// 		if (str[0] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] && j < 17)
// 	{
// 		j = 0;
// 		while (j < 17)
// 		{
// 			if (str[i] == digits[j] || str[i] == digits2[j])
// 				break ;
// 			j++;
// 		}
// 		if (j == 17)
// 			i++;
// 		else
// 		{
// 			nb = (nb * str_base) + j;
// 			i++;
// 		}
// 	}
// 	return (nb * sign);
// }

// // int main()
// // {
// // 	printf("%d\n", ft_atoi_base("Ceci permet de decouvrir le fonctionnement de ton ft_atoi_base", 16));
// // 	return (0);
// // }

// // Assignment name  : ft_atoi_base
// // Expected files   : ft_atoi_base.c
// // Allowed functions: None
// // --------------------------------------------------------------------------------

// // Write a function that converts the string argument str (base N <= 16)
// // to an integer (base 10) and returns it.

// // The characters recognized in the input are: 0123456789abcdef
// // Those are, of course, to be trimmed according to the requested base. For
// // example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// // Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// // Minus signs ('-') are interpreted only if they are the first character of the
// // string.

// // Your function must be declared as follows:

// // int	ft_atoi_base(const char *str, int str_base);
