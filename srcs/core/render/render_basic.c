/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/09 02:38:10 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

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
	int	pos_x;
	int	pos_y;

	pos_x = game->map->player_x * SPRITE_SIZE;
	pos_y = game->map->player_y * SPRITE_SIZE;
	render_sprite(game, &game->player, pos_x, pos_y);
}

void	render_bomb(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == '?')
				render_sprite(game, &game->bomb, x * SPRITE_SIZE,
					y * SPRITE_SIZE);
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
