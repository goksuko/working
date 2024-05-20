/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wait_waitpid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/20 22:10:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/20 22:12:04 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

void	pipex(char *argv[], char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	pid2;
	int 	status;
	int err;

	status = 0;
	if (pipe(pipefd) == -1)
		ft_exit_str_fd(1, "Pipe error\n", 2);
	pid = fork();
	if (pid < 0)
		ft_exit_str_fd(1, "Fork error\n", 2);
	else if (pid == 0)
		do_child_process(argv, envp, pipefd);
	pid2 = fork();
	if (pid2 < 0)
		ft_exit_str_fd(1, "Fork error\n", STDERR_FILENO);
	else if (pid2 == 0)
		do_second_child_process(argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	// waitpid(pid, NULL, 0); we do not have to wait for first child process 
	// because it eventually will be waited by the second child process because of the pipe
	waitpid(pid2, &status, 0);
	wait(NULL);  // parent process waits for all the child processes to be finished
	// this can either be done with wait(NULL) or waitpid for all the child processes
	exit(WEXITSTATUS(status));
}