#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
    int				value;
    int				index;
    int				keep;
    int             len;
    char            *arr;
    struct s_stack	*prev;
    struct s_stack	*next;
}					t_stack;

#endif