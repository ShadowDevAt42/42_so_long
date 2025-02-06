/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_collectible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:49:51 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 04:34:54 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'C')
				render_coin(game, x, y);
			x++;
		}
		y++;
	}
}
