/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 22:13:15 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

t_wall_pos	init_wall_pos(int x, int y, t_point start, t_rect rect)
{
	t_wall_pos	pos;

	pos.x = x;
	pos.y = y;
	pos.rect_x = x - start.x;
	pos.rect_y = y - start.y;
	pos.width = rect.width;
	pos.height = rect.height;
	pos.is_top = (y - start.y == 0);
	pos.is_bottom = (y - start.y == rect.height - 1);
	pos.is_left = (x - start.x == 0);
	pos.is_right = (x - start.x == rect.width - 1);
	pos.is_corner = ((y - start.y == 0 || y - start.y == rect.height - 1)
			&& (x - start.x == 0 || x - start.x == rect.width - 1));
	return (pos);
}

void	handle_non_rect_wall(t_game *game, int x, int y)
{
	t_wall_info	info;

	info = get_wall_info(game, x, y);
	if (info.has_left || info.has_right)
		handle_horiz_wall(game, info);
	else if ((info.has_top || info.has_bottom) && x > 1
		&& x < game->map->width - 2)
		render_vert_wall(game, x, y);
	else
		render_sprite(game, &game->wall.wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	handle_rect_wall(t_game *game, int x, int y, t_point start)
{
	t_rect		rect;
	t_wall_pos	pos;

	if (is_uniform_rect(game, start.x, start.y, &rect))
	{
		pos = init_wall_pos(x, y, start, rect);
		render_rect_wall(game, pos);
	}
	else
		handle_non_rect_wall(game, x, y);
}

void	render_internal_wall(t_game *game, int x, int y)
{
	t_point	start;

	if (is_border_wall(game, x, y))
	{
		render_sprite(game, &game->wall.wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
		return ;
	}
	if (!find_rect_start(game, x, y, &start))
	{
		handle_non_rect_wall(game, x, y);
		return ;
	}
	handle_rect_wall(game, x, y, start);
}

void	render_wall_type(t_game *game, int x, int y)
{
	if (y == 0)
		render_sprite(game, &game->wall.top, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (y == game->map->height - 1)
		render_sprite(game, &game->wall.bottom,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (x == 0)
		render_sprite(game, &game->wall.left, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (x == game->map->width - 1)
		render_sprite(game, &game->wall.right,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else
		render_internal_wall(game, x, y);
}
