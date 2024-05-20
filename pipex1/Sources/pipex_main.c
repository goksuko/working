/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:36:47 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/20 17:27:10 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	do_child_process(char *argv[], char **envp, int pipefd[])
{
	int	infile;

	close(pipefd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
		perror("pipex: do child process\n");
		// it will write the error message to the standard error output with the beginning of the start message we wroter
		// use perror only for fucntions that are not done by you
		// ft_exit_str_fd(1, "Infile error\n", 2);
	dup2(pipefd[1], STDOUT_FILENO);
	// after nowon STDOUT will send its output to pipefd[1]
	close(pipefd[1]);
	// pipefd[1] is closed because we do not need it anymore
	dup2(infile, STDIN_FILENO);
	close(infile);
	start_exec(argv[2], envp);
	// do not close after execve because you will not return here later on
}

// void	do_parent_process(char *argv[], char **envp, int pipefd[])
//  I only changed the name of old parent process
void	do_second_child_process(char *argv[], char **envp, int pipefd[])
{
	int	outfile;

	close(pipefd[1]);
	outfile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (outfile < 0)
		ft_exit_str_fd(1, "Outfile error\n", 2);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipefd[0]);
	close(outfile);
	start_exec(argv[3], envp);
}

void	pipex(char *argv[], char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	pid2;
	int 	status;
	int err;

	status = 0;
	if (pipe(pipefd) == -1)
	{
		err = errno;
		char * error_str = strerror(err);
		printf("%s\n", error_str);
	}
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
