/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:34:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/17 23:15:57 by akaya-oz      ########   odam.nl         */
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

	cmd = ft_split(long_command, ' ');
	if (cmd[0])
		path = find_path(cmd[0], envp);
	else
	{
		free_matrix(cmd);
		perror("Command not found\n");
		exit(127);
	}
	if (!path)
	{
		free_matrix(cmd);
		perror("Path not found\n");
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_matrix(cmd);
		perror("Error executing command\n");
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
