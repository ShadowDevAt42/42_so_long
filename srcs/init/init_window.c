/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:01:05 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:36:24 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"

void    free_window(t_game *game)
{
    if (!game)
        return ;
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        free_sprites(game);
        free(game->mlx);
    }
    free(game);
}

int     close_window(t_game *game)
{
    free_window(game);
    exit(0);
    return (0);
}

t_game  *init_window(t_map *map)
{
    t_game  *game;

    game = (t_game *)ft_calloc(1, sizeof(t_game));
    if (!game)
    {
        handle_error(ERR_MALLOC);
        return (NULL);
    }
    game->map = map;
	game->moves = 0;
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        handle_error(ERR_MLX_INIT);
        free_window(game);
        return (NULL);
    }
    game->win = mlx_new_window(game->mlx,
            map->width * SPRITE_SIZE,
            map->height * SPRITE_SIZE,
            "so_long");
    if (!game->win)
    {
        handle_error(ERR_WIN_INIT);
        free_window(game);
        return (NULL);
    }
    setup_hooks(game);  // Ajout de cette ligne
    return (game);
}