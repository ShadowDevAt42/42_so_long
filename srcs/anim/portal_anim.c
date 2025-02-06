/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:04:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 04:14:58 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_error	load_portal_frame(t_game *game, int frame_num)
{
	int				width;
	int				height;
	t_error_info	error_info;
	char			*sprite_path;
	char			*num_str;

	num_str = ft_itoa(frame_num + 1);
	if (!num_str)
		return (ERR_MALLOC);
	sprite_path = ft_strjoin("srcs/assets/portal/exit_open", num_str);
	free(num_str);
	if (!sprite_path)
		return (ERR_MALLOC);
	sprite_path = ft_strjoin(sprite_path, ".xpm");
	error_info.sprite_path = sprite_path;
	error_info.additional_info = NULL;
	game->portal.frames[frame_num].img = mlx_xpm_file_to_image(game->mlx,
			sprite_path, &width, &height);
	if (!game->portal.frames[frame_num].img)
	{
		free(sprite_path);
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	game->portal.frames[frame_num].width = width;
	game->portal.frames[frame_num].height = height;
	free(sprite_path);
	return (ERR_NONE);
}

t_error	init_portal_anim(t_game *game)
{
	int	i;

	game->portal.current_frame = 0;
	game->portal.is_animating = 0;
	game->portal.is_open = 0;
	i = 0;
	while (i < 6)
	{
		if (load_portal_frame(game, i) != ERR_NONE)
			return (ERR_SPRITE_LOAD);
		i++;
	}
	return (ERR_NONE);
}

void	update_portal_anim(t_game *game)
{
	if (!game->portal.is_animating)
		return ;
	game->portal.current_frame = (game->portal.current_frame + 1) % 6;
}

void	render_portal(t_game *game, int x, int y)
{
	t_img	*current_frame;

	if (game->portal.is_animating || game->portal.is_open)
		current_frame = &game->portal.frames[game->portal.current_frame];
	else
		current_frame = &game->exit;
	mlx_put_image_to_window(game->mlx, game->win, current_frame->img,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	start_portal_anim(t_game *game)
{
	if (!game->portal.is_animating)
	{
		game->portal.is_animating = 1;
		game->portal.current_frame = 0;
	}
}