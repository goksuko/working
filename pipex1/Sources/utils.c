/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:34:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/18 18:07:08 by akaya-oz      ########   odam.nl         */
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

void	start_exec(char *long_command, char **envp)
{
	char	**cmd;
	char	*path;

	if (long_command[0] == ' ')
	{
		ft_putstr_fd("zsh: command not found: \n", 2);
		exit(1);
	}
	cmd = ft_split(long_command, ' ');
	if (cmd[0])
		path = find_path(cmd[0], envp);
	else
	{
		free_matrix(cmd);
		ft_putstr_fd("zsh: permission denied: \n", 2);
		exit(1);
	}
	if (!path)
	{
		ft_putstr_fd("zsh: not a directory: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd("\n", 2);
		free_matrix(cmd);
		exit(1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_matrix(cmd);
		ft_putstr_fd("Error executing command\n", 2);
		exit(1);
	}
}

char	*find_path(char *main_command, char **envp)
{
	char	*path;
	char	**path_split;
	int		i;
	char	*tmp;

	i = 0;
	if (access(main_command, F_OK | X_OK) == 0)
		return (main_command);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_split = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_split[i])
	{
		tmp = ft_strjoin(path_split[i], "/");
		path = ft_strjoin(tmp, main_command);
		free(tmp);
		if (access(path, F_OK | X_OK) == 0)
			return (free_matrix(path_split), path);
		free(path);
		i++;
	}
	free_matrix(path_split);
	return (NULL);
}

char *put_main_command(char *command, char space)
{
	char *temp;
	int i;

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