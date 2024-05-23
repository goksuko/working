/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_fd.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 20:00:33 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/23 22:47:19 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# ifndef FT_PRINTF_FD_ERROR
#  define FT_PRINTF_FD_ERROR -1
# endif

int		ft_printf_fd(int fd, const char *format, ...);
size_t	print_char(int fd, int i);
size_t	print_string(int fd, void *ptr);
size_t	print_decimal(int fd, int nb);
size_t	print_unsign_decimal(int fd, unsigned int nb);
size_t	print_hexadecimal(int fd, unsigned int hexa);
size_t	print_upp_hexadecimal(int fd, unsigned int hexa);
size_t	print_pointer(int fd, unsigned long int nb);
size_t	pointer_helper(int fd, unsigned long int hexa);

#endif