/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:34:12 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/21 11:39:43 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>

typedef struct s_pipex
{
	int		pipefd[2];
	int		fd_in;
	int		fd_out;
	int		nbr_of_cmds;
	int		curr_cmd;
}	t_pipex;

// Libft functions //

int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_calloc(size_t nmemb, size_t size);

// Utils functions //
char	*put_main_command(char *command, char space);
void	start_exec(t_pipex *info, char **argv, char **envp);
void	*free_matrix(char **string);
void	close_pipex(t_pipex *info, char **matrix);

// Path functions //
char	*find_path(char *cmd, char **envp);
int		check_path(char **envp);
void	command_not_found(char *argv[]);

// Ft_putstr2_fd functions //
void	ft_putstr2_fd(char *s1, char *s2, int fd);
void	ft_putstr3_fd(char *s1, char *s2, char *s3, int fd);
void	ft_exit_str_fd(int exit_no, char *s, int fd);
void	ft_exit_perror(int exit_no, char *s);
void	ft_close_exit_perror(t_pipex *info, char **matrix,
			int exit_no, char *s);
