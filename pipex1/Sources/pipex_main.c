/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:36:47 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/18 18:07:19 by akaya-oz      ########   odam.nl         */
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
		ft_putstr_fd("Infile error\n", 2);
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
		ft_putstr_fd("Outfile error\n", 2);
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
	char	*cmd_1;
	char	*cmd_2;

	cmd_1 = NULL;
	cmd_2 = NULL;
	if (argc != 5)
	{
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	path_no = check_path(envp);
	if (envp[path_no] == NULL)
		return (ft_putstr_fd("Path B not found\n", 2), 1);
	if (path_no == 0)
	{
		cmd_1 = put_main_command(argv[2], ' ');
		cmd_2 = put_main_command(argv[3], ' ');
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putstr_fd(cmd_1, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putstr_fd(cmd_2, 2);
		ft_putstr_fd("\n", 2);
		free(cmd_1);
		free(cmd_2);
		return (127);
	}
	else
	{
		if (pipe(pipefd) == -1)
			return (ft_putstr_fd("Pipe error\n", 2), 2);
		pid = fork();
		if (pid < 0)
			return (ft_putstr_fd("Fork error\n", 2), 3);
		else if (pid == 0)
			do_child_process(argv, envp, pipefd);
		waitpid(pid, NULL, 0);
		do_parent_process(argv, envp, pipefd);
	}
	return (0);
}
