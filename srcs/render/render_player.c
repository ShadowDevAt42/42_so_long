/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:22:23 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:22:29 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    render_player(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->player.img,
        game->map->player_x * SPRITE_SIZE,
        game->map->player_y * SPRITE_SIZE);
}