/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:54:55 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/13 12:17:39 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_exit(t_game *game)
{
	xpm_t		*collectible;
	mlx_image_t	*collectible_i;

	collectible = mlx_load_xpm42("./img/collectible.xpm42");
	if (!collectible)
		return (ft_putendl_fd("Sprite load failed", 2));
	collectible_i = mlx_texture_to_image(game->mlx, &collectible->texture);
	if (!collectible_i)
		return (ft_putendl_fd("Image load failed", 2));
	game->sprites[2] = collectible_i;
	mlx_delete_xpm42(collectible);
}

static void	init_ground(t_game *game)
{
	xpm_t		*ground;
	mlx_image_t	*ground_i;

	ground = mlx_load_xpm42("./img/ground.xpm42");
	if (!ground)
		return (ft_putendl_fd("Sprite load failed", 2));
	ground_i = mlx_texture_to_image(game->mlx, &ground->texture);
	if (!ground_i)
		return (ft_putendl_fd("Image load failed", 2));
	game->sprites[1] = ground_i;
	mlx_delete_xpm42(ground);
}

static void	init_wall(t_game *game)
{
	xpm_t		*wall;
	mlx_image_t	*wall_i;

	wall = mlx_load_xpm42("./img/wall.xpm42");
	if (!wall)
		return (ft_putendl_fd("Sprite load failed", 2));
	wall_i = mlx_texture_to_image(game->mlx, &wall->texture);
	if (!wall_i)
		return (ft_putendl_fd("Image load failed", 2));
	game->sprites[0] = wall_i;
	mlx_delete_xpm42(wall);
}

static void	init_collectibles(t_game *game)
{
	xpm_t		*exit;
	mlx_image_t	*exit_i;

	exit = mlx_load_xpm42("./img/exit.xpm42");
	if (exit == NULL)
		return (ft_putendl_fd("Sprite load failed", 2));
	exit_i = mlx_texture_to_image(game->mlx, &exit->texture);
	if (!exit_i)
		return (ft_putendl_fd("Image load failed", 2));
	game->sprites[3] = exit_i;
	mlx_delete_xpm42(exit);
}

void	init_textures(t_game *game)
{
	init_wall(game);
	init_ground(game);
	init_exit(game);
	init_collectibles(game);
}
