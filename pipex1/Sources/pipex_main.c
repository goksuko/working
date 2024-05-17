/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:36:47 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/17 23:13:39 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	do_child_process(char *argv[], char **envp, int pipefd[])
{
	int		infile;

	close(pipefd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
	{
		perror("Infile error\n");
		exit(1);
	}
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	start_exec(argv[2], envp);
	close(pipefd[1]);
}

void	do_parent_process(char *argv[], char **envp, int pipefd[])
{
	int		outfile;

	close(pipefd[1]);
	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (outfile < 0)
	{
		perror("Outfile error\n");
		exit(1);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	start_exec(argv[3], envp);
	close(pipefd[0]);
}

int	check_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[], char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	int		path_no;

	if (argc != 5)
	{
		perror("Please write 4 arguments!\n1.file1\n2.cmd1\n3.cmd2\n4.file2\n");
		return (1);
	}
	path_no = check_path(envp);
	if (envp[path_no] == NULL)
		return (perror("Path not found\n"), 1);
	else
	{
		if (pipe(pipefd) == -1)
			return (perror("Pipe error\n"), 2);
		pid = fork();
		if (pid < 0)
			return (perror("Fork error\n"), 3);
		else if (pid == 0)
			do_child_process(argv, envp, pipefd);
		waitpid(pid, NULL, 0);
		do_parent_process(argv, envp, pipefd);
	}
	return (0);
}
