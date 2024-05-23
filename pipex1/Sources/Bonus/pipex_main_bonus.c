/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_main_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:36:47 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/23 22:31:00 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

pid_t	child_process(t_pipex *info, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close_pipex(info, NULL);
		ft_exit_perror(1, "Fork error");
	}
	if (pid == 0)
	{
		if (info->curr_cmd == 2)
		{
			if(dup2(info->fd_in, STDIN_FILENO) == -1)
				ft_exit_perror(1, "dup2 for infile in child process");
			close(info->fd_in);
		}
		close(info->pipefd[0]);
		if(dup2(info->pipefd[1], STDOUT_FILENO) == -1)
			ft_exit_perror(1, "dup2 for pipefd in child process");
		close(info->pipefd[1]);
		start_exec(info, argv, envp);
	}
	return (pid);
}

pid_t	last_child_process(t_pipex *info, char **argv, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit_perror(1, "Fork error");
	if (pid == 0)
	{
		close(info->pipefd[1]);
		if(dup2(info->pipefd[0], STDIN_FILENO) == -1)
			ft_exit_perror(1, "dup2 for pipefd in last child process");
		close(info->pipefd[0]);
		if(dup2(info->fd_out, STDOUT_FILENO) == -1)
			ft_exit_perror(1, "dup2 for outfile in last child process");
		close(info->fd_out);
		start_exec(info, argv, envp);
	}
	return (pid);
}

int	create_children(t_pipex *info, char *argv[], char **envp)
{
	int		i;
	pid_t	pid;
	pid_t	pid_last;
	int		status;

	i = 1;
	while (i < info->nbr_of_cmds)
	{
		if (pipe(info->pipefd) == -1)
			ft_close_exit_perror(info, NULL, 1, "Pipe error");
		pid = child_process(info, argv, envp);
		close(info->pipefd[1]);
		dup2(info->pipefd[0], STDIN_FILENO);
		close(info->pipefd[0]);
		info->curr_cmd++;
		i++;
	}
	pid_last = last_child_process(info, argv, envp);
	while (waitpid(pid, &status, 0) != -1)
		;
	waitpid(pid_last, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

void	initialize_info(t_pipex *info, char *argv[], int argc)
{
	info->fd_in = open(argv[1], O_RDONLY, 0777);
	if (info->fd_in < 0)
	{
		free(info);
		ft_exit_perror(1, "infile opening error");
	}
	info->fd_out = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (info->fd_out < 0)
	{
		close(info->fd_in);
		free(info);
		ft_exit_perror(1, "outfile opening error");
	}
	info->nbr_of_cmds = argc - 3;
	info->curr_cmd = 2;
}

int	main(int argc, char *argv[], char **envp)
{
	int		path_no;
	t_pipex	*info;
	int		exit_code;

	if (argc < 5)
	{
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO);
		return (1);
	}
	info = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (info == NULL)
		ft_exit_perror(1, "Malloc error");
	initialize_info(info, argv, argc);
	path_no = check_path(envp);
	if (envp[path_no] == NULL)
		return (ft_putstr_fd("zsh: path not found\n", STDERR_FILENO), 1);
	if (path_no == 0)
		return (command_not_found(argv), 127);
	exit_code = create_children(info, argv, envp);
	if (exit_code != 0)
		return (free(info), exit_code);
	free(info);
	return (0);
}
