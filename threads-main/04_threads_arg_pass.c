#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int				array[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
pthread_mutex_t	mutex;

void	*write_prime(void *i_value)
{
	int	*ptr_prime;
	int	i;

	i = *(int *)i_value;
	pthread_mutex_lock(&mutex);
	ptr_prime = malloc(sizeof(int));
	if (ptr_prime == NULL)
		return (NULL);
	*ptr_prime = array[i];
	printf("We are at thread %d => array[%d]: %d\n", i, i, *ptr_prime);
	pthread_mutex_unlock(&mutex);
	return ((void *)ptr_prime);
}

void	*routine(void *arg)
{
	int	index;

	// sleep(10);
	index = *(int *)arg;
	printf("We are at thread %d => array[%d]: %d\n", index, index,
		array[index]);
	free(arg);
	return (NULL);
}

// int	main(void)
// {
// 	pthread_t	th[10];

// 	// pthread_mutex_init(&mutex, NULL);
// 	for (int i = 0; i < 10; i++)
// 	{
// 		if (pthread_create(&th[i], NULL, &routine, &i) != 0)
// 		{
// 			printf("Error creating thread %d\n", i);
// 			return (i);
// 		}
// 		printf("Thread %d has started\n", i);
// 		if (pthread_join(th[i], NULL) != 0)
// 		{
// 			printf("Error joining thread %d\n", i);
// 			return (i + 4);
// 		}
// 		printf("Thread %d finished execution\n", i);
// 	}
// 	// pthread_mutex_destroy(&mutex);
// 	return (0);
// }

int	main(void)
{
	pthread_t th[10];
	int *result;
	void *ptr;

	pthread_mutex_init(&mutex, NULL);

	for (int i = 0; i < 10; i++)
	{
		ptr = malloc(sizeof(int));
		if (ptr == NULL)
			return (1);
		*(int *)ptr = i;
		if (pthread_create(&th[i], NULL, (void *)&write_prime, ptr) != 0)
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
		free(result);
	}

	pthread_mutex_destroy(&mutex);

	return (0);
}