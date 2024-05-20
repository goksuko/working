/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:36:47 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/20 22:27:18 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	do_child_process(char *argv[], char **envp, int pipefd[])
{
	int	infile;

	close(pipefd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
		ft_exit_perror(1, "infile opening error");
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	dup2(infile, STDIN_FILENO);
	close(infile);
	start_exec(argv[2], envp);
}

void	do_second_child_process(char *argv[], char **envp, int pipefd[])
{
	int	outfile;

	close(pipefd[1]);
	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (outfile < 0)
		ft_exit_perror(1, "outfile opening error");
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	start_exec(argv[3], envp);
}

void	pipex(char *argv[], char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	pid2;
	int 	status;

	status = 0;
	if (pipe(pipefd) == -1)
		ft_exit_perror(1, "Pipe error");
	pid = fork();
	if (pid < 0)
		ft_exit_perror(1, "First fork error");
	else if (pid == 0)
		do_child_process(argv, envp, pipefd);
	pid2 = fork();
	if (pid2 < 0)
		ft_exit_perror(1, "Second fork error");
	else if (pid2 == 0)
		do_second_child_process(argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid2, &status, 0);
	wait(NULL);
	exit(WEXITSTATUS(status));
}

void	command_not_found(char *argv[])
{
	char	*cmd_1;
	char	*cmd_2;

	cmd_1 = put_main_command(argv[2], ' ');
	cmd_2 = put_main_command(argv[3], ' ');
	ft_putstr2_fd("zsh: command not found: ", cmd_1, STDERR_FILENO);
	ft_putstr3_fd("\nzsh: command not found: ", cmd_2, "\n", STDERR_FILENO);
	free(cmd_1);
	free(cmd_2);
	exit(127);
}

int	main(int argc, char *argv[], char **envp)
{
	int		path_no;

	if (argc != 5)
		return (ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO), 1);
	path_no = check_path(envp);
	if (envp[path_no] == NULL)
		return (ft_putstr_fd("zsh: path not found\n", STDERR_FILENO), 1);
	if (path_no == 0)
		return (command_not_found(argv), 127);
	else
		pipex(argv, envp);
	return (0);
}
