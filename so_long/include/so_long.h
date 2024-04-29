/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/26 19:46:49 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/04/29 23:51:57 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"
// # include "./MLX42.h"
// # include "./MLX42_Int.h"
# include "../MLX42/include/MLX42/MLX42.h"
// # include "../MLX42/include/MLX42/MLX42_Int.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_game
{
	mlx_texture_t	*char_tx;
	mlx_image_t		*char_img;
	mlx_texture_t	*wall_tx;
	mlx_image_t		*wall_img;
	mlx_texture_t	*col_tx;
	mlx_image_t		*col_img;
	mlx_texture_t	*end_tx;
	mlx_image_t		*end_img;
	mlx_texture_t	*backgr_tx;
	mlx_image_t		*backgr_img;
	mlx_texture_t	*fire_tx;
	mlx_image_t		*fire_img;
	mlx_texture_t	*gameover_tx;
	mlx_image_t		*gameover_img;
	mlx_image_t		*steps_img;
	int				char_y;
	int				char_x;
	int				steps;
	int				dead;
}					t_game;

typedef struct s_map
{
	int				length_x;
	int				length_y;
	char			**content;
	char			**dup_content;
	int				e_count;
	int				p_count;
	int				c_count;
	int				player_x;
	int				player_y;
	mlx_t			*mlx;
	t_game			game;
}					t_map;

// typedef struct s_pos
// {
// 	int		x;
// 	int		y;
// 	bool	visited;
// }	t_pos;

// main.c

char				**sl_map_dup(char **map, int length_x, int length_y);
t_map				*sl_map_init(char **map);

// map_check.c

bool				sl_check_size_prob(t_map *my_map);
bool				sl_check_character_prob(t_map *my_map);
bool				sl_map_empty_line_prob(t_map *my_map);

// map_check2.c

bool				sl_check_extension_prob(char *str);
bool				sl_check_side_wall_prob(t_map *my_map);
bool				sl_check_up_down_wall_prob(t_map *my_map);

// flood_fill.c

bool				sl_check_floodfill_prob(t_map *my_map);

// game.c

bool				sl_game(t_map *my_map);

// utils.c

char				*sl_strjoin(char *s1, char *s2);
void				free_maps(char **map, t_map *my_map);
int					count_lines(char **matrix);
void				*free_matrix(char **string);

// utils2.c

int					sl_strlen(char *str);
char				**sl_split(char const *s, char c);

#endif
