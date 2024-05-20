/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strerror.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/20 22:05:34 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/20 22:07:51 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	int pipefd[2];
	int err;
	char *error_str;

	error_str = NULL;

	if (pipe(pipefd) == -1)
	{
		err = errno;
		error_str = strerror(err);
		printf("%s\n", error_str);
		return (1);
	}
	else
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (0);
	}
}