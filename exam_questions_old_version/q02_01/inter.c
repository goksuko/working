#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int array[255] = {0};
	int i;
	char	*first;
	char	*second;

	first = NULL;
	second = NULL;
	if (argc == 3)
	{
		first = argv[1];
		second = argv[2];
		i = 0;
		while (second[i])
		{
			array[(int)second[i]] = 1;
			i++;
		}
		i = 0;
		while (first[i])
		{
			if (array[(int)first[i]] == 1)
			{
				write(1, &first[i], 1);
				array[(int)first[i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}




// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $
