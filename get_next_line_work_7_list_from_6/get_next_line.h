#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // calloc
# include <unistd.h> // read
# include <stdio.h> // printf
# include <fcntl.h> // open
# include <limits.h> // INT_MAX
# include <stdbool.h> // bool

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct Node {
    int			value; /**< the value stored in the node */
    struct Node	*next; /**< pointer to the next node in the list */
} Node;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*list_to_string(Node **list);
Node	*string_to_list(char *string);
Node	*split_from_value(Node **head, int value);
Node	*append_list(Node **head1, Node **head2);
Node    *duplicate_list_recursive(Node *node);
Node    *delete_list(Node *node);
int     length(Node **head);
Node    *duplicate_list(Node **head);
Node    *insert_at_tail(Node **head, int new_value);
void print_list(Node **head);
Node *rest_list(Node **long_list, Node **begin);


#endif