#include <unistd.h>

int main(int argc, char *argv[])
{
	char c;
	int n;
	char *str;
	int i;

	i = 0;
	if (argc == 2)
	{
		str = argv[1];
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				c = str[i];
				n = (int)(c - 'a');
				while (n--)
					write(1, &str[i], 1);
			}
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				c = str[i];
				n = (int)(c - 'A');
				while (n--)
					write(1, &str[i], 1);
			}
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


// Assignment name  : repeat_alpha
// Expected files   : repeat_alpha.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called repeat_alpha that takes a string and display it
// repeating each alphabetical character as many times as its alphabetical index,
// followed by a newline.

// 'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

// Case remains unchanged.

// If the number of arguments is not 1, just display a newline.

// Examples:

// $>./repeat_alpha "abc"
// abbccc
// $>./repeat_alpha "Alex." | cat -e
// Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
// $>./repeat_alpha 'abacadaba 42!' | cat -e
// abbacccaddddabba 42!$
// $>./repeat_alpha | cat -e
// $
// $>
// $>./repeat_alpha "" | cat -e
// $
// $>