/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_sort_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/15 23:38:12 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 23:48:44 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	sort_eff_a(t_stack **a)
{
	int		clock_wise;
	int		min_a;
	int		length;

	min_a = find_min(a);
	length = ps_find_length(a);
	clock_wise = clck_while_nb_edge(a, min_a);
	if (length - clock_wise > clock_wise)
		rotate_till(a, min_a, 'a');
	else
		reverse_rotate_till(a, min_a, 'a');
}

void	sort_eff_b(t_stack **b)
{
	int		clock_wise;
	int		max_b;
	int		length;

	max_b = find_max(b);
	length = ps_find_length(b);
	clock_wise = clck_while_nb_edge(b, max_b);
	if (length - clock_wise > clock_wise)
		rotate_till(b, max_b, 'b');
	else
		reverse_rotate_till(b, max_b, 'b');
}
