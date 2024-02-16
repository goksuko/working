/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:28:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/16 10:57:48 by akaya-oz      ########   odam.nl         */
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
void	ps_take_numbers(t_stack **a, int argc, char *argv[]);
int		ft_printf(const char *format, ...);
void	do_radix_sort(t_stack **a);
void	sort_eff_a(t_stack **a);
void	sort_eff_b(t_stack **b);
void	ps_push(t_stack **src, t_stack **dest, char *str);
void	ps_rotate(t_stack **stack, char *str);
void	ps_reverse_rotate(t_stack **stack, char *str);
void	ps_swap(t_stack **stack, char *str);
int		clck_while_nb_edge(t_stack **stack, int edge);
int		clck_while_nb_small(t_stack **stack, int big);
int		clck_while_nb_big(t_stack **stack, int small);
void	reverse_rotate_till(t_stack **stack, int nb, char letter);
void	reverse_rotate_still_small(t_stack **stack, int big, char letter);
void	reverse_rotate_still_big(t_stack **stack, int small, char letter);
void	rotate_till(t_stack **stack, int nb, char letter);
void	rotate_still_small(t_stack **stack, int big, char letter);
void	rotate_still_big(t_stack **stack, int small, char letter);
void	do_first_first(t_stack **a, t_stack **b, int max_b);
void	do_first_second(t_stack **a, t_stack **b, int min_b);
void	do_second_first(t_stack **a, t_stack **b, int max_a);
void	do_second_second(t_stack **a, t_stack **b, int min_a);
void	do_radix_sort(t_stack **a);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_char_in_set(char c, char const *set);
t_stack	*ps_write_in_stack_a(t_stack **a, int nb);

#endif