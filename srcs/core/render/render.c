/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:49 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 18:15:56 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	render_portal_if_needed(t_game *game)
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
				render_exit(game);
				return ;
			}
			j++;
		}
		i++;
	}
}

int	render_next_frame(void *param)
{
	static int	portal_counter;
	static int	coin_counter;
	t_game		*game;

	game = (t_game *)param;
	portal_counter++;
	coin_counter++;

	if (game->portal.is_animating)
	{
		int speed = game->portal.in_transition ? 
			PORTAL_TRANSITION_SPEED : PORTAL_OPEN_SPEED;
		if (portal_counter >= speed)
		{
			portal_counter = 0;
			update_portal_anim(game);
			render_portal_if_needed(game);
		}
	}

	if (coin_counter >= COIN_ANIM_SPEED)
	{
		coin_counter = 0;
		update_coin_anim(game);
		render_collectibles(game);
	}

	return (0);
}

void	render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_background(game);
	render_walls(game);
	render_corner(game);
	render_collectibles(game);
	render_portal_if_needed(game);
	render_player(game);
	render_ui(game);
	render_collectibles_ui(game);
}
