/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:34:13 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 21:19:29 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_coin_anim(t_game *game)
{
	game->coin.current_frame = (game->coin.current_frame + 1) % 9;
}

void	render_coin(t_game *game, int x, int y)
{
	t_img	*current_frame;

	current_frame = &game->coin.frames[game->coin.current_frame];
	mlx_put_image_to_window(game->mlx, game->win, current_frame->img,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}