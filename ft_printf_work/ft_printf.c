/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 19:26:05 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/08 14:45:12 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	do_type(char t, va_list args)
{
	static size_t	total;

	total = 0;
	if (t == 'c')
		total += print_char(va_arg(args, int));
	else if (t == 's')
		total += print_string(va_arg(args, void *));
	else if (t == 'p')
		total += print_pointer(va_arg(args, long long));
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

int main(void)
{
	char			c = 'G';
	char			*s = "Goksu";
	int				d = -458961230;
	// int				u = 123456789;
	// unsigned int 	x = 123;
	// unsigned int	ux = 123456;
	int				f;
	int				p;

	f = ft_printf(" %u \n", 101);
	p = printf(" %u \n", 101);
	printf(" my: %d\norg: %d\n-----\n", f, p);
	f = ft_printf(" %x \n", -100);
	p = printf(" %x \n", -100);
	printf(" my: %d\norg: %d\n-----\n", f, p); 
	f = ft_printf(" %X \n", -100);
	p = printf(" %X \n", -100);
	printf(" my: %d\norg: %d\n-----\n", f, p); 
	f = ft_printf("char: %c\n", c);
	p = printf("char: %c\n", c);
	printf(" my: %d\norg: %d\n-----\n", f, p);
	f = ft_printf("char: %c, string: %s\n", c, s);
	p = printf("char: %c, string: %s\n", c, s);
	printf(" my: %d\norg: %d\n-----\n", f, p);
	f = ft_printf("char: %c, string: %s, decimal: %d\n", c, s, d);
	p = printf("char: %c, string: %s, decimal: %i\n", c, s, d);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("char: %c, string: %s, decimal: %d, integer: %d\n", c, s, d, d);
	// p = printf("char: %c, string: %s, decimal: %i, integer: %d\n", c, s, d, d);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("integer: %d, unsigned decimal: %u\n", d, u);
	// p = printf("integer: %d, unsigned decimal: %u\n", d, u);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("hexa: %x, HEXA: %X\n", x, ux);
	// p = printf("hexa: %x, HEXA: %X\n", x, ux);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("pointer: %p\n", s);
	// p = printf("pointer: %p\n", s);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf(" %d ", 1);
	// p = printf(" %d ", 1);
	// printf(" my: %d\norg: %d\n-----\n", f, p);	
	// f = ft_printf(" NULL %s NULL ", NULL);
	// // p = printf(" NULL %s NULL ", NULL);
	// // printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	// // p = printf(" %p %p ", LONG_MIN, LONG_MAX);
	// // printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf(" %p %p ", INT_MIN, INT_MAX);
	// // p = printf(" %p %p ", INT_MIN, INT_MAX);
	// // printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	// // p = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	// // printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf(" %p %p ", 0, 0);
	// // p = printf(" %p %p ", 0, 0);
	// // printf(" my: %d\norg: %d\n-----\n", f, p);	
	return (0);
}
