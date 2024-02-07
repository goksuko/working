/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:28:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/07 22:05:09 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	ps_sa(t_stack **a);
void	ps_sb(t_stack **b);
void	ps_ss(t_stack **a, t_stack **b);
void	ps_pa(t_stack **a, t_stack **b);
void	ps_pb(t_stack **a, t_stack **b);
void	ps_ra(t_stack **a);
void	ps_rb(t_stack **b);
void	ps_rr(t_stack **a, t_stack **b);
void	ps_rra(t_stack **a);
void	ps_rrb(t_stack **b);
void	ps_rrr(t_stack **a, t_stack **b);
t_stack	*ps_string_to_stack_a(char *string, t_stack **a);
t_stack	*ps_arguments_to_stack_a(char *string, t_stack **a);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
t_stack	*ps_free_list(t_stack *t_stack);
void	ps_write_error(void);
long	ps_atoi_matrix(const char *string, char **array, t_stack **a);
long	ps_atoi(const char *string);
int		ps_check_alpha(char *string);
int		ps_check_duplicates(t_stack **a);
int		ps_check_if_sorted(t_stack **a);
void	*free_matrix(char **string);
void	ps_print_stack(t_stack *a);
int		ps_find_length(t_stack **a);
void	ps_sort(t_stack **a);
int		find_max(t_stack **a);
int		find_min(t_stack **a);
int		find_median(t_stack **a);
void	do_for_three(t_stack **a);
void	do_for_five(t_stack **a);
void	do_big_sort(t_stack **a);
void	ps_make_bubble_sort(t_stack **a);
void	*free_array(int *array);

#endif