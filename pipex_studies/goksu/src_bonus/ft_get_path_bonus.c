

#include "pipex_bonus.h"

static char	**ft_get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*ft_get_exec_cmd(char *cmd, char **envp)
{
	char	**dir_list;
	char	*full_dir_path;
	char	*exec_cmd;
	int		i;

	i = 0;
	if (ft_strnstr(cmd, "/", ft_strlen(cmd)))
		return (cmd);
	dir_list = ft_get_paths(envp);
	i = -1;
	while (dir_list[++i])
	{
		full_dir_path = ft_strjoin(dir_list[i], "/");
		exec_cmd = ft_strjoin(full_dir_path, cmd);
		free(full_dir_path);
		if (access(exec_cmd, F_OK | X_OK) == 0)
		{
			ft_free_list(dir_list);
			return (exec_cmd);
		}
		free(exec_cmd);
	}
	ft_free_list(dir_list);
	return (NULL);
}

void	ft_exec(t_info *info, char **argv, char **envp)
{
	char	**cmd_list;

	cmd_list = ft_split(argv[info->curr_cmd], ' ');
	if (cmd_list[0] == NULL)
		ft_exit(cmd_list[0]);
	if (execve(ft_get_exec_cmd(cmd_list[0], envp), cmd_list, envp) == -1)
		ft_cmd_not_found(cmd_list);
}
