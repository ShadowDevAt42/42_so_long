/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:50:06 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 17:32:56 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'E')
			{
				if (game->collected == game->map->collectibles)
					mlx_put_image_to_window(game->mlx, game->win,
						game->exit_open.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
				else
					mlx_put_image_to_window(game->mlx, game->win,
						game->exit.img, x * SPRITE_SIZE, y * SPRITE_SIZE);
			}
			x++;
		}
		y++;
	}
}
