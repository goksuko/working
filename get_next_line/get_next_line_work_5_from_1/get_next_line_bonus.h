/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/02 12:21:18 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/10 12:18:12 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h> //read
# include <stdlib.h> //malloc
// # include <stdio.h> // printf and End Of File
# include <limits.h>
# include <fcntl.h> //open txt file
# include <stdint.h> //ft_calloc

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	*free_there(char **line);
char	*gnl_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *s);

#endif