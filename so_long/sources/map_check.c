/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 13:07:57 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/25 13:08:00 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	while (y < my_map->length_y && my_map->content[y])
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
	while (x < my_map->length_x && my_map->content[0][x])
	{
		if (my_map->content[0][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (x < my_map->length_x && my_map->content[my_map->length_y - 1][x])
	{
		if (my_map->content[my_map->length_y - 1][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

bool	sl_check_size_prob(t_map *my_map)
{
	int		y;

	y = 0;
	while (y < my_map->length_y && my_map->content[y])
	{
		if (sl_strlen(my_map->content[y]) != my_map->length_x)
			return (1);
		y++;
	}
	return (0);
}

bool sl_check_character_prob(t_map *my_map)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y < my_map->length_y && my_map->content[y] && my_map->content[y][x])
	{
		while (x < my_map->length_x && my_map->content[y][x])
		{
			if (my_map->content[y][x] == 'P')
			{
				my_map->p_count++;
				my_map->player_x = x;
				my_map->player_y = y;
			}
			else if (my_map->content[y][x] == 'E')
				my_map->e_count++;
			else if (my_map->content[y][x] == 'C')
				my_map->c_count++;
			x++;
		}	
		y++;
		x = 0;
	}
	if (my_map->p_count != 1 || my_map->e_count != 1 || my_map->c_count < 1)
		return (1);
	else
		return (0);
}

bool sl_map_empty_line_prob(t_map *my_map)
{
	int		y;

	y = 0;
	while (y < my_map->length_y && my_map->content[y])
	{
		if (sl_strlen(my_map->content[y]) == 0)
			return (1);
		y++;
	}
	return (0);
}