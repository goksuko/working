/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   13_semaphores_login_que.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/05 11:02:45 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/07/05 12:52:57 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


//semaphores can be used to synchronize threads, but they can also be used to synchronize processes.
//the difference from mutex_lock:
// in mutex lock should be opened from the same process/thread, 
// but in semaphore, it can be opened from different processes/threads.

//wait and post are the functions that are used to open and close the semaphore.
//WAIT WITH ME s--
//I AM DONE, POST IT! s++
//wait is like lock, and post is unlock

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>

#define THREAD_NUM 16

sem_t semaphore; // an unsigend integer value, that is used to control the access to a shared resource.

void *thread_function(void *arg)
{
	printf("[%d] is waiting in the queue\n", *(int * )arg);
	sem_wait(&semaphore);
	printf("\033[32m[%d] is logged in\n\033[0m", *(int * )arg);
	sleep(rand() % 5 + 1);
	printf("\033[31m[%d] is logged out\n\033[0m", *(int * )arg);
	sem_post(&semaphore);
	free(arg);
}

int main(int argc, char *argv[])
{
	pthread_t threads[THREAD_NUM];
	int i;

	sem_init(&semaphore, 0, 5);

	//if there is only multiple threads in the 1 same process, pshared = 0;
	//if there is multiple processes, they have multiple threads, pshared = 1;

	//initial value of the semaphore is 1, so it is open.

	for (i = 0; i < THREAD_NUM; i++)
	{
		int *a = malloc(sizeof(int));
		*a = i;		
		if (pthread_create(&threads[i], NULL, &thread_function, a) != 0)
		{
			perror("Failed to create thread");
			return (1);
		}
	}

	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			perror("Failed to join thread");
			return (2);
		}
	}

	sem_destroy(&semaphore);
	return (0);
	
}


// T0	.	W 	.	P	.	.	.	
// T1	.	.	.	.	W	.	.
// T2	.	.	W	.	.	P	.	
// T3	.	.	.	.	.	.	W	
// SEM	2	1	0	1	0	1	0

