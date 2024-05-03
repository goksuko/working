#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int		result;
	int		n1;
	int		n2;
	char	*num1;
	char	oper;
	char	*num2;

	if (argc == 4)
	{
		num1 = argv[1];
		oper = argv[2][0];
		num2 = argv[3];
		n1 = atoi(num1);
		n2 = atoi(num2);
		if (oper == '+')
			result = n1 + n2;
		else if (oper == '-')
			result = n1 - n2;
		else if (oper == '*')
			result = n1 * n2;
		else if (oper == '/')
			result = n1 / n2;
		else if (oper == '%')
			result = n1 % n2;
		printf("%d", result);
	}
	write (1, "\n", 1);
	return (0);
}


// Assignment name  : do_op
// Expected files   : do_op.c
// Allowed functions: atoi, printf, write
// --------------------------------------------------------------------------------

// Write a program that takes three strings:
// - The first and the third one are representations of base-10 signed integers
//   that fit in an int.
// - The second one is an arithmetic operator chosen from: + - * / %

// The program must display the result of the requested arithmetic operation,
// followed by a newline. If the number of parameters is not 3, the program
// just displays a newline.

// You can assume the string have no mistakes or extraneous characters. Negative
// numbers, in input or output, will have one and only one leading '-'. The
// result of the operation fits in an int.

// Examples:

// $> ./do_op "123" "*" 456 | cat -e
// 56088$
// $> ./do_op "9828" "/" 234 | cat -e
// 42$
// $> ./do_op "1" "+" "-43" | cat -e
// -42$
// $> ./do_op | cat -e
// $
