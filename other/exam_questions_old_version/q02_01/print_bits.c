#include <unistd.h>
#include <stdio.h>

// This is also nice
// void print_bits(unsigned char octet)
// {
// 	int div = 128;
// 	int num = octet;

// 	while (div != 0)
// 	{
// 		if (div <= num)
// 		{
// 			write(1, "1", 1);
// 			num = num % div;
// 		}
// 		else
// 			write(1, "0", 1);
// 		div = div / 2;
// 	}
// }

// also this 
// void print_bits(unsigned char octet)
// {
// 	int	i;
// 	unsigned char bit;

// 	i = 8;
// 	while (i--)
// 	{
// 		bit = (octet >> i & 1) + '0';
// 		write(1, &bit, 1);
// 	}
// }

void	print_bits(unsigned char octet)
{
	int	i;
	int	digit;
	int	nb;
	char str[9];

	i = (int)octet - '0';
	digit = 8;
	nb = i;
	while (digit--)
	{
		nb = i % 2;
		str[digit - 1] = nb + '0';
		i /= 2;
	}
	str[8] = '\0';
	i = 0;
	while (i < 8)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main()
{
	print_bits('8');
	write(1, "\n",1 );
	return (0);
}


// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void	print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"