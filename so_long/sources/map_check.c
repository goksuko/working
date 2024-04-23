#include "../include/so_long.h"

bool	sl_check_extension_prob(char *str)
{
	int		len;
	char	*ext;
	int		i;
	int		j;
	char	*ber;

	len = sl_strlen(str);
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

bool	sl_check_side_wall_prob(t_map *my_map)
{
	int		y;

	y = 0;
	while (my_map->content[y])
	{
		if (my_map->content[y][0] != '1' || my_map->content[y][my_map->length_x - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

bool	sl_check_up_down_wall_prob(t_map *my_map)
{
	int		x;

	x = 0;
	while (my_map->content[0][x])
	{
		if (my_map->content[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (my_map->content[my_map->length_y - 1][x])
	{
		if (my_map->content[my_map->length_y - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

bool	sl_check_size_prob(t_map *my_map)
{
	int		i;
	int		length;

	i = 0;
	length = my_map->length_x;
	while (my_map->content[i])
	{
		if (sl_strlen(my_map->content[i]) != length)
			return (1);
		i++;
	}
	return (0);
}
