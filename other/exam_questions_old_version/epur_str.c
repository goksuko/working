#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*org;
	int		i;
	int		j;
	int		t;

	i = 0;
	j = 0; //is there anything written yet?
	t = 0; //is there a tab or space?
	org = argv[1];
	if (argc ==2)
	{
		while (org[i] != '\0')
		{
			if (org[i] == ' ' || org[i] == '\t')
				t = 1;
			else
			{
				if (j == 1 && t == 1)
					write (1, " ", 1);
				j = 1;
				t = 0;
				write (1, &org[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// Assignment name  : epur_str
// Expected files   : epur_str.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string, and displays this string with exactly one
// space between words, with no spaces or tabs either at the beginning or the end,
// followed by a \n.

// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.

// If the number of arguments is not 1, or if there are no words to display, the
// program displays \n.

// Example:

// $> ./epur_str "See? It's easy to print the same thing" | cat -e
// See? It's easy to print the same thing$
// $> ./epur_str " this        time it      will     be    more complex  . " | cat -e
// this time it will be more complex .$
// $> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
// $
// $> ./epur_str "" | cat -e
// $
// $>

// $> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
// vous voyez c'est facile d'afficher la meme chose$
// $> ./epur_str " seulement          la c'est      plus dur " | cat -e
// seulement la c'est plus dur$
// $> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
// $
// $> ./epur_str "" | cat -e
// $
// $>
