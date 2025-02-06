/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:02:22 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 01:13:27 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	render_wall_at(t_game *game, int x, int y, t_img *wall)
{
	mlx_put_image_to_window(game->mlx, game->win, wall->img,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
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
			{
				if (y == 0)  // Top row
					render_wall_at(game, x, y, &game->wall_top);
				else if (y == game->map->height - 1)  // Bottom row
					render_wall_at(game, x, y, &game->wall_bottom);
				else if (x == 0)  // Left wall
					render_wall_at(game, x, y, &game->wall_left);
				else if (x == game->map->width - 1)  // Right wall
					render_wall_at(game, x, y, &game->wall_right);
				else  // Middle walls
					render_wall_at(game, x, y, &game->wall);
			}
			x++;
		}
		y++;
	}
}
