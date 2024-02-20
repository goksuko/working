#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int ft_atoi(char *str)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

void ft_putnbr(int nb)
{
	char c;
	
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

// int find_digit(char *str)
// {
// 	int	i;
	
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

int main(int argc, char *argv[])
{
	int	nb;
	char *str;
	char letter;
	int nine;

	if (argc == 2)
	{
		str = argv[1];
		nb = ft_atoi(str);
		nine = 1;
		if (nb <= INT_MAX / 9)
		{
			while (nine <= 9)
			{
				letter = nine + '0';
				write(1, &letter, 1);
				write(1, " x ", 3);
				ft_putnbr(nb);
				write(1, " = ", 3);
				ft_putnbr(nine * nb);
				write(1, "\n", 1);
				nine++;
			}
		}
		else
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}

// int main()
// {
// 	ft_putnbr(12345);
// 	return (0);
// }


// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>
