/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hex.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 20:26:18 by akaya-oz      #+#    #+#                 */
/*   Updated: 2023/12/08 14:45:47 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_hexadecimal(unsigned int hexa)
{
	char			*letters;
	static size_t	total;

	total = 0;
	letters = "0123456789abcdef";
	if (hexa >= 16)
	{
		print_hexadecimal(hexa / 16);
	}
	if (hexa <= INT_MAX && hexa >= 0)
	{
		write(1, &letters[hexa % 16], 1);
		total++;
	}
	return (total);
}

size_t	print_upp_hexadecimal(unsigned int hexa)
{
	char			*letters;
	static size_t	total;

	total = 0;
	letters = "0123456789ABCDEF";
	if (hexa >= 16)
	{
		print_upp_hexadecimal(hexa / 16);
	}
	if (hexa <= INT_MAX && hexa >= 0)
	{
		write(1, &letters[hexa % 16], 1);
		total++;
	}
	return (total);
}

size_t	print_pointer(long long nb)
{
	static size_t	total;

	if (!nb)
	{
		total += print_string("(nil)");
		return (total);
	}
	total += print_string("0x");
	total += print_hexadecimal(nb);
	return (total);
}
