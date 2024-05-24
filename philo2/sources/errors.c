/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/23 22:55:51 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/24 16:32:12 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

const char	*ft_error(int code)
{
	const char	*errors[] = {"", "No seat provided", "No fork provided"};

	if (code > 0 && code <= 2)
	{
		// ft_printf_fd(STDERR_FILENO, "%s", errors[code]);
		exit(code);
	}
	else
	{
		// ft_printf_fd(STDERR_FILENO, "Unknown error");
		return (errors[code]);
	}
}