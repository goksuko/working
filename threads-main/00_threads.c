#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int	mails = 0;

void	*my_thread(void)
{
	for (int i = 0; i < 100000; i++)
	// for (int i = 0; i < 1000000; i++)
	{
		mails++;
		// read mails
		// increment
		// write mails
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, my_thread, NULL);
	pthread_create(&thread2, NULL, my_thread, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("mails: %d\n", mails);
	return (0);
}
