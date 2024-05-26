/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/26 18:29:30 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/26 23:42:36 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

char *status_strs(t_action status)
{
	static char	*str[] = {
	[THINKING] = "is thinking",
	[DIED] = "died",
	[SLEEPING] = "is sleeping",
	[EATING] = "is eating",
	[FORK] = "has taken a fork"};
	return (str[status]);
}

// gettimeofday: gets the system's clock time
// the current time is expressed in elapsed seconds and microseconds
// since 00:00:00, January 1, 1970 (Unix Epoch)

// tv_sec is seconds
// tv_usec is microseconds
// tv is timeval (with tv_sec and tv_usec)
// tz is timezone

// 1 sec = hundred thousand (100 000) microseconds
// 1 sec = thousand (1000) milliseconds

int	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (EXIT_FAILURE);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void print_status(t_philo *philo, t_action status)
{
	ft_printf("hello\n");
	pthread_mutex_lock(philo->print_lock);
	ft_printf("mutex locked\n");
	ft_printf("%d %d %s\n", get_current_time(), philo->index + 1, status_strs(status));
	pthread_mutex_unlock(philo->print_lock);
}