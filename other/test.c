#include "get_next_line.h"

char	*list_to_string(Node **list);
Node	*string_to_list(char *string);


//my own test for my functions
// int main()
// {
//     char *string;
//     char *string2;
//     Node *list;
//     Node *temp;

//     string = "Hello World";
//     printf("%s\n", string);
//     list = string_to_list(string);
//     printf("%d\n", list->value);
//     printf("%d\n", list->next->value);
//     printf("%d\n", list->next->next->value);
//     string2 = list_to_string(&list);
//     printf("%s\n", string2);
//     free(string2);
//     string2 = NULL;
//     while (list != NULL)
//     {
//         temp = list;
//         list = list->next;
//         free(temp);
//     }
//     return (0);
// }