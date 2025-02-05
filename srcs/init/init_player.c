/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:21:41 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 17:47:41 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error	init_player(t_game *game)
{
	int				width;
	int				height;
	t_error_info	error_info;
	char			*sprite_path;

	sprite_path = "srcs/assets/player/player.xpm";
	error_info.sprite_path = sprite_path;
	error_info.additional_info = NULL;
	game->player.img = mlx_xpm_file_to_image(game->mlx, sprite_path, &width,
			&height);
	if (!game->player.img)
	{
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	game->player.width = width;
	game->player.height = height;
	return (ERR_NONE);
}
