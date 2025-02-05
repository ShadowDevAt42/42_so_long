/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:39:55 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:51:25 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    render_game(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    render_walls(game);
    render_collectibles(game);
    render_exit(game);
    render_player(game);
}