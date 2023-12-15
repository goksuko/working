/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 19:26:05 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/11 14:13:05 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	do_type(char t, va_list args)
{
	static size_t	total;

	total = 0;
	if (t == 'c')
		total += print_char(va_arg(args, int));
	else if (t == 's')
		total += print_string(va_arg(args, char *));
	else if (t == 'p')
		total += print_pointer(va_arg(args, unsigned int));
	else if (t == 'i' || t == 'd')
		total += print_decimal(va_arg(args, int));
	else if (t == 'u')
		total += print_unsign_decimal(va_arg(args, unsigned int));
	else if (t == 'x')
		total += print_hexadecimal(va_arg(args, unsigned int));
	else if (t == 'X')
		total += print_upp_hexadecimal(va_arg(args, unsigned int));
	else if (t == '%')
		total += write(STDOUT_FD, "%", sizeof(char));
	else if (t != '%')
	{
		total += write(STDOUT_FD, "%", sizeof(char));
		total += write(STDOUT_FD, &t, sizeof(char));
	}
	return (total);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	char			*s;
	va_list			args;
	int				total;

	va_start (args, format);
	total = 0;
	if(!format)
		return (0);
	s = (char *)format;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != '%')
		{
			write(STDOUT_FD, &s[i], sizeof(char));
			total++;
		}
		else
		{
			total += do_type(s[i + 1], args);
			i++;
		}
		i++;
	}
	va_end (args);
	return (total);
}
