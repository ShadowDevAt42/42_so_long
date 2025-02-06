/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:50:06 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 03:42:41 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_exit(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->grid[i][j] == 'E')
			{
				if (game->collected == game->map->collectibles 
					&& !game->portal.is_open)
				{
					game->portal.is_open = 1;
					start_portal_anim(game);
				}
				render_portal(game, j, i);
			}
			j++;
		}
		i++;
	}
}
