/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:14:40 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 18:16:58 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H

typedef enum e_error
{
	ERR_NONE,
	ERR_ARGS,
	ERR_EXTENSION,
	ERR_OPEN,
	ERR_EMPTY,
	ERR_MALLOC,
	ERR_INVALID_CHAR,
	ERR_NOT_RECT,
	ERR_NO_WALLS,
	ERR_NO_PLAYER,
	ERR_MULTI_PLAYER,
	ERR_NO_EXIT,
	ERR_MULTI_EXIT,
	ERR_NO_COLLECT,
	ERR_TOO_BIG,
	ERR_PATH,
	ERR_MLX_INIT,
	ERR_WIN_INIT,
	ERR_SPRITE_LOAD,
	ERR_IMG_CREATE,
	ERR_SPRITE_PATH
}	t_error;

typedef struct s_error_info
{
	char	*sprite_path;
	char	*additional_info;
}	t_error_info;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	wall;
	t_img	player;
	t_img	collectible;
	t_img	exit;
	t_img	exit_open;
	t_img	background;
	t_map	*map;
	int		moves;
	int		collected;
	int		on_exit;
}	t_game;

#endif
