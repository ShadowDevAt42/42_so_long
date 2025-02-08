/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:49 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/09 00:24:20 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	handle_portal_animation(t_game *game, int *counter)
{
	int	speed;

	speed = PORTAL_OPEN_SPEED;
	if (game->portal.in_transition)
		speed = PORTAL_TRANSITION_SPEED;
	if (*counter >= speed)
	{
		*counter = 0;
		update_portal_anim(game);
		render_exit(game);
	}
}

static void	handle_coin_animation(t_game *game, int *counter)
{
	if (*counter >= COIN_ANIM_SPEED)
	{
		*counter = 0;
		update_coin_anim(game);
		render_collectibles(game);
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
		handle_portal_animation(game, &portal_counter);
	handle_coin_animation(game, &coin_counter);
	return (0);
}

void	render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_background(game);
	render_walls(game);
	render_corner(game);
	render_collectibles(game);
	render_exit(game);
	render_player(game);
	render_ui(game);
	render_collectibles_ui(game);
}
