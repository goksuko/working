#include "../include/so_long.h"

void	*free_matrix(char **string)
{
	int	i;

	i = 0;
	while (string && string[i])
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	if (string)
	{
		free(string);
		string = NULL;
	}
	return (NULL);
}