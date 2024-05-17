
#include "pipex_bonus.h"

void	ft_usage(void)
{
	ft_putstr_fd("Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_init_info(t_info *info, int argc, char **argv)
{
	info->infile = argv[1];
	info->outfile = argv[argc - 1];
	info->argc = argc;
	info->nbr_of_cmds = argc - 3;
	info->curr_cmd = 2;
}

void	ft_exit(char *arg)
{
	if (errno == 0)
	{
		if (arg == NULL)
		{
			ft_putstr_fd("Command '' not found \n", 2);
			exit(126);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	else
		perror(arg);
	exit(EXIT_FAILURE);
}

void	ft_cmd_not_found(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	ft_putstr_fd(": command not found\n", 2);
	ft_free_list(cmd);
	exit(127);
}
