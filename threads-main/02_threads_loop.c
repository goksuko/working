#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int				mails = 0;
pthread_mutex_t	mutex;

void	*my_thread(void)
{
	for (int i = 0; i < 1000000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	th[4];

	// pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < 4; i++)
	{
		if (pthread_create(&th[i], NULL, my_thread, NULL) != 0)
		{
			printf("Error creating thread %d\n", i);
			return (i);
		}
		printf("Thread %d has started\n", i);
	}
	for (int i = 0; i < 4; i++)
	{
		if (pthread_join(th[i], NULL) != 0)
		{
			printf("Error joining thread %d\n", i);
			return (i + 4);
		}
		printf("Thread %d finished execution\n", i);
		printf("mails: %d\n", mails);
	}
	// pthread_mutex_destroy(&mutex);
	printf("mails at last: %d\n", mails);
	return (0);
}

//Although the message shows that the execution finished in the order,
//  it does not in the reality. It is this way because of the for loop.
// It writes the result when the thread is finished its execution on the loop.