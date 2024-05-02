/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/01 12:06:43 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/02 17:46:03 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *pointer)
{
	char	*steps_str;
	t_map	*my_map;

	my_map = pointer;
	steps_str = 0;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(my_map->mlx);
	steps_str = ft_itoa(my_map->game.steps);
	if (my_map->game.dead != 1)
	{
		keyboard_down(&keydata, my_map, steps_str);
		keyboard_up(&keydata, my_map, steps_str);
		keyboard_right(&keydata, my_map, steps_str);
		keyboard_left(&keydata, my_map, steps_str);
	}
	free(steps_str);
	check_move(my_map);
}

// void	keyboard_play(void *pointer)
// {
// 	t_map			*my_map;
// 	char			*steps_str;
// 	mlx_key_data_t	*keydata;
// 	mlx_keyfunc		keyboard_press;
// 	typedef void	(*mlx_keyfunc)(mlx_key_data_t keydata, void *param);

// 	keyboard_press = (mlx_keyfunc)keyboard_play;
// 	keydata = malloc(sizeof(mlx_key_data_t));
// 	if (keydata == NULL)
// 		return ;
// 	my_map = pointer;
// 	steps_str = 0;
// 	mlx_key_hook(my_map->mlx, keyboard_play, my_map);
// 	steps_str = ft_itoa(my_map->game.steps);
// 	if (my_map->game.dead != 1)
// 	{
// 		keyboard_down(keydata, my_map, steps_str);
// 		keyboard_up(keydata, my_map, steps_str);
// 		keyboard_right(keydata, my_map, steps_str);
// 		keyboard_left(keydata, my_map, steps_str);
// 	}
// 	free(steps_str);
// 	check_move(my_map);
// }

void	keyboard_down(mlx_key_data_t *keydata, t_map *my_map, char *steps_str)
{
	if (keydata->key == MLX_KEY_DOWN && my_map->content[my_map->game.char_y + 1][my_map->game.char_x] != '1')
	{
		my_map->game.steps++;
		mlx_delete_image(my_map->mlx, my_map->game.steps_img);
		my_map->game.steps_img = mlx_put_string(my_map->mlx, steps_str, 1, 2);
		my_map->game.char_y++;
		my_map->game.char_img->instances[0].y += 32;
	}
}

void	keyboard_up(mlx_key_data_t *keydata, t_map *my_map, char *steps_str)
{
	if (keydata->key == MLX_KEY_UP && my_map->content[my_map->game.char_y - 1][my_map->game.char_x] != '1')
	{
		my_map->game.steps++;
		mlx_delete_image(my_map->mlx, my_map->game.steps_img);
		my_map->game.steps_img = mlx_put_string(my_map->mlx, steps_str, 1, 2);
		my_map->game.char_y--;
		my_map->game.char_img->instances[0].y -= 32;
	}
}

void	keyboard_right(mlx_key_data_t *keydata, t_map *my_map, char *steps_str)
{
	if (keydata->key == MLX_KEY_RIGHT && my_map->content[my_map->game.char_y][my_map->game.char_x + 1] != '1')
	{
		my_map->game.steps++;
		mlx_delete_image(my_map->mlx, my_map->game.steps_img);
		my_map->game.steps_img = mlx_put_string(my_map->mlx, steps_str, 1, 2);
		my_map->game.char_x++;
		my_map->game.char_img->instances[0].x += 32;
	}
}

void	keyboard_left(mlx_key_data_t *keydata, t_map *my_map, char *steps_str)
{
	if (keydata->key == MLX_KEY_LEFT && my_map->content[my_map->game.char_y][my_map->game.char_x - 1] != '1')
	{
		my_map->game.steps++;
		mlx_delete_image(my_map->mlx, my_map->game.steps_img);
		my_map->game.steps_img = mlx_put_string(my_map->mlx, steps_str, 1, 2);
		my_map->game.char_x--;
		my_map->game.char_img->instances[0].x -= 32;
	}
}
