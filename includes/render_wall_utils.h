/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_utils.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:57:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/09 00:56:27 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_WALL_UTILS_H
# define RENDER_WALL_UTILS_H

// Basic rendering functions
void		render_background(t_game *game);
void		render_player(t_game *game);
void		render_corner(t_game *game);

// Wall detection functions
int			is_wall(t_game *game, int x, int y);
void		get_rect_size(t_game *game, int x, int y, t_rect *rect);
int			check_rect_walls(t_game *game, int x, int y, t_rect rect);
int			is_uniform_rect(t_game *game, int x, int y, t_rect *rect);
int			find_rect_start(t_game *game, int x, int y, t_point *start);
int			is_border_wall(t_game *game, int x, int y);

// Wall rendering utility functions
void		render_rect_wall_corners(t_game *game, t_wall_pos pos);
void		render_rect_wall_edges(t_game *game, t_wall_pos pos);
void		render_rect_wall(t_game *game, t_wall_pos pos);
void		render_vert_wall(t_game *game, int x, int y);
void		handle_horiz_wall(t_game *game, t_wall_info info);

// Wall position and rendering functions
t_wall_info	get_wall_info(t_game *game, int x, int y);
t_wall_pos	init_wall_pos(int x, int y, t_point start, t_rect rect);
void		handle_non_rect_wall(t_game *game, int x, int y);
void		handle_rect_wall(t_game *game, int x, int y, t_point start);
void		render_internal_wall(t_game *game, int x, int y);
void		render_wall_type(t_game *game, int x, int y);
void		render_walls(t_game *game);

#endif
