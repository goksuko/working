#include <stdio.h>

int take_num(char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (str[i] != 0)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

int main(int argc, char *argv[])
{
	int nb;
	int i;
	int j;
	int w;

	w = 0;
	i = 2;
	j = 0;
	if (argc == 2)
	{
		nb = take_num(argv[1]);
		if (nb == 1)
			printf("1");
		while (nb >= i)
		{
			if (j != 0)
				i = j;
			if (nb % i == 0)
			{
				if (w == 1)
					printf("*");
				printf("%d", i);
				w = 1;
				j = i;
				nb = nb / i;
			}
			else
				j = 0;
			i++;
		}
	}
	printf("\n");
	return (0);
}


// Assignment name  : fprime
// Expected files   : fprime.c
// Allowed functions: printf, atoi
// --------------------------------------------------------------------------------

// Write a program that takes a positive int and displays its prime factors on the
// standard output, followed by a newline.

// Factors must be displayed in ascending order and separated by '*', so that
// the expression in the output gives the right result.

// If the number of parameters is not 1, simply display a newline.

// The input, when there is one, will be valid.

// Examples:

// $> ./fprime 225225 | cat -e
// 3*3*5*5*7*11*13$
// $> ./fprime 8333325 | cat -e
// 3*3*5*5*7*11*13*37$
// $> ./fprime 9539 | cat -e
// 9539$
// $> ./fprime 804577 | cat -e
// 804577$
// $> ./fprime 42 | cat -e
// 2*3*7$
// $> ./fprime 1 | cat -e
// 1$
// $> ./fprime | cat -e
// $
// $> ./fprime 42 21 | cat -e
// $