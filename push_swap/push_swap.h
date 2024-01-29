#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int			value;
	int			index;
	struct s_stack	*next;
}				t_stack;


#include "push_swap.h"

void ps_sa(t_stack **a);
void ps_sb(t_stack **b);
void ps_ss(t_stack **a, t_stack **b);
void ps_pa(t_stack **a, t_stack **b);
void ps_pb(t_stack **a, t_stack **b);
void ps_ra(t_stack **a);
void ps_rb(t_stack **b);
void ps_rr(t_stack **a, t_stack **b);
void ps_rra(t_stack **a);
void ps_rrb(t_stack **b);
void ps_rrr(t_stack **a, t_stack **b);
t_stack *ps_string_to_stack_a(char *string, t_stack **a);
t_stack *ps_arguments_to_stack_a(char *string, t_stack **a);


#endif