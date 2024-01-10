/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/04 16:05:18 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/01/04 16:09:59 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_node {
    int			    value; /**< the value stored in the node */
    struct s_node	*next; /**< pointer to the next node in the list */
} t_node;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*list_to_string(t_node **list);
t_node	*string_to_list(char *string);
t_node	*split_from_value(t_node **head, int value);
t_node	*append_list(t_node **head1, t_node **head2);
t_node  *duplicate_list_recursive(t_node *node);
t_node  *delete_list(t_node *node);
int     length(t_node **head);
t_node  *duplicate_list(t_node **head);
t_node  *insert_at_tail(t_node **head, int new_value);
void    print_list(t_node **head);
t_node  *rest_list(t_node **long_list, t_node **begin);

#endif
