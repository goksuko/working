#include <unistd.h>
#include <stdio.h>

// beter solution
// int	main(int ac, char **av)
// {
// 	int	i;

// 	i = 0;
// 	if (ac == 2)
// 	{
// 		while (av[1][i] != '\0')
// 			i++;
// 		i--;
// 		while ((av[1][i] == ' ' || av[1][i] == '\t') && i != 0)
// 			i--;	
// 		while (av[1][i] != ' ' && av[1][i] != '\t'  && i != 0)
// 			i--;
// 		if (av[1][i] == ' ' || av[1][i] == '\t')
// 			i++;
// 		while (av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
// 		{	
// 			write(1, &av[1][i], 1);
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// }

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_if_space(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
		else
			i++;
	}
	return (0);
}

int	last_pos_from_back(char *str)
{
	int	length;

	length = ft_strlen(str);
	while(length > 1)
	{
		// printf("str[%d]: .%c.\n", length - 1, str[length - 1]);
		if (str[length - 1] == ' ' || str[length - 1] == '\t')
			length--;
		else
			return (length - 1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		start;
	int		i;
	int		last;
	int		temp;

	i = 0;
	start = 0;
	temp = 0;
	if (argc == 2)
	{
		str = argv[1];
		last = last_pos_from_back(str);
		// printf("last: %d\n", last);
		if (check_if_space(str))
		{
			while (str[i])
			{
				if (str[i] == ' ' || str[i] == '\t')
				{
					start = i + 1;
					// printf("start: %d\n", start);
				}
				if (start >= last)
					break;
				else
				{
					temp = start;
					// printf("temp: %d\n", temp);
				}
				i++;
			}
		}
		while (str[temp] != ' ' && str[temp] != '\t' && str[temp] != '\0')
		{
			write(1, &str[temp], 1);
			temp++;
		}
	}
	write(1, "\n", 1);
	return (0);
}



// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>
