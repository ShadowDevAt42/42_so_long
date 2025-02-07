/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:01:26 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 09:41:30 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error	load_sprite(t_game *game, t_img *img, char *sprite_path)
{
	int				width;
	int				height;
	t_error_info	error_info;

	error_info.sprite_path = sprite_path;
	error_info.additional_info = NULL;
	img->img = mlx_xpm_file_to_image(game->mlx, sprite_path, &width, &height);
	if (!img->img)
	{
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	img->width = width;
	img->height = height;
	return (ERR_NONE);
}

char	*build_anim_sprite_path(const char *base_path, int frame_num,
		const char *suffix)
{
	char	*num_str;
	char	*temp;
	char	*full_path;

	num_str = ft_itoa(frame_num + 1);
	if (!num_str)
		return (NULL);
	temp = ft_strjoin(base_path, num_str);
	free(num_str);
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, suffix);
	free(temp);
	return (full_path);
}

void	free_sprite(t_game *game, t_img *sprite)
{
	if (sprite && sprite->img)
	{
		mlx_destroy_image(game->mlx, sprite->img);
		sprite->img = NULL;
	}
}

void	free_sprite_frames(t_game *game, t_img *sprites, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free_sprite(game, &sprites[i]);
		i++;
	}
}
