#include "push_swap.h"

void	ps_print_stack(t_stack *a)
{
	t_stack    *current;
	int     i;

	current = a;
	i = 0;
	if (current == NULL)
		printf("List is empty.\n");
	else
	{
		printf("===Printing List===\n");
		while (current != NULL)
		{
			printf("Stack %d: %d\n", i, current->value);
			i++;
			current = current->next;
		}
	}
}

t_stack *ps_free_list(t_stack *t_stack)
{
	if (t_stack != NULL)
	{
		ps_free_list(t_stack->next);
		free(t_stack);
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
	t_stack *a = NULL;
	int 	i;

	i = 1;
	if (argc == 2)
		a = ps_string_to_stack_a(argv[1], &a);
	else if (argc > 2)
	{
		while (i < argc)
		{
			a = ps_arguments_to_stack_a(argv[i], &a);
			i++;
		}
	}
	ps_print_stack(a);
	a = ps_free_list(a);
	return (0);
}

