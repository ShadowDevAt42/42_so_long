/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:20:34 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 21:23:53 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_walls_and_background(t_game *game)
{
	free_sprite(game, &game->wall.wall);
	free_sprite(game, &game->wall.top);
	free_sprite(game, &game->wall.bottom);
	free_sprite(game, &game->wall.left);
	free_sprite(game, &game->wall.right);
	free_sprite(game, &game->wall.int_h_left);
	free_sprite(game, &game->wall.int_h_right);
	free_sprite(game, &game->wall.int_h_center);
	free_sprite(game, &game->wall.int_v_top);
	free_sprite(game, &game->wall.int_v_center);
	free_sprite(game, &game->wall.int_v_bottom);
	free_sprite(game, &game->wall.int_m_ctl);
	free_sprite(game, &game->wall.int_m_ctr);
	free_sprite(game, &game->wall.int_m_cbl);
	free_sprite(game, &game->wall.int_m_cbr);
	free_sprite(game, &game->wall.int_m_wt);
	free_sprite(game, &game->wall.int_m_wb);
	free_sprite(game, &game->wall.int_m_wl);
	free_sprite(game, &game->wall.int_m_wr);
	free_sprite(game, &game->wall.int_m_center);
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
	free_sprite(game, &game->ui.one);
	free_sprite(game, &game->ui.two);
	free_sprite(game, &game->ui.coll_one);
	free_sprite(game, &game->ui.coll_two);
}
