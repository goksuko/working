/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/16 13:34:12 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/17 12:39:12 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// Libft functions //

int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big,	const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

// Main functions //
void	start_exec(char *comand, char **envp);
char	*find_path(char *cmd, char **envp);