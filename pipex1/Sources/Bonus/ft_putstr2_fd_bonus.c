/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr2_fd_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/18 23:30:13 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/21 11:40:20 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

void	ft_putstr2_fd(char *s1, char *s2, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
}

void	ft_putstr3_fd(char *s1, char *s2, char *s3, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd(s3, fd);
}

void	ft_exit_str_fd(int exit_no, char *s, int fd)
{
	ft_putstr_fd(s, fd);
	exit(exit_no);
}

void	ft_exit_perror(int exit_no, char *s)
{
	perror(s);
	exit(exit_no);
}

void	ft_close_exit_perror(t_pipex *info, char **matrix, int exit_no, char *s)
{
	close_pipex(info, matrix);
	perror(s);
	exit(exit_no);
}
