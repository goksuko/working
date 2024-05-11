/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:28:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/12 00:51:46 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*ps_arguments_to_stack_a(char *string, t_stack **a);
t_stack				*ps_free_list(t_stack *t_stack);
void				ps_write_error(void);
int					ps_check_if_sorted(t_stack **a);
void				ps_take_numbers(t_stack **a, char **args);
char				*get_next_line(int fd);
void				ps_push(t_stack **src, t_stack **dest, char *str);
void				ps_rotate(t_stack **stack, char *str);
void				ps_reverse_rotate(t_stack **stack, char *str);
void				ps_swap(t_stack **stack, char *str);
bool				ps_initial_probs(int argc, char *argv[]);
char				**ft_split(char const *s, char c);
void				*free_matrix(char **string);
bool				ps_check_probs(char **str);
bool				ps_check_in_array(long *array, long temp);
bool				ps_check_dupp(char **str);
bool				ps_check_non_num(char **str);
bool				ps_big_num(char **str);

#endif