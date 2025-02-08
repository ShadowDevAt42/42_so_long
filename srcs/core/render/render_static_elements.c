/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_static_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 19:20:20 by fdi-tria         ###   ########.fr       */
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

static void	render_internal_wall(t_game *game, int x, int y)
{
	int	has_left;
	int	has_right;

	has_left = is_wall(game, x - 1, y);
	has_right = is_wall(game, x + 1, y);

	if (has_left && has_right)
		render_sprite(game, &game->wall.int_h_center, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (has_right)
		render_sprite(game, &game->wall.int_h_left, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else if (has_left)
		render_sprite(game, &game->wall.int_h_right, x * SPRITE_SIZE, y * SPRITE_SIZE);
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
