
#include <limits.h>
#include <stdio.h>

int		max(int* tab, unsigned int len)
{
	int 	max;

	max = INT_MIN;
	if (len == 0)
		return (0);
	while (len--)
	{
		if (tab[len] > max)
			max = tab[len];
	}
	return (max);
}

/*
int	main()
{
	int	array[5] = {};
	printf("%d\n", max(array, 0));
	return (0);
}
*/


/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/