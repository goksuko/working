#include "../include/so_long.h"

int	gnl_count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (count);
}

char **sl_open_map(char *str)
{
	int		fd;
	char	*line;
	char	*temp;
	char 	**map;

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
	map = ft_split(temp, '\n');
	if (map == NULL)
		return (ft_printf("Map split error.\n"), free(temp), close(fd), NULL);
	close(fd);
	free(temp);
	return (map);
}

t_map	*sl_map_init(char **map)
{
	t_map	*my_map;

	my_map = malloc(sizeof(t_map));
	my_map->content = map;
	my_map->dup_content = map;
	my_map->length_x = sl_strlen(map[0]);
	my_map->length_y = count_lines(map);
	my_map->e_count = 0;
	my_map->p_count = 0;
	my_map->c_count = 0;
	my_map->player_x = 0;
	my_map->player_y = 0;
	return (my_map);
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_map	*my_map;
	
	map = NULL;
	if (argc != 2)
		return (ft_printf("Please provide 1 map.\n"), 1);
	else
	{
		if (sl_check_extension_prob(argv[1]))
			return (ft_printf("Map extension error.\n"), 2);
		map = sl_open_map(argv[1]);
		if (!map)
			return (3);
		my_map = sl_map_init(map);
		if (sl_check_size_prob(my_map))
			return (ft_printf("Map size error.\n"), free_maps(map, my_map),  4);
		if (sl_check_side_wall_prob(my_map) || sl_check_up_down_wall_prob(my_map))
			return (ft_printf("Map wall error.\n"), free_maps(map, my_map), 5);
		else
			return (ft_printf("Fine.\n"), free_maps(map, my_map), 0);
	}
	return (0);
}