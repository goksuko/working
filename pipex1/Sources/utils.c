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

void	start_exec(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_matrix(cmd);
		perror("Command not found\n");
		exit(1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_matrix(cmd); //??
		perror("Error executing command\n");
		exit(1);
	}
}

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	**path_split;
	int		i;
	char 	*tmp;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_split = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_split[i])
	{
		tmp = ft_strjoin(path_split[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (path_split[++i])
		free(path_split[i]);
	free(path_split);
	return (NULL);
}

void do_execution(char *argv, char **envp)
{
	char **cmd;
	char *path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_matrix(cmd);
		perror("Command not found\n");
		exit(1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_matrix(cmd);
		perror("Error executing command\n");
		exit(1);
	}
}