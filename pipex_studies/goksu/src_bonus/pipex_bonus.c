

#include "pipex_bonus.h"

pid_t	ft_last_child(t_info *info, char **argv, char **envp)
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (pid == -1)
		ft_exit("fork");
	if (pid == 0)
	{
		outfile = open(info->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (outfile == -1)
			ft_exit(info->outfile);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		ft_exec(info, argv, envp);
	}
	close(STDIN_FILENO);
	return (pid);
}

pid_t	ft_child(t_info *info, char **argv, char **envp)
{
	pid_t	pid;
	int		infile;

	pid = fork();
	if (pid == -1)
		ft_exit("fork");
	if (pid == 0)
	{
		if (info->curr_cmd == 2)
		{
			infile = open(info->infile, O_RDONLY, 0777);
			if (infile == -1)
				ft_exit(info->infile);
			dup2(infile, STDIN_FILENO);
			close(infile);
		}
		close(info->pipe_fd[0]);
		dup2(info->pipe_fd[1], STDOUT_FILENO);
		close(info->pipe_fd[1]);
		ft_exec(info, argv, envp);
	}
	return (pid);
}

int	ft_create_children(t_info *info, char **argv, char **envp)
{
	int		i;
	pid_t	wpidc;
	pid_t	wpidlc; //last child
	int		status;

	i = 1;
	while (i < info->nbr_of_cmds)
	{
		if (pipe(info->pipe_fd) == -1)
			ft_exit(NULL);
		wpidc = ft_child(info, argv, envp);
		close(info->pipe_fd[1]);
		dup2(info->pipe_fd[0], STDIN_FILENO);
		close(info->pipe_fd[0]);
		info->curr_cmd++;
		i++;
	}
	wpidlc = ft_last_child(info, argv, envp);
	while (waitpid(wpidc, &status, 0) != -1)
		;
	waitpid(wpidlc, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;
	int		exit_code;

	errno = 0;
	info = malloc(sizeof(t_info));
	if (argc < 5)
		ft_usage();
	ft_init_info(info, argc, argv);
	exit_code = ft_create_children(info, argv, envp);
	if (exit_code != 0)
	{
		free(info);
		return (exit_code);
	}
	free(info);
	return (0);
}
