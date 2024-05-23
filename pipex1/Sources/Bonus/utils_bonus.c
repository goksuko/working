/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:34:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/23 22:16:12 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

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

void	close_pipex(t_pipex *info, char **matrix)
{
	close(info->pipefd[0]);
	close(info->pipefd[1]);
	close(info->fd_in);
	close(info->fd_out);
	free(info);
	if (matrix)
		free_matrix(matrix);
}

char	*before_exec(char *long_command, t_pipex *info, char **cmd, char **envp)
{
	char	*path;

	path = NULL;
	if (long_command[0] == ' ')
	{
		close_pipex(info, cmd);
		ft_exit_str_fd(127, "zsh: not a directory: \n", 2);
	}
	if (cmd[0])
		path = find_path(cmd[0], envp);
	else
	{
		close_pipex(info, cmd);
		ft_exit_str_fd(1, "zsh: permission denied: \n", 2);
	}
	if (!path)
	{
		ft_putstr3_fd("zsh: command not found: ", cmd[0], "\n", 2);
		close_pipex(info, cmd);
		exit(127);
	}
	return (path);
}

void	start_exec(t_pipex *info, char **argv, char **envp)
{
	char	**cmd;
	char	*path;
	char	*long_command;

	path = NULL;
	long_command = argv[info->curr_cmd];
	cmd = ft_split(long_command, ' ');
	path = before_exec(long_command, info, cmd, envp);
	if (execve(path, cmd, envp) == -1)
	{
		close_pipex(info, cmd);
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
