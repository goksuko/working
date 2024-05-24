#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// if I use rand() without srand() it will always generate the same numbers

// srand changes the seed of the random number generator
// srand(1) is a common seed to use for testing

int	main(void)
{
	int *random_numbers;
	int i;
	time_t seconds_from_epoch;

	// time function returns the current time of the system as a time_t value and saves it in a pointer
	seconds_from_epoch = time(NULL);

	srand(seconds_from_epoch);
	random_numbers = (int *)malloc(10 * sizeof(int));
	if (random_numbers == NULL)
		return (1);
	for (i = 0; i < 10; i++)
		random_numbers[i] = rand();
	for (i = 0; i < 10; i++)
		printf("%d\n", random_numbers[i]);
	free(random_numbers);
	return (0);
}