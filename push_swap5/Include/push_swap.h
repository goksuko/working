/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:28:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/15 18:51:07 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
char	**ft_split(char const *s, char c);
t_stack	*ps_free_list(t_stack *t_stack);
void	ps_write_error(void);
long	ps_atoi_matrix(const char *string, char **array, t_stack **a);
long	ps_atoi(const char *string);
int		ps_check_digit(char *string);
int		ps_check_duplicates(t_stack **a);
int		ps_check_if_sorted(t_stack **a);
void	*free_matrix(char **string);
void	ps_print_stack(t_stack *a);
int		ps_find_length(t_stack **a);
void	ps_sort(t_stack **a, int median);
int		find_max(t_stack **a);
int		find_min(t_stack **a);
int		find_median(t_stack **a);
void	do_for_three(t_stack **a, int median);
void	do_for_four(t_stack **a, int length);
void	do_for_five(t_stack **a, int median, int length);
void	do_big_sort(t_stack **a, int median, int length);
void	ps_make_bubble_sort(t_stack **a);
t_stack	*ps_take_numbers(int argc, char *argv[]);
int		ft_printf(const char *format, ...);
void	do_radix_sort(t_stack **a);
void	sort_eff_a(t_stack **a);
void	sort_eff_b(t_stack **b);
void	ps_push(t_stack **src, t_stack **dest, char *str);
void	ps_rotate(t_stack **stack, char *str);
void	ps_reverse_rotate(t_stack **stack, char *str);
void	ps_swap(t_stack **stack, char *str);

#endif