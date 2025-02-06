/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:02:08 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 21:21:50 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error	init_coin_anim(t_game *game)
{
    int		i;
    char	*sprite_path;
    t_error	error;

    game->coin.current_frame = 0;
    game->coin.is_animating = 1;  // Les pièces sont toujours en animation
    i = 0;
    while (i < 9)
    {
        sprite_path = build_anim_sprite_path("srcs/assets/collectible/coins", i, ".xpm");
        if (!sprite_path)
            return (ERR_MALLOC);
        error = load_sprite(game, &game->coin.frames[i], sprite_path);
        free(sprite_path);
        if (error != ERR_NONE)
            return (ERR_SPRITE_LOAD);
        i++;
    }
    return (ERR_NONE);
}

t_error	init_portal_anim(t_game *game)
{
    int		i;
    char	*sprite_path;
    t_error error;

    game->portal.current_frame = 0;
    game->portal.is_animating = 0;
    game->portal.is_open = 0;
    i = 0;
    while (i < 6)
    {
        sprite_path = build_anim_sprite_path("srcs/assets/portal/exit_open", i, ".xpm"); // voir [`build_anim_sprite_path`](srcs/core/utils.c)
        if (!sprite_path)
            return (ERR_MALLOC);
        error = load_sprite(game, &game->portal.frames[i], sprite_path); // voir [`load_sprite`](srcs/core/utils.c)
        free(sprite_path);
        if (error != ERR_NONE)
            return (ERR_SPRITE_LOAD);
        i++;
    }
    return (ERR_NONE);
}