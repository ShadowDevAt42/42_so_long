/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_static_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 21:30:52 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '0')
				render_sprite(game, &game->background, x * SPRITE_SIZE,
					y * SPRITE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	render_sprite(game, &game->player, game->map->player_x * SPRITE_SIZE,
		game->map->player_y * SPRITE_SIZE);
}

static int	is_wall(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (0);
	return (game->map->grid[y][x] == '1');
}

static void	get_rectangle_size(t_game *game, int x, int y, int *width, int *height)
{
	int	w;
	int	h;

	w = 0;
	while (x + w < game->map->width && is_wall(game, x + w, y))
		w++;
	h = 0;
	while (y + h < game->map->height)
	{
		int i = 0;
		while (i < w && is_wall(game, x + i, y + h))
			i++;
		if (i < w)
			break;
		h++;
	}
	*width = w;
	*height = h;
}

static int	is_uniform_rectangle(t_game *game, int x, int y, int *width, int *height)
{
	get_rectangle_size(game, x, y, width, height);
	if (*width < 2 || *height < 2)
		return (0);

	// Check if rectangle touches map border
	if (x == 0 || y == 0 || x + *width == game->map->width || y + *height == game->map->height)
		return (0);

	// Check if all cells in rectangle are walls
	for (int j = 0; j < *height; j++)
	{
		for (int i = 0; i < *width; i++)
		{
			if (!is_wall(game, x + i, y + j))
				return (0);
		}
	}
	return (1);
}

static void	render_rectangle_wall(t_game *game, int x, int y, int rect_x, int rect_y,
		int width, int height)
{
	int	is_top = (rect_y == 0);
	int	is_bottom = (rect_y == height - 1);
	int	is_left = (rect_x == 0);
	int	is_right = (rect_x == width - 1);

	if (is_top && is_left)
		render_sprite(game, &game->wall.int_m_ctl, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (is_top && is_right)
		render_sprite(game, &game->wall.int_m_ctr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (is_bottom && is_left)
		render_sprite(game, &game->wall.int_m_cbl, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (is_bottom && is_right)
		render_sprite(game, &game->wall.int_m_cbr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (is_top)
		render_sprite(game, &game->wall.int_m_wt, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (is_bottom)
		render_sprite(game, &game->wall.int_m_wb, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (is_left)
		render_sprite(game, &game->wall.int_m_wl, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (is_right)
		render_sprite(game, &game->wall.int_m_wr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else
		render_sprite(game, &game->wall.int_m_center, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

static void	render_vertical_wall(t_game *game, int x, int y)
{
	int	has_top;
	int	has_bottom;

	has_top = is_wall(game, x, y - 1);
	has_bottom = is_wall(game, x, y + 1);

	// Skip if any adjacent wall is a border wall
	if (has_top && y - 1 == 0)
		has_top = 0;
	if (has_bottom && y + 1 == game->map->height - 1)
		has_bottom = 0;

	if (has_top && has_bottom)
		render_sprite(game, &game->wall.int_v_center, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (has_bottom && !has_top)
		render_sprite(game, &game->wall.int_v_top, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (has_top && !has_bottom)
		render_sprite(game, &game->wall.int_v_bottom, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else
		render_sprite(game, &game->wall.wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

static int	find_rectangle_start(t_game *game, int x, int y, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = x;
	while (i >= 0 && is_wall(game, i - 1, y))
		i--;
	j = y;
	while (j >= 0 && is_wall(game, i, j - 1))
		j--;
	*start_x = i;
	*start_y = j;
	return (1);
}

static int	is_border_wall(t_game *game, int x, int y)
{
	return (x == 0 || y == 0 || x == game->map->width - 1 || y == game->map->height - 1);
}

static void	render_internal_wall(t_game *game, int x, int y)
{
	int	width;
	int	height;
	int	start_x;
	int	start_y;

	// Skip border walls
	if (is_border_wall(game, x, y))
	{
		render_sprite(game, &game->wall.wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
		return;
	}

	if (find_rectangle_start(game, x, y, &start_x, &start_y) &&
		is_uniform_rectangle(game, start_x, start_y, &width, &height))
	{
		render_rectangle_wall(game, x, y, x - start_x, y - start_y, width, height);
		return;
	}

	int	has_left = is_wall(game, x - 1, y);
	int	has_right = is_wall(game, x + 1, y);
	int	has_top = is_wall(game, x, y - 1);
	int	has_bottom = is_wall(game, x, y + 1);

	// Skip if any adjacent wall is a border wall
	if (has_left && x - 1 == 0)
		has_left = 0;
	if (has_right && x + 1 == game->map->width - 1)
		has_right = 0;
	if (has_top && y - 1 == 0)
		has_top = 0;
	if (has_bottom && y + 1 == game->map->height - 1)
		has_bottom = 0;

	// Check if wall is adjacent to a border
	if (x == 1 || x == game->map->width - 2)
	{
		render_sprite(game, &game->wall.wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
		return;
	}

	if (has_left || has_right)
	{
		if (has_left && has_right)
			render_sprite(game, &game->wall.int_h_center, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else if (has_right)
			render_sprite(game, &game->wall.int_h_left, x * SPRITE_SIZE, y * SPRITE_SIZE);
		else
			render_sprite(game, &game->wall.int_h_right, x * SPRITE_SIZE, y * SPRITE_SIZE);
	}
	else if ((has_top || has_bottom) && x > 1 && x < game->map->width - 2)
		render_vertical_wall(game, x, y);
	else
		render_sprite(game, &game->wall.wall, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

static void	render_wall_type(t_game *game, int x, int y)
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

void	render_walls(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '1')
				render_wall_type(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_corner(t_game *game)
{
	int	tile_w;
	int	tile_h;

	if (!game || !game->mlx || !game->win || !game->corner.top_left.img
		|| !game->corner.top_right.img || !game->corner.bottom_left.img
		|| !game->corner.bottom_right.img)
		return ;
	tile_w = game->corner.top_left.width;
	tile_h = game->corner.top_left.height;
	render_sprite(game, &game->corner.top_left, 0, 0);
	render_sprite(game, &game->corner.top_right,
		(game->map->width - 1) * tile_w, 0);
	render_sprite(game, &game->corner.bottom_left, 0,
		(game->map->height - 1) * tile_h);
	render_sprite(game, &game->corner.bottom_right,
		(game->map->width - 1) * tile_w, (game->map->height - 1) * tile_h);
}
