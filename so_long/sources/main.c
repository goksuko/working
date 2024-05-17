/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 13:07:47 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/17 23:34:29 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	initial_checks(int argc, char *argv[])
{
	if (argc == 1)
		return (perror("Error\nPlease provide a map.\n"), 1);
	if (argc > 2)
		return (perror("Error\nPlease provide 1 map.\n"), 2);
	if (sl_check_extension_prob(argv[1]))
		return (perror("Error\nMap extension error.\n"), 3);
	return (0);
}

int	do_checks(char **map, t_map *my_map)
{
	if (sl_map_empty_line_prob(my_map))
		return (perror("Error\nMap empty line error.\n"), free_maps(map,
				my_map), 8);
	if (sl_check_side_wall_prob(my_map) || sl_check_up_down_wall_prob(my_map))
		return (perror("Error\nMap wall error.\n"), free_maps(map, my_map),
			9);
	if (sl_check_character_prob(my_map))
		return (free_maps(map, my_map), 10);
	if (sl_check_floodfill_prob(my_map))
		return (perror("Error\nUnreachable exit or collectable.\n"),
			free_maps(map, my_map), 11);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_map	*my_map;
	int		error_check;

	map = NULL;
	error_check = initial_checks(argc, argv);
	if (error_check > 0)
		return (error_check);
	map = sl_open_map(argv[1]);
	if (!map)
		return (4);
	if (map && map[0] == NULL)
		return (perror("Error\nEmpty map.\n"), 5);
	my_map = sl_map_init(map);
	if (!my_map)
		return (6);
	if (sl_check_size_prob(my_map))
		return (perror("Error\nSize error.\n"), free_maps(map, my_map), 7);
	error_check = do_checks(map, my_map);
	if (error_check > 0)
		return (error_check);
	if (!sl_game(&my_map->game, my_map))
		return (perror("Error\nGame error.\n"), free_maps(map, my_map), 12);
	free_maps(map, my_map);
	return (0);
}
