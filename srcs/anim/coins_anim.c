/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins_anim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:34:13 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 04:43:37 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_error	load_coin_frame(t_game *game, int frame_num)
{
	int				width;
	int				height;
	t_error_info	error_info;
	char			*sprite_path;
	char			*num_str;

	num_str = ft_itoa(frame_num + 1);
	if (!num_str)
		return (ERR_MALLOC);
	sprite_path = ft_strjoin("srcs/assets/collectible/coins", num_str);
	free(num_str);
	if (!sprite_path)
		return (ERR_MALLOC);
	sprite_path = ft_strjoin(sprite_path, ".xpm");
	error_info.sprite_path = sprite_path;
	error_info.additional_info = NULL;
	game->coin.frames[frame_num].img = mlx_xpm_file_to_image(game->mlx,
			sprite_path, &width, &height);
	if (!game->coin.frames[frame_num].img)
	{
		free(sprite_path);
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	game->coin.frames[frame_num].width = width;
	game->coin.frames[frame_num].height = height;
	free(sprite_path);
	return (ERR_NONE);
}

t_error	init_coin_anim(t_game *game)
{
	int	i;

	game->coin.current_frame = 0;
	game->coin.is_animating = 1;  // Les pièces sont toujours en animation
	i = 0;
	while (i < 9)
	{
		if (load_coin_frame(game, i) != ERR_NONE)
			return (ERR_SPRITE_LOAD);
		i++;
	}
	return (ERR_NONE);
}

void	update_coin_anim(t_game *game)
{
	game->coin.current_frame = (game->coin.current_frame + 1) % 9;
}

void	render_coin(t_game *game, int x, int y)
{
	t_img	*current_frame;

	current_frame = &game->coin.frames[game->coin.current_frame];
	mlx_put_image_to_window(game->mlx, game->win, current_frame->img,
		x * SPRITE_SIZE, y * SPRITE_SIZE);
}