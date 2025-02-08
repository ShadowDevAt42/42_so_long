/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 22:13:15 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/render_wall_utils.h"

void	render_rect_wall_corners(t_game *game, t_wall_pos pos)
{
	int	x_pos;
	int	y_pos;

	x_pos = pos.x * SPRITE_SIZE;
	y_pos = pos.y * SPRITE_SIZE;
	if (pos.is_top && pos.is_left)
		render_sprite(game, &game->wall.int_m_ctl, x_pos, y_pos);
	else if (pos.is_top && pos.is_right)
		render_sprite(game, &game->wall.int_m_ctr, x_pos, y_pos);
	else if (pos.is_bottom && pos.is_left)
		render_sprite(game, &game->wall.int_m_cbl, x_pos, y_pos);
	else if (pos.is_bottom && pos.is_right)
		render_sprite(game, &game->wall.int_m_cbr, x_pos, y_pos);
}

void	render_rect_wall_edges(t_game *game, t_wall_pos pos)
{
	int	x_pos;
	int	y_pos;

	x_pos = pos.x * SPRITE_SIZE;
	y_pos = pos.y * SPRITE_SIZE;
	if (pos.is_top)
		render_sprite(game, &game->wall.int_m_wt, x_pos, y_pos);
	else if (pos.is_bottom)
		render_sprite(game, &game->wall.int_m_wb, x_pos, y_pos);
	else if (pos.is_left)
		render_sprite(game, &game->wall.int_m_wl, x_pos, y_pos);
	else if (pos.is_right)
		render_sprite(game, &game->wall.int_m_wr, x_pos, y_pos);
	else
		render_sprite(game, &game->wall.int_m_center, x_pos, y_pos);
}

void	render_rect_wall(t_game *game, t_wall_pos pos)
{
	render_rect_wall_corners(game, pos);
	if (!pos.is_corner)
		render_rect_wall_edges(game, pos);
}

void	render_vert_wall(t_game *game, int x, int y)
{
	int	has_top;
	int	has_bottom;
	int	x_pos;
	int	y_pos;

	has_top = is_wall(game, x, y - 1);
	has_bottom = is_wall(game, x, y + 1);
	if (has_top && y - 1 == 0)
		has_top = 0;
	if (has_bottom && y + 1 == game->map->height - 1)
		has_bottom = 0;
	x_pos = x * SPRITE_SIZE;
	y_pos = y * SPRITE_SIZE;
	if (has_top && has_bottom)
		render_sprite(game, &game->wall.int_v_center, x_pos, y_pos);
	else if (has_bottom && !has_top)
		render_sprite(game, &game->wall.int_v_top, x_pos, y_pos);
	else if (has_top && !has_bottom)
		render_sprite(game, &game->wall.int_v_bottom, x_pos, y_pos);
	else
		render_sprite(game, &game->wall.wall, x_pos, y_pos);
}

void	handle_horiz_wall(t_game *game, t_wall_info info)
{
	int	x_pos;
	int	y_pos;

	x_pos = info.x * SPRITE_SIZE;
	y_pos = info.y * SPRITE_SIZE;
	if (info.has_left && info.has_right)
		render_sprite(game, &game->wall.int_h_center, x_pos, y_pos);
	else if (info.has_right)
		render_sprite(game, &game->wall.int_h_left, x_pos, y_pos);
	else
		render_sprite(game, &game->wall.int_h_right, x_pos, y_pos);
}
