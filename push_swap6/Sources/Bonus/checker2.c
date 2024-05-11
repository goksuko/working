/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/10 23:47:15 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/12 00:49:52 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	ps_check_probs(char **str)
{
	if (ps_check_non_num(str))
		return (1);
	if (ps_big_num(str))
		return (1);
	if (ps_check_dupp(str))
		return (1);
	return (0);
}