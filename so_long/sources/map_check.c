#include "../include/so_long.h"

bool	sl_check_extension_prob(char *str)
{
	int		len;
	char	*ext;
	int		i;
	int		j;
	char	*ber;

	len = ft_strlen(str);
	ber = ".ber";
	if (len < 5)
		return (1);	
	i = 0;
	j = len - 4;
	ext = malloc(sizeof(char) * 5);
	if (ext == NULL)
		return (1);
	while (i < 4)
	{
		ext[i] = str[j];
		i++;
		j++;
	}
	ext[i] = '\0';
	i = 0;
	while (i < 4)
	{
		if (ext[i] != ber[i])
		{
			free(ext);
			return (1);
		}
		i++;
	}
	free(ext);
	return (0);
}

bool	sl_check_border_prob(t_map *my_map)
{
	int		i;

	i = 0;
	while (i < my_map->length_x)
	{
		if (my_map->content[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < my_map->length_x)
	{
		if (my_map->content[my_map->length_y - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < my_map->length_y)
	{
		if (my_map->content[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < my_map->length_y)
	{
		if (my_map->content[i][my_map->length_x - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
