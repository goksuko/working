/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:28:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/12 01:01:01 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int				index_a;
	int				price;
	bool			second_half;
	struct s_stack	*next;
}					t_stack;

// Libft

char				**ft_split(char const *s, char c);
int					ft_printf(const char *format, ...);

// utils.c

t_stack				*ps_arguments_to_stack_a(char *string, t_stack **a);
bool				ps_check_if_sorted(t_stack **a);
int					clck_while_nb_edge(t_stack **stack, int edge);

// checks_new.c

bool				ps_initial_probs(int argc, char *argv[]);
bool				ps_check_in_array(long *array, long temp);
bool				ps_check_dupp(char **str);
bool				ps_check_non_num(char **str);
bool				ps_big_num(char **str);

// utils2.c

t_stack				*ps_free_list(t_stack *t_stack);
void				*free_matrix(char **string);
void				ps_write_error(void);
void				ps_print_stack(t_stack *a);
int					ps_find_length(t_stack **a);

// oper_push.c

void				ps_push(t_stack **src, t_stack **dest, char *str);

// oper_rotate.c

void				ps_rotate(t_stack **stack, char *str);
void				ps_rotate_both(t_stack **a, t_stack **b);

// oper_reverse.c

void				ps_reverse_rotate(t_stack **stack, char *str);
void				ps_reverse_rotate_both(t_stack **a, t_stack **b);

// oper_swap.c
void				ps_swap(t_stack **stack, char *str);

// sort.c

void				ps_sort(t_stack **a);
void				do_for_three(t_stack **a);
void				do_for_four(t_stack **a, int length);
void				do_for_five(t_stack **a, int length);

// new_sort.c

void				do_new_sort(t_stack **a, int length);

// new_sort_utils.c

void				rotate_and_finish(t_stack **a, t_stack **b,
						t_stack *best_b);
void				reverse_rotate_and_finish(t_stack **a, t_stack **b,
						t_stack *best_b);
void				a_first_b_second(t_stack **a, t_stack **b, t_stack *best_b);
void				a_second_b_first(t_stack **a, t_stack **b, t_stack *best_b);

// find_index.c

void				give_position_index(t_stack **a);
void				find_index_a(t_stack **a, t_stack **b);
void				give_price(t_stack **stack);

// maths.c

int					find_min(t_stack **a);
int					find_max(t_stack **a);

// new_sort_utils2.c

void				reverse_rotate_till(t_stack **stack, int nb, char letter);
void				rotate_till(t_stack **stack, int nb, char letter);
void				sort_eff_a(t_stack **a);

// atois.c

long				ps_string_to_long(const char *string);

#endif