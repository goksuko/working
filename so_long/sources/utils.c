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

int sl_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		join[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = '\0';
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (join);
}

void free_maps(char **map, t_map *my_map)
{
	free_matrix(map);
	if (!my_map)
		return ;
	else
	{
		free_matrix(my_map->content);
		free_matrix(my_map->dup_content);
		free(my_map);
		my_map = NULL;	
	}

}

int	count_lines(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}
