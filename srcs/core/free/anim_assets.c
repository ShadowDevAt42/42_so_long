/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:02:08 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 22:27:42 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_coin_frames(t_game *game)
{
    free_sprite_frames(game, game->coin.frames, 9);
}

void	free_portal_frames(t_game *game)
{
	free_sprite_frames(game, game->portal.frames, 6);
}