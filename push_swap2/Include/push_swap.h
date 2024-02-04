/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 11:28:55 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/02/05 00:06:10 by akaya-oz      ########   odam.nl         */
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
long		ps_atoi_matrix(const char *string, char **array, t_stack **a);
long		ps_atoi(const char *string);
static int	ft_isspace(int c);


#endif