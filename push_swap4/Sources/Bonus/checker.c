/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/10 23:47:15 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/12 00:23:20 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/push_swap.h"

char	*do_operation2(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'r'&& line[2] == 'a' && line[3] == '\n')
		ps_rra(a);
	else if (line[0] == 'r' && line[1] == 'r'&& line[2] == 'b' && line[3] == '\n')
		ps_rrb(b);
	else if (line[0] == 'r' && line[1] == 'r'&& line[2] == 'r' && line[3] == '\n')
		ps_rrr(a, b);
	else
		ps_write_error();
	return (get_next_line(0));
}

char	*do_operation(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ps_sa(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ps_sb(b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ps_ss(a, b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ps_pa(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ps_pb(a, b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ps_ra(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ps_rb(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ps_rr(a, b);
	else 
		return (do_operation2(a, b, line));
	return (get_next_line(0));
}

void	do_check(t_stack **a, t_stack **b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = do_operation(a, b, line);
		free(temp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!ps_check_if_sorted(a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = ps_take_numbers(argc, argv);
	b = NULL;
	if (!a || ps_check_duplicates(&a))
	{
		a = ps_free_list(a);
		ps_write_error();
	}
	line = get_next_line(0);
	if (!line && !ps_check_if_sorted(&a))
		write(1, "KO\n", 3);
	else if(!line && ps_check_if_sorted(&a))
		write(1, "OK\n", 3);
	else
		do_check(&a, &b, line);
	if (a != NULL)
		a = ps_free_list(a);
	if (b != NULL)
		b = ps_free_list(b);
	return (0);
}
