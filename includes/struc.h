/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:14:40 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 00:23:17 by fdi-tria         ###   ########.fr       */
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
	ERR_SPRITE_PATH,
	ERR_CUSTOM
}	t_error;

typedef struct s_error_msg
{
	t_error	code;
	char	*message;
}	t_error_msg;

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

typedef struct s_corner
{
	t_img	top_left;
	t_img	top_right;
	t_img	bottom_left;
	t_img	bottom_right;
}	t_corner;

typedef struct s_portal_anim
{
	t_img	frames[6];
	int		current_frame;
	int		is_animating;
	int		is_open;
}	t_portal_anim;

typedef struct s_coin_anim
{
	t_img	frames[9];
	int		current_frame;
	int		is_animating;
}	t_coin_anim;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		wall;
	t_img		wall_top;
	t_img		wall_bottom;
	t_img		wall_left;
	t_img		wall_right;
	t_img		player;
	t_img		exit;
	t_img		background;
	t_img		ui_one;
	t_img		ui_two;
	t_img		ui_coll_one;
	t_img		ui_coll_two;
	t_map		*map;
	t_corner	corner;
	t_portal_anim	portal;
	t_coin_anim	coin;    // Nouvelle structure pour l'animation des pièces
	int			moves;
	int			collected;
	int			on_exit;
}	t_game;

#endif
