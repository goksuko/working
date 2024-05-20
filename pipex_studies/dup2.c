/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dup2.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/20 22:08:58 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/20 22:10:46 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void	do_child_process(char *argv[], char **envp, int pipefd[])
{
	int	infile;

	close(pipefd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
		perror("pipex: do child process\n");
		// it will write the error message to the standard error output with the beginning of the start message we wroter
		// use perror only for fucntions that are not done by you
	dup2(pipefd[1], STDOUT_FILENO);
	// after nowon STDOUT will send its output to pipefd[1]
	close(pipefd[1]);
	// pipefd[1] is closed because we do not need it anymore
	dup2(infile, STDIN_FILENO);
	close(infile);
	// do not close after execve because you will not return here later on
	start_exec(argv[2], envp); //inside execve
	// execve takes everything and if compiles, finishes it and frees everything left
}