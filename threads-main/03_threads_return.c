#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int				total_value;
pthread_mutex_t	mutex;

void	*roll_dice(void)
{
	int	value;
	int	*ptr_value;

	value = (rand() % 6) + 1;
	printf("* dice value: %d\n", value);
	pthread_mutex_lock(&mutex);
	ptr_value = malloc(sizeof(int));
	total_value += value;
	*ptr_value = total_value;
	// printf("dice value in total: %d\n", *ptr_value);
	pthread_mutex_unlock(&mutex);
	return ((void *)ptr_value);
}

int	main(void)
{
	pthread_t th[2];
	int *result;

	pthread_mutex_init(&mutex, NULL);

	for (int i = 0; i < 2; i++)
	{
		srand(time(NULL) * (i + 1));
		if (pthread_create(&th[i], NULL, (void *)&roll_dice, NULL) != 0)
		{
			printf("Error creating thread %d\n", i);
			return (i);
		}
		printf("Thread %d has started\n", i);
		if (pthread_join(th[i], (void **)&result) != 0)
		{
			printf("Error joining thread %d\n", i);
			return (i + 4);
		}
		printf("Thread %d finished execution\n", i);
		if (i == 1)
			printf("** total value: %d\n", *result);
		free(result);
	}

	pthread_mutex_destroy(&mutex);

	return (0);
}