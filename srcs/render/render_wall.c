/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:02:22 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:02:24 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void    render_wall_at(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, game->wall.img,
        x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void    render_walls(t_game *game)
{
    int    y;
    int    x;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == '1')
                render_wall_at(game, x, y);
            x++;
        }
        y++;
    }
}