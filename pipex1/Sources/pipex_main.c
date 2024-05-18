/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:36:47 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/18 23:43:35 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	do_child_process(char *argv[], char **envp, int pipefd[])
{
	int	infile;

	close(pipefd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
		ft_exit_str_fd(1, "Infile error\n", 2);
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	start_exec(argv[2], envp);
	close(pipefd[1]);
}

void	do_parent_process(char *argv[], char **envp, int pipefd[])
{
	int	outfile;

	close(pipefd[1]);
	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (outfile < 0)
		ft_exit_str_fd(1, "Outfile error\n", 2);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	start_exec(argv[3], envp);
	close(pipefd[0]);
}

void	pipex(char *argv[], char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		ft_exit_str_fd(1, "Pipe error\n", 2);
	pid = fork();
	if (pid < 0)
		ft_exit_str_fd(1, "Fork error\n", 2);
	else if (pid == 0)
		do_child_process(argv, envp, pipefd);
	waitpid(pid, NULL, 0);
	do_parent_process(argv, envp, pipefd);
}

void	command_not_found(char *argv[])
{
	char	*cmd_1;
	char	*cmd_2;

	cmd_1 = put_main_command(argv[2], ' ');
	cmd_2 = put_main_command(argv[3], ' ');
	ft_putstr2_fd("zsh: command not found: ", cmd_1, 2);
	ft_putstr3_fd("\nzsh: command not found: ", cmd_2, "\n", 2);
	free(cmd_1);
	free(cmd_2);
	exit(127);
}

int	main(int argc, char *argv[], char **envp)
{
	int		path_no;

	if (argc != 5)
		return (ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2), 1);
	path_no = check_path(envp);
	if (envp[path_no] == NULL)
		return (ft_putstr_fd("zsh: path not found\n", 2), 1);
	if (path_no == 0)
		return (command_not_found(argv), 127);
	else
		pipex(argv, envp);
	return (0);
}
