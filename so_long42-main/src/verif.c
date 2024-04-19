/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vphilipp <vphilipp@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:58:22 by vphilipp          #+#    #+#             */
/*   Updated: 2023/12/13 13:28:40 by vphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->ref_matrix[j][i] != '1' && (j == 0 || i == 0
					|| i == game->rows - 1 || j == game->lines - 1))
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	check_shape(t_game *game)
{
	int		k;
	size_t	base_len;

	k = 0;
	base_len = ft_strlen(game->matrix[k]);
	while (k < game->lines)
	{
		if (ft_strlen(game->matrix[k]) != base_len)
			return (1);
		k++;
	}
	return (0);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (check_bounds(y, x, game))
	{
		if (game->matrix[y][x] == '.')
			return ;
		if (game->matrix[y][x] == 'C')
			game->total_collectables++;
		game->matrix[y][x] = '.';
		flood_fill(game, x - 1, y);
		flood_fill(game, x + 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
	return ;
}

int	check_collectables(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->ref_matrix[j][i] == 'C')
			{
				if (game->matrix[j][i] != '.')
					return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (game->total_collectables < 1)
		return (1);
	else
		return (0);
}

int	check_exit(t_game *game)
{
	int	i;
	int	j;
	int	c[2];

	j = 0;
	i = 0;
	c[0] = 0;
	c[1] = 0;
	while (j < game->lines)
	{
		while (i < game->rows)
		{
			if (game->ref_matrix[j][i] == 'E')
				c[0]++;
			if (game->ref_matrix[j][i] == 'P')
				c[1]++;
			i++;
		}
		i = 0;
		j++;
	}
	if (game->matrix[game->end_y][game->end_x] == '.' && c[0] == 1 && c[1] == 1)
		return (0);
	else
		return (1);
}
