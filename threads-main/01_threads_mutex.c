#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int mails = 0;

// int lock = 0;
pthread_mutex_t mutex;

void *my_thread()
{
	for (int i = 0; i < 10000000; i++)
	{
		// if (lock == 1)
		// {
		// 	// wait untill lock is 0
		// }
		// lock = 1;
		pthread_mutex_lock(&mutex);

		mails++;
		//read mails
		//increment
		//write mails

		// lock = 0;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_init(&mutex, NULL);

	if(pthread_create(&thread1, NULL, my_thread, NULL) != 0){
		printf("Error creating thread 1\n");
		return (1);
	}
	if(pthread_create(&thread2, NULL, my_thread, NULL) != 0){
		printf("Error creating thread 2\n");
		return (2);
	}
	if(pthread_join(thread1, NULL) != 0){
		printf("Error joining thread 1\n");
		return (3);
	}
	if(pthread_join(thread2, NULL) != 0){
		printf("Error joining thread 2\n");
		return (4);
	}

	pthread_mutex_destroy(&mutex);

	printf("mails: %d\n", mails);
	return (0);
}
