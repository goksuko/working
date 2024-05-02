/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/29 20:35:53 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/02 23:16:05 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_free_textures(t_game *my_game)
{
	if (my_game->char_tx)
		mlx_delete_texture(my_game->char_tx);
	if (my_game->wall_tx)
		mlx_delete_texture(my_game->wall_tx);
	if (my_game->col_tx)
		mlx_delete_texture(my_game->col_tx);
	if (my_game->end_tx)
		mlx_delete_texture(my_game->end_tx);
	if (my_game->backgr_tx)
		mlx_delete_texture(my_game->backgr_tx);
	if (my_game->fire_tx)
		mlx_delete_texture(my_game->fire_tx);
	if (my_game->gameover_tx)
		mlx_delete_texture(my_game->gameover_tx);
}

void	sl_free_images(t_game *my_game, t_map *my_map)
{
	if (my_game->char_img)
		mlx_delete_image(my_map->mlx, my_game->char_img);
	if (my_game->wall_img)
		mlx_delete_image(my_map->mlx, my_game->wall_img);
	if (my_game->col_img)
		mlx_delete_image(my_map->mlx, my_game->col_img);
	if (my_game->end_img)
		mlx_delete_image(my_map->mlx, my_game->end_img);
	if (my_game->backgr_img)
		mlx_delete_image(my_map->mlx, my_game->backgr_img);
	if (my_game->fire_img)
		mlx_delete_image(my_map->mlx, my_game->fire_img);
	if (my_game->gameover_img)
		mlx_delete_image(my_map->mlx, my_game->gameover_img);
	if (my_game->steps_img)
		mlx_delete_image(my_map->mlx, my_game->steps_img);
}

bool	sl_image_init(t_game *my_game, t_map *my_map)
{
	my_game->char_tx = mlx_load_png("textures/char.png");
	my_game->wall_tx = mlx_load_png("textures/wall.png");
	my_game->col_tx = mlx_load_png("textures/col.png");
	my_game->end_tx = mlx_load_png("textures/end.png");
	my_game->backgr_tx = mlx_load_png("textures/backgr.png");
	my_game->fire_tx = mlx_load_png("textures/fire.png");
	my_game->gameover_tx = mlx_load_png("textures/gameover.png");
	my_game->steps_img = mlx_new_image(my_map->mlx, 16, 16);
	if (my_game->char_tx == NULL || my_game->wall_tx == NULL || my_game->col_tx == NULL
		|| my_game->end_tx == NULL || my_game->backgr_tx == NULL
		|| my_game->fire_tx == NULL || my_game->gameover_tx == NULL
		|| my_game->steps_img == NULL)
		return (false);
	return (true);
}

bool	sl_text_to_img(t_map *my_map, t_game *my_game)
{
	my_game->char_img = mlx_texture_to_image(my_map->mlx, my_game->char_tx);
	my_game->wall_img = mlx_texture_to_image(my_map->mlx, my_game->wall_tx);
	my_game->col_img = mlx_texture_to_image(my_map->mlx, my_game->col_tx);
	my_game->end_img = mlx_texture_to_image(my_map->mlx, my_game->end_tx);
	my_game->backgr_img = mlx_texture_to_image(my_map->mlx, my_game->backgr_tx);
	my_game->fire_img = mlx_texture_to_image(my_map->mlx, my_game->fire_tx);
	my_game->gameover_img = mlx_texture_to_image(my_map->mlx, my_game->gameover_tx);
	if (my_game->char_img == NULL || my_game->wall_img == NULL
		|| my_game->col_img == NULL || my_game->end_img == NULL
		|| my_game->backgr_img == NULL || my_game->fire_img == NULL
		|| my_game->gameover_img == NULL)
		return (false);
	return (true);
}

bool	sl_place_images(t_map *my_map, t_game *my_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < my_map->length_y)
	{
		x = 0;
		while (x < my_map->length_x)
		{
			if (my_map->content[y][x] == '1')
				mlx_image_to_window(my_map->mlx, my_game->wall_img, x * 16, y
					* 16);
			else if (my_map->content[y][x] == 'C')
				mlx_image_to_window(my_map->mlx, my_game->col_img, x * 16, y * 16);
			else if (my_map->content[y][x] == 'E')
				mlx_image_to_window(my_map->mlx, my_game->end_img, x * 16, y * 16);
			else if (my_map->content[y][x] == 'P')
			{
				my_game->char_y = y;
				my_game->char_x = x;
				mlx_image_to_window(my_map->mlx, my_game->char_img, x * 16, y
					* 16);
			}
			else if (my_map->content[y][x] == 'F')
				mlx_image_to_window(my_map->mlx, my_game->fire_img, x * 16, y
					* 16);
			else
				mlx_image_to_window(my_map->mlx, my_game->backgr_img, x * 16, y
					* 16);
			x++;
		}
		y++;
	}
	return (true);
}

void	sl_clean_window(t_game *my_game, t_map *my_map)
{
	sl_free_textures(my_game);
	sl_free_images(my_game, my_map);
	mlx_terminate(my_map->mlx);
}

// void	ft_hook(void *pointer)
// {
// 	mlx_t	*mlx;

// 	mlx = (mlx_t *)pointer;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 5;
// }

static void	remove_collectible(t_map *my_map)
{
	const int		x = my_map->game.char_x * 16;
	const int		y = my_map->game.char_y * 16;
	int				i;
	mlx_instance_t	*check;

	i = 0;
	while (1)
	{
		check = &my_map->game.col_img->instances[i];
		if (check->x == x && check->y == y)
		{
			check->enabled = false;
			return ;
		}
		i++;
	}
}

static void	game_over(t_map *my_map)
{
	const int		x = my_map->game.char_x * 16;
	const int		y = my_map->game.char_y * 16;
	mlx_instance_t	*player;

	player = &my_map->game.char_img->instances[0];
	player->enabled = false;
	mlx_image_to_window(my_map->mlx, my_map->game.gameover_img, x, y);
	my_map->game.steps = 0;
	my_map->game.dead = 1;
}

void	check_move(t_map *my_map)
{
	if (my_map->content[my_map->game.char_y][my_map->game.char_x] == 'C')
	{
		my_map->c_count--;
		my_map->content[my_map->game.char_y][my_map->game.char_x] = '0';
		remove_collectible(my_map);
	}
	if (my_map->content[my_map->game.char_y][my_map->game.char_x] == 'E')
	{
		if (my_map->c_count != 0)
			return ;
		else
			mlx_close_window(my_map->mlx);
	}
	if (my_map->content[my_map->game.char_y][my_map->game.char_x] == 'F')
		game_over(my_map);
}

bool	sl_create_window(t_game *my_game, t_map *my_map)
{
	mlx_t	*mlx;

	mlx = mlx_init(my_map->length_x * 16, my_map->length_y * 16, "So_long",
			false);
	if (mlx == NULL)
		return (false);
	my_map->mlx = mlx;
	my_map->game.steps = 0;
	if (!sl_image_init(my_game, my_map))
		return (sl_clean_window(my_game, my_map), false);
	if (!sl_text_to_img(my_map, my_game))
		return (sl_clean_window(my_game, my_map), false);
	if (!sl_place_images(my_map, my_game))
		return (sl_clean_window(my_game, my_map), false);
	my_game->char_y = my_map->player_y;
	my_game->char_x = my_map->player_x;
	my_map->game.dead = 0;
	// printf("my_map->content[0][0] = %c\n", my_map->content[0][0]);
	// printf("my_map->content[0][1] = %c\n", my_map->content[0][1]);
	// printf("my_map->content[1][0] = %c\n", my_map->content[1][0]);
	// printf("my_map->content[1][1] = %c\n", my_map->content[1][1]);
	// printf("my_map->content[2][0] = %c\n", my_map->content[2][0]);
	// printf("my_map->player_x = %d\n", my_map->player_x);
	// printf("my_map->player_y = %d\n", my_map->player_y);
	// printf("my_map->game.char_y = %d\n", my_map->game.char_y);
	// printf("my_map->game.char_x = %d\n", my_map->game.char_x);
	mlx_key_hook(mlx, &my_keyhook, my_map);
	mlx_loop(my_map->mlx);
	sl_clean_window(my_game, my_map);
	return (true);
}

bool	sl_game(t_map *my_map)
{
	if (!sl_create_window(&my_map->game, my_map))
	{
		// free(my_game);
		return (false);
	}
	// free(my_game);
	return (true);
}
