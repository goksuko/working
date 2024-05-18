/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:34:42 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/18 23:39:34 by akaya-oz      ########   odam.nl         */
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
		ft_exit_str_fd(127, "zsh: command not found: \n", 2);
	cmd = ft_split(long_command, ' ');
	if (cmd[0])
		path = find_path(cmd[0], envp);
	else
	{
		free_matrix(cmd);
		ft_exit_str_fd(1, "zsh: permission denied: \n", 2);
	}
	if (!path)
	{
		ft_putstr3_fd("zsh: not a directory: ", cmd[0], "\n", 2);
		free_matrix(cmd);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_matrix(cmd);
		ft_exit_str_fd(1, "Error executing command\n", 2);
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
