// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>

// int main(int argc, char *argv[])
// {
// 	int i;
// 	int a;
// 	int b;
// 	int wrt;
// 	char **str;

// 	i = 0;
// 	printf("test");
// 	while(argv[1][i])
// 		i++;
// 	str = malloc(sizeof(char) * i + 1);
// 	if (str == NULL)
// 		return 0;
// 	a = 0;
// 	b = 0;
// 	wrt = 0;
// 	printf("test");
// 	if (argc == 2)
// 	{
// 		i = 0;
// 		while(argv[1][i])
// 		{
// 			if (argv[1][i] == ' ')
// 			{
// 				str[a][b] = '\0';
// 				a++;
// 				b = 0;
// 			}
// 			str[a][b] = argv[1][i];
// 			i++;
// 		}
// 		str[a][b] = '\0';
// 		while (a >= 0)
// 		{
// 			b = 0;
// 			while (str[a][b])
// 			{
// 				write(1, &str[a][b], 1);
// 				b++;
// 			}
// 			a--;
// 			if (wrt == 1)
// 				write (1, " ", 1);
// 			wrt = 1;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	free(str);
// 	return (0);
// }





// // Assignment name  : rev_wstr
// // Expected files   : rev_wstr.c
// // Allowed functions: write, malloc, free
// // --------------------------------------------------------------------------------

// // Write a program that takes a string as a parameter, and prints its words in 
// // reverse order.

// // A "word" is a part of the string bounded by spaces and/or tabs, or the 
// // begin/end of the string.

// // If the number of parameters is different from 1, the program will display 
// // '\n'.

// // In the parameters that are going to be tested, there will not be any "additional" 
// // spaces (meaning that there will not be additionnal spaces at the beginning or at 
// // the end of the string, and words will always be separated by exactly one space).

// // Examples:

// // $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
// // ironic? it Isn't gatherings. love I But people! hate You$
// // $>./rev_wstr "abcdefghijklm"
// // abcdefghijklm
// // $> ./rev_wstr "Wingardium Leviosa" | cat -e
// // Leviosa Wingardium$
// // $> ./rev_wstr | cat -e
// // $
// // $>
