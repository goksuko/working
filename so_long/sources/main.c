/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 13:07:47 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/26 20:03:51 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**sl_open_map(char *str)
{
	int		fd;
	char	*line;
	char	*temp;
	char	**map;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Map openning error.\n"), NULL);
	temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = sl_strjoin(temp, line);
	}
	if (temp == NULL)
		return (ft_printf("Failed to read line.\n"), close(fd), NULL);
	map = sl_split(temp, '\n');
	if (map == NULL)
		return (ft_printf("Map split error.\n"), free(temp), close(fd), NULL);
	close(fd);
	free(temp);
	return (map);
}

char	**sl_map_dup(char **map, int length_x, int length_y)
{
	char	**dup_map;
	int		y;
	int		x;

	y = 0;
	x = 0;
	dup_map = malloc(sizeof(char *) * (length_y + 1));
	if (dup_map == NULL)
		return (ft_printf("Map dup error.\n"), NULL);
	while (y < length_y && map[y])
	{
		dup_map[y] = malloc(sizeof(char) * (length_x + 1));
		if (dup_map[y] == NULL)
			return (ft_printf("Map dup error.\n"), free_matrix(dup_map), NULL);
		while (x < length_x && map[y][x])
		{
			dup_map[y][x] = map[y][x];
			x++;
		}
		dup_map[y][x] = '\0';
		x = 0;
		y++;
	}
	dup_map[y] = NULL;
	return (dup_map);
}

t_map	*sl_map_init(char **map)
{
	t_map	*my_map;

	if (!map)
		return (ft_printf("Map not found.\n"), NULL);
	my_map = malloc(sizeof(t_map));
	if (my_map == NULL)
		return (ft_printf("Map init error.\n"), NULL);
	my_map->length_x = sl_strlen(map[0]);
	my_map->length_y = count_lines(map);
	my_map->content = NULL;
	my_map->content = sl_map_dup(map, my_map->length_x, my_map->length_y);
	my_map->dup_content = NULL;
	my_map->dup_content = sl_map_dup(map, my_map->length_x, my_map->length_y);
	my_map->e_count = 0;
	my_map->p_count = 0;
	my_map->c_count = 0;
	my_map->player_x = 0;
	my_map->player_y = 0;
	return (my_map);
}

int	do_checks(char **map, t_map *my_map)
{
	if (sl_map_empty_line_prob(my_map))
		return (ft_printf("Error\nMap empty line error.\n"),
			free_maps(map, my_map), 5);
	if (sl_check_side_wall_prob(my_map)
		|| sl_check_up_down_wall_prob(my_map))
		return (ft_printf("Error\nMap wall error.\n"),
			free_maps(map, my_map), 6);
	if (sl_check_character_prob(my_map))
		return (ft_printf("Error\nMap character error.\n"),
			free_maps(map, my_map), 7);
	if (sl_check_floodfill_prob(my_map))
		return (ft_printf("Error\nMap floodfill error.\n"),
			free_maps(map, my_map), 8);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_map	*my_map;

	map = NULL;
	// argv[1] = "maps/empty_line_at_start.ber";
	if (argc != 2)
	// if (argc == 5)
		return (ft_printf("Error\nPlease provide 1 map.\n"), 1);
		// ft_printf("Please provide 1 map.\n");
	else
	{
		if (sl_check_extension_prob(argv[1]))
			return (ft_printf("Error\nMap extension error.\n"), 2);
		map = sl_open_map(argv[1]);
		if (!map || map[0] == NULL)
			return (ft_printf("Error\nEmpty map.\n"), 3);
		my_map = sl_map_init(map);
		if (sl_check_size_prob(my_map))
			return (ft_printf("Error\nMap size error.\n"),
				free_maps(map, my_map), 4);
		if (!do_checks(map, my_map))
			return (ft_printf("Fine.\n"), free_maps(map, my_map), 0);
	}
	return (0);
}
