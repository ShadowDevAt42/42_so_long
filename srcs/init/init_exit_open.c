/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:59:31 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 05:06:48 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error init_exit_open(t_game *game)
{
    int         width;
    int         height;
    t_error_info error_info;
    char        sprite_path[] = "srcs/assets/portal/exit_open.xpm";

    error_info.sprite_path = sprite_path;
    error_info.additional_info = NULL;

    game->exit_open.img = mlx_xpm_file_to_image(game->mlx, sprite_path,
            &width, &height);
    if (!game->exit_open.img)
    {
        handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
        return (ERR_SPRITE_LOAD);
    }
    game->exit_open.width = width;
    game->exit_open.height = height;
    return (ERR_NONE);
}