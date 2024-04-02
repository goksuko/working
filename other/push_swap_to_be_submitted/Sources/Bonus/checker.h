/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:28:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/25 13:16:15 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ps_one_arg_to_stack_a(char *string, t_stack **a);
t_stack	*ps_arguments_to_stack_a(char *string, t_stack **a);
t_stack	*ps_free_list(t_stack *t_stack);
void	ps_write_error(void);
int		ps_check_duplicates(t_stack **a);
int		ps_check_if_sorted(t_stack **a);
t_stack	*ps_take_numbers(int argc, char *argv[]);
char	*get_next_line(int fd);
// int		ft_printf(const char *format, ...);
void	ps_push(t_stack **src, t_stack **dest, char *str);
void	ps_rotate(t_stack **stack, char *str);
void	ps_reverse_rotate(t_stack **stack, char *str);
void	ps_swap(t_stack **stack, char *str);

#endif