#include <unistd.h>
// #include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	char *org;
	char c;

	i = 0;
	org = argv[1];
	if (argc == 2)
	{
		while (org[i])
		{
			if(org[i] >= 'a' && org[i] <= 'z')
				write(1, &org[i], 1);
			if (org[i] >= 'A' && org[i] <= 'Z')
			{
				c = org[i] + 32;
				write(1, "_", 1);
				write(1, &c, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// // Assignment name  : camel_to_snake
// // Expected files   : camel_to_snake.c
// // Allowed functions: malloc, free, realloc, write
// // --------------------------------------------------------------------------------

// // Write a program that takes a single string in lowerCamelCase format
// // and converts it into a string in snake_case format.

// // A lowerCamelCase string is a string where each word begins with a capital letter
// // except for the first one.

// // A snake_case string is a string where each word is in lower case, separated by
// // an underscore "_".

// // Examples:
// // $>./camel_to_snake "hereIsACamelCaseWord"
// // here_is_a_camel_case_word
// // $>./camel_to_snake "helloWorld" | cat -e
// // hello_world$
// // $>./camel_to_snake | cat -e
// // $
