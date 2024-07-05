#include <stdio.h>
#include <pthread.h>

# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"

// JOIN

// In order to block the execution of a thread until another thread finishes,
// we can use the pthread_join function.

// int pthread_join(pthread_t thread, void **retval);

// thread: the ID of the thread that this thread should wait for. 
// The specified thread must be joinable (meaning not detached – see below).
// retval: a pointer towards a variable that can contain the return value 
// of the thread’s routine function 

// DETACH

// But in some cases, it is possible and preferable to not wait for 
// the end of certain theads at all. In that case, we can detach the thread 
// to tell the operating system that it can reclaim its resources right away 
// when it finishes its execution. For that, we use the 
// pthread_detach function (usually right after that thread’s creation).

// int pthread_detach(pthread_t thread);

//////////////////////////////////////////////////////////////////////////////////

// thread_routine is the function the thread invokes right after its
// creation. The thread ends at the end of this function.
void	*thread_routine(void *data)
{
	pthread_t tid;

	// The pthread_self() function provides
	// this thread's own ID.
	tid = pthread_self();
	printf("%sThread [%ld]: The heaviest burden is to exist without living.%s\n",
		YELLOW, tid, NC);
	return (NULL); // The thread ends here.
}

int	main(void)
{
	pthread_t	tid1;	// First thread's ID
	pthread_t	tid2;	// Second thread's ID

	// Creating the first thread that will go
	// execute its thread_routine function.
	pthread_create(&tid1, NULL, thread_routine, NULL);
	printf("Main: Created first thread [%ld]\n", tid1);
	// Creating the second thread that will also execute thread_routine.
	pthread_create(&tid2, NULL, thread_routine, NULL);
	printf("Main: Created second thread [%ld]\n", tid2);
	// The main thread waits for the new threads to end
	// with pthread_join.
	pthread_join(tid1, NULL);
	printf("Main: Joining first thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Joining second thread [%ld]\n", tid2);
	return (0);
}