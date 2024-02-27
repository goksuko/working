#include <unistd.h>
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

int	is_prime(int num)
{
	int	i;

	i = 3;
	if (num <= 1)
		return (0);
	if (num % 2 == 0 && num > 2)
		return(0);
	while (i < (num / 2))
	{
		if (num % i == 0)
			return (0);
		else
			i += 2;
	}
	return (1);
}

void	print_num(int num)
{
	char c;

	if (num >= 10)
		print_num(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char *argv[])
{
	int	num;
	int	total;

	total = 0;
	if (argc == 2)
	{
		num = take_num(argv[1]);
		total = 0;
		if (num > 0)
		{
			while (num > 0)
			{
				if (is_prime(num))
					total += num;
				num--;
			}
			print_num(total);
			write(1, "\n", 1);
		}
		else
			write(1, "0\n", 2);
	}
	else
		write(1, "0\n", 2);
	// printf("is_prime(0) = %d\n", is_prime(0));
	// printf("is_prime(1) = %d\n", is_prime(1));
	// printf("is_prime(2) = %d\n", is_prime(2));
	// printf("is_prime(3) = %d\n", is_prime(3));
	// printf("is_prime(4) = %d\n", is_prime(4));
	// printf("is_prime(5) = %d\n", is_prime(5));
	// printf("is_prime(6) = %d\n", is_prime(6));
	// printf("is_prime(7) = %d\n", is_prime(7));
	return (0);
}


// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>
