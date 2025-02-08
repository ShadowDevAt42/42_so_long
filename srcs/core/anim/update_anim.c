/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:33:45 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 23:17:02 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_portal_anim(t_game *game)
{
	if (!game->portal.is_animating)
		return ;
	if (game->portal.in_transition)
	{
		if (game->portal.current_frame < 24)
			game->portal.current_frame++;
		if (game->portal.current_frame == 24)
		{
			game->portal.in_transition = 0;
			game->portal.transition_done = 1;
			game->portal.is_open = 1;
			game->portal.current_frame = 0;
		}
	}
	else if (game->portal.transition_done)
	{
		game->portal.current_frame = (game->portal.current_frame + 1) % 6;
	}
}

void	start_portal_anim(t_game *game)
{
	if (!game->portal.is_animating)
	{
		game->portal.is_animating = 1;
		game->portal.in_transition = 1;
		game->portal.transition_done = 0;
		game->portal.current_frame = 0;
		game->portal.is_open = 0;
	}
}

void	update_coin_anim(t_game *game)
{
	game->coin.current_frame = (game->coin.current_frame + 1) % 9;
}
