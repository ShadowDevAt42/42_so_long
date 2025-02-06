/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:20:34 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 00:23:35 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_walls_and_background(t_game *game)
{
	free_sprite(game, &game->wall);
    free_sprite(game, &game->wall_top);
    free_sprite(game, &game->wall_bottom);
    free_sprite(game, &game->wall_left);
    free_sprite(game, &game->wall_right);
    free_sprite(game, &game->background);
}

void	free_corner_elements(t_game *game)
{
    free_sprite(game, &game->corner.top_left);
    free_sprite(game, &game->corner.top_right);
    free_sprite(game, &game->corner.bottom_left);
    free_sprite(game, &game->corner.bottom_right);
}

void	free_gameplay_elements(t_game *game)
{
    free_sprite(game, &game->player);
    free_sprite(game, &game->exit);
}

void	free_ui_elements(t_game *game)
{
    free_sprite(game, &game->ui_one);
    free_sprite(game, &game->ui_two);
	free_sprite(game, &game->ui_coll_one);
    free_sprite(game, &game->ui_coll_two);
}
