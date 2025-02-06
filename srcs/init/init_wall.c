/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:01:54 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 01:12:04 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_error	load_wall_sprite(t_game *game, t_img *wall_img, char *sprite_path)
{
	int				width;
	int				height;
	t_error_info	error_info;

	error_info.sprite_path = sprite_path;
	error_info.additional_info = NULL;
	wall_img->img = mlx_xpm_file_to_image(game->mlx, sprite_path, &width, &height);
	if (!wall_img->img)
	{
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	wall_img->width = width;
	wall_img->height = height;
	return (ERR_NONE);
}

t_error	init_wall(t_game *game)
{
	t_error	error;

	error = load_wall_sprite(game, &game->wall, "srcs/assets/wall/bloc.xpm");
	if (error != ERR_NONE)
		return (error);

	error = load_wall_sprite(game, &game->wall_top, "srcs/assets/wall/top.xpm");
	if (error != ERR_NONE)
		return (error);

	error = load_wall_sprite(game, &game->wall_bottom, "srcs/assets/wall/bottom.xpm");
	if (error != ERR_NONE)
		return (error);

	error = load_wall_sprite(game, &game->wall_left, "srcs/assets/wall/wall_l.xpm");
	if (error != ERR_NONE)
		return (error);

	error = load_wall_sprite(game, &game->wall_right, "srcs/assets/wall/wall_r.xpm");
	if (error != ERR_NONE)
		return (error);

	return (ERR_NONE);
}
