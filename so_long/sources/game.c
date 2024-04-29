/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/29 20:35:53 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/29 23:53:13 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	sl_free_textures(t_game *game)
{
	if (game->char_tx)
		mlx_delete_texture(game->char_tx);
	if (game->wall_tx)
		mlx_delete_texture(game->wall_tx);
	if (game->col_tx)
		mlx_delete_texture(game->col_tx);
	if (game->end_tx)
		mlx_delete_texture(game->end_tx);
	if (game->backgr_tx)
		mlx_delete_texture(game->backgr_tx);
	if (game->fire_tx)
		mlx_delete_texture(game->fire_tx);
	if (game->gameover_tx)
		mlx_delete_texture(game->gameover_tx);
}

void	sl_free_images(t_game *game)
{
	if (game->char_img)
		mlx_delete_image(game->char_img);
	if (game->wall_img)
		mlx_delete_image(game->wall_img);
	if (game->col_img)
		mlx_delete_image(game->col_img);
	if (game->end_img)
		mlx_delete_image(game->end_img);
	if (game->backgr_img)
		mlx_delete_image(game->backgr_img);
	if (game->fire_img)
		mlx_delete_image(game->fire_img);
	if (game->gameover_img)
		mlx_delete_image(game->gameover_img);
	if (game->steps_img)
		mlx_delete_image(game->steps_img);
}

bool	sl_image_init(game)
{
	game->char_tx = mlx_load_png("textures/char.png");
	game->wall_tx = mlx_load_png("textures/wall.png");
	game->col_tx = mlx_load_png("textures/col.png");
	game->end_tx = mlx_load_png("textures/end.png");
	game->backgr_tx = mlx_load_png("textures/backgr.png");
	game->fire_tx = mlx_load_png("textures/fire.png");
	game->gameover_tx = mlx_load_png("textures/gameover.png");
	game->steps_img = mlx_new_image(mlx, 64, 64);
	if (game->char_tx == NULL || game->wall_tx == NULL || game->col_tx == NULL
		|| game->end_tx == NULL || game->backgr_tx == NULL
		|| game->fire_tx == NULL || game->gameover_tx == NULL
		|| game->steps_img == NULL)
		return (false);
	return (true);
}

bool	sl_text_to_img(t_map *my_map, t_game *game)
{
	game->char_img = mlx_texture_to_image(my_map->mlx, game->char_tx);
	game->wall_img = mlx_texture_to_image(my_map->mlx, game->wall_tx);
	game->col_img = mlx_texture_to_image(my_map->mlx, game->col_tx);
	game->end_img = mlx_texture_to_image(my_map->mlx, game->end_tx);
	game->backgr_img = mlx_texture_to_image(my_map->mlx, game->backgr_tx);
	game->fire_img = mlx_texture_to_image(my_map->mlx, game->fire_tx);
	game->gameover_img = mlx_texture_to_image(my_map->mlx, game->gameover_tx);
	if (game->char_img == NULL || game->wall_img == NULL
		|| game->col_img == NULL || game->end_img == NULL
		|| game->backgr_img == NULL || game->fire_img == NULL
		|| game->gameover_img == NULL)
		return (false);
	return (true);
}

bool	sl_place_images(t_map *my_map, t_game *game)
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
				mlx_image_to_window(my_map->mlx, game->wall_img, x * 32, y
					* 32);
			else if (my_map->content[y][x] == 'C')
				mlx_image_to_window(my_map->mlx, game->col_img, x * 32, y * 32);
			else if (my_map->content[y][x] == 'E')
				mlx_image_to_window(my_map->mlx, game->end_img, x * 32, y * 32);
			else if (my_map->content[y][x] == 'P')
			{
				game->char_y = y;
				game->char_x = x;
				mlx_image_to_window(my_map->mlx, game->char_img, x * 32, y
					* 32);
			}
			else if (my_map->content[y][x] == 'F')
				mlx_image_to_window(my_map->mlx, game->fire_img, x * 32, y
					* 32);
			else
				mlx_image_to_window(my_map->mlx, game->backgr_img, x * 32, y
					* 32);
			x++;
		}
		y++;
	}
	return (true);
}

void	sl_clean_window(t_game *game, t_map *my_map)
{
	sl_free_textures(game);
	sl_free_images(game);
	mlx_terminate(my_map->mlx);
}

void	ft_hook(void *pointer)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)pointer;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

bool	sl_create_window(t_game *game, t_map *my_map)
{
	mlx_t	*mlx;

	my_map->game = game;
	my_map->mlx = mlx;
	mlx = mlx_init(map->length_x * 64, map->length_y * 64, "So_long", false);
	if (mlx == NULL)
		return (false);
	my_map->game.steps = 0;
	if (!sl_image_init(game))
		return (sl_clean_window(game, my_map), false);
	if (!sl_text_to_img(my_map, game))
		return (sl_clean_window(game, my_map), false);
	if (!sl_place_images(my_map, game))
		return (sl_clean_window(game, my_map), false);
	game->char_y = my_map->player_y;
	game->char_x = my_map->player_x;
	my_map->game.dead = 0;
	mlx_loop_hook(my_map->mlx, ft_hook, my_map->mlx);
	mlx_loop(my_map->mlx);
	sl_clean_window(game, my_map);
	return (true);
}

bool	sl_game(t_map *my_map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		return (false);
	if (!sl_create_window(game, my_map))
	{
		free(game);
		return (false);
	}
	free(game);
	return (true);
}
