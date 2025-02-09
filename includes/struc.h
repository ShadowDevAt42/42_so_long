/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:14:40 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/09 02:38:29 by fdi-tria         ###   ########.fr       */
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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_rect
{
	int	width;
	int	height;
}	t_rect;

typedef struct s_wall_pos
{
	int	x;
	int	y;
	int	rect_x;
	int	rect_y;
	int	width;
	int	height;
	int	is_top;
	int	is_bottom;
	int	is_left;
	int	is_right;
	int	is_corner;
}	t_wall_pos;

typedef struct s_wall_info
{
	int	x;
	int	y;
	int	has_left;
	int	has_right;
	int	has_top;
	int	has_bottom;
}	t_wall_info;

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

typedef struct s_text
{
	int		x;
	int		y;
	int		color;
	char	*str;
}	t_text;

typedef struct s_corner
{
	t_img	top_left;
	t_img	top_right;
	t_img	bottom_left;
	t_img	bottom_right;
}	t_corner;

typedef struct s_portal_anim
{
	t_img	transition_frames[24];
	t_img	open_frames[6];
	int		current_frame;
	int		is_animating;
	int		is_open;
	int		in_transition;
	int		transition_done;
}	t_portal_anim;

typedef struct s_coin_anim
{
	t_img	frames[9];
	int		current_frame;
	int		is_animating;
}	t_coin_anim;

typedef struct s_wall
{
	t_img	wall;
	t_img	top;
	t_img	bottom;
	t_img	left;
	t_img	right;
	t_img	int_h_left;
	t_img	int_h_right;
	t_img	int_h_center;
	t_img	int_v_top;
	t_img	int_v_center;
	t_img	int_v_bottom;
	t_img	int_m_ctl;
	t_img	int_m_ctr;
	t_img	int_m_cbl;
	t_img	int_m_cbr;
	t_img	int_m_wt;
	t_img	int_m_wb;
	t_img	int_m_wl;
	t_img	int_m_wr;
	t_img	int_m_center;
}	t_wall;

typedef struct s_ui
{
	t_img	one;
	t_img	two;
	t_img	coll_one;
	t_img	coll_two;
}	t_ui;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_wall			wall;
	t_img			player;
	t_img			exit;
	t_img			background;
	t_map			*map;
	t_corner		corner;
	t_portal_anim	portal;
	t_coin_anim		coin;
	t_ui			ui;
	int				moves;
	int				collected;
	int				on_exit;
	t_img			bomb;
}	t_game;

#endif
