#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // calloc
# include <unistd.h> // read
# include <stdio.h> // printf
# include <fcntl.h> // open
# include <limits.h> // INT_MAX
# include <stdbool.h> // bool

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct Node {
    int			value; /**< the value stored in the node */
    struct Node	*next; /**< pointer to the next node in the list */
} Node;

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
Node	*string_to_list2(char *buffer);
Node	*split_from_value(Node **head, int value);
Node	*append_list(Node **head1, Node **head2);


#endif