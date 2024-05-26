/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:21:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/26 19:21:22 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void	*thread_routine(void *data)
// {
// 	pthread_t tid;

// 	// The pthread_self() function provides
// 	// this thread's own ID.
// 	tid = pthread_self();
// 	printf("Thread [%ld]: The heaviest burden is to exist without living.\n", tid);
// 	return (NULL); // The thread ends here.
// }

// int	main(void)
// {
// 	pthread_t	tid1;	// First thread's ID
// 	pthread_t	tid2;	// Second thread's ID

// 	pthread_create(&tid1, NULL, thread_routine, NULL);
// 	printf("Main: Created first thread [%ld]\n", tid1);
// 	pthread_create(&tid2, NULL, thread_routine, NULL);
// 	printf("Main: Created second thread [%ld]\n", tid2);

// 	pthread_join(tid1, NULL);
// 	printf("Main: Joining first thread [%ld]\n", tid1);
// 	pthread_join(tid2, NULL);
// 	printf("Main: Joining second thread [%ld]\n", tid2);
// 	return (0);
// }

// void	threads_init(t_table *table)
// {
// 	int	i;

// 	i = 0;
// 	while (i < table->NO_OF_PHILOS)
// 	{
// 		if (pthread_create(&table->philo[i].thread, NULL, thread_routine, &table->philo[i]))
// 			ft_exit_perror(ERROR_THREAD, "Thread creation");
// 		i++;
// 	}
// }