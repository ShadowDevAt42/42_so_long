/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:49:18 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:53:59 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error init_exit(t_game *game)
{
    int         width;
    int         height;
    t_error_info error_info;
    char        sprite_path[] = "srcs/assets/portal/exit_close.xpm";

    error_info.sprite_path = sprite_path;
    error_info.additional_info = NULL;

    game->exit.img = mlx_xpm_file_to_image(game->mlx, sprite_path,
            &width, &height);
    if (!game->exit.img)
    {
        handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
        return (ERR_SPRITE_LOAD);
    }
    game->exit.width = width;
    game->exit.height = height;
    return (ERR_NONE);
}