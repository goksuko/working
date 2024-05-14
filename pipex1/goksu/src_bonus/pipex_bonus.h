

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <errno.h>

typedef struct s_info
{
	char	*infile;
	char	*outfile;
	int		pipe_fd[2];
	int		argc;
	int		nbr_of_cmds;
	int		curr_cmd;
}	t_info;

void	ft_usage(void);
void	ft_init_info(t_info *info, int argc, char **argv);
void	ft_exit(char *arg);
void	ft_cmd_not_found(char **cmd);
char	**ft_free_list(char **strlist);
char	**ft_split(const char *str, char c);
char	*ft_get_exec_cmd(char *cmd, char **envp);
void	ft_exec(t_info *info, char **argv, char **envp);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif