#include "push_swap.h"

//If you intend to modify the original pointer passed to the function, 
//you should use the first code where the function takes a pointer to a pointer.

//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
void ps_sa(t_stack **a)
{
	t_stack *current;
	t_stack *t_stack1;
	t_stack *t_stack2;
	t_stack *temp1;
	t_stack *temp2;

	current = *a;
	if (current == NULL || current->next == NULL)
		return ;
	t_stack1 = current;
	t_stack2 = current->next;
	temp1 = t_stack2->next; //temp1 shows what will be the next t_stack of t_stack1 in the future
	t_stack1->next = temp1;
	temp2 = t_stack1;
	t_stack2->next = temp2;
	current = t_stack2;
	*a = current;
}

//Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
void ps_sb(t_stack **b)
{
	t_stack *current;
	t_stack *t_stack1;
	t_stack *t_stack2;
	t_stack *temp1;
	t_stack *temp2;

	current = *b;
	if (current == NULL || current->next == NULL)
		return ;
	t_stack1 = current;
	t_stack2 = current->next;
	temp1 = t_stack2->next; //temp1 shows what will be the next t_stack of t_stack1 in the future
	t_stack1->next = temp1;
	temp2 = t_stack1;
	t_stack2->next = temp2;
	current = t_stack2;
	*b = current;
}

void ps_ss(t_stack **a, t_stack **b)
{
	ps_sa(a);
	ps_sb(b);
}

//push a: Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void ps_pa(t_stack **a, t_stack **b)
{
	t_stack		*to_return;
	t_stack		*current;
	t_stack		*temp;

	current = *b;
	if (current == NULL)
		return ;
	else
	{
		to_return = current->next;
		temp = *b;
		*b = to_return;
	}
	if (*a == NULL)
		*a = temp;
	else
	{
		temp->next = *a;
		*a = temp;
	}
}

//push b: Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
void ps_pb(t_stack **a, t_stack **b)
{
	t_stack		*to_return;
	t_stack		*current;
	t_stack		*temp;

	current = *a;
	if (current == NULL)
		return ;
	else
	{
		to_return = current->next;
		temp = *a;
		*a = to_return;
	}
	if (*b == NULL)
		*b = temp;
	else
	{
		temp->next = *b;
		*b = temp;
	}
}

//rotate a: Shift up all elements of stack a by 1.
//The first element becomes the last one.
void ps_ra(t_stack **a)
{
	t_stack *current;
	t_stack *temp;

	current = *a;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		temp = current;
		*a = current->next;
		temp->next = NULL;
		while (current->next->next != NULL)
			current = current->next;
		current->next = temp;
	} 
}

//rotate b: Shift up all elements of stack b by 1.
//The first element becomes the last one.
void ps_rb(t_stack **b)
{
	t_stack *current;
	t_stack *temp;

	current = *b;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		temp = current;
		*b = current->next;
		temp->next = NULL;
		while (current->next->next != NULL)
			current = current->next;
		current->next = temp;
	} 
}

void ps_rr(t_stack **a, t_stack **b)
{
	ps_ra(a);
	ps_rb(b);
}

//reverse rotate a: Shift down all elements of stack a by 1.
//The last element becomes the first one.
void ps_rra(t_stack **a)
{
	t_stack *current;
	t_stack *temp;

	current = *a;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		while (current->next->next != NULL)
			current = current->next;
		temp = current->next;
		current->next = NULL;
		temp->next = *a;
		*a = temp;
	}
}

//reverse rotate b: Shift down all elements of stack b by 1.
//The last element becomes the first one.
void ps_rrb(t_stack **b)
{
	t_stack *current;
	t_stack *temp;

	current = *b;
	if (current == NULL || current->next == NULL)
		return ;
	else
	{
		while (current->next->next != NULL)
			current = current->next;
		temp = current->next;
		current->next = NULL;
		temp->next = *b;
		*b = temp;
	}
}

void ps_rrr(t_stack **a, t_stack **b)
{
	ps_rra(a);
	ps_rrb(b);
}

/*
typedef struct s_stack
{
	int			value;
	int			index;
	struct s_stack	*next;
}				t_stack;
*/