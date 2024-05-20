/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:34:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/21 00:42:46 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	*free_matrix(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	if (string)
	{
		free(string);
		string = NULL;
	}
	return (NULL);
}

void	start_exec(t_pipex *info, char **argv, char **envp)
{
	char	**cmd;
	char	*path;
	char	*long_command;

	path = NULL;
	long_command = argv[info->curr_cmd];
	if (long_command[0] == ' ')
	{
		close(info->pipefd[0]);
		close(info->pipefd[1]);
		close(info->fd_in);
		close(info->fd_out);
		free(info);
		ft_exit_str_fd(127, "zsh: command not found: \n", 2);
	}
	cmd = ft_split(long_command, ' ');
	if (cmd[0])
		path = find_path(cmd[0], envp);
	else
	{
		close(info->pipefd[0]);
		close(info->pipefd[1]);
		close(info->fd_in);
		close(info->fd_out);
		free_matrix(cmd);
		free(info);
		ft_exit_str_fd(1, "zsh: permission denied: \n", 2);
	}
	if (!path)
	{
		close(info->pipefd[0]);
		close(info->pipefd[1]);
		close(info->fd_in);
		close(info->fd_out);
		ft_putstr3_fd("zsh: not a directory: ", cmd[0], "\n", 2);
		free_matrix(cmd);
		free(info);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		close(info->pipefd[0]);
		close(info->pipefd[1]);
		close(info->fd_in);
		close(info->fd_out);
		free_matrix(cmd);
		free(info);
		ft_exit_perror(1, "Error executing command");
	}
}

char	*put_main_command(char *command, char space)
{
	char	*temp;
	int		i;

	i = 0;
	while (command[i] != space && command[i] != '\0')
		i++;
	temp = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (command[i] != space && command[i] != '\0')
	{
		temp[i] = command[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
