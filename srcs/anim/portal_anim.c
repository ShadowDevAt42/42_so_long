/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:04:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 21:23:16 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_portal_anim(t_game *game)
{
	if (!game->portal.is_animating)
		return ;
	game->portal.current_frame = (game->portal.current_frame + 1) % 6;
}

void	render_portal(t_game *game, int x, int y)
{
	t_img	*current_frame;

	if (game->portal.is_animating || game->portal.is_open)
		current_frame = &game->portal.frames[game->portal.current_frame];
	else
		current_frame = &game->exit;
	mlx_put_image_to_window(game->mlx, game->win, current_frame->img,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	start_portal_anim(t_game *game)
{
	if (!game->portal.is_animating)
	{
		game->portal.is_animating = 1;
		game->portal.current_frame = 0;
	}
}