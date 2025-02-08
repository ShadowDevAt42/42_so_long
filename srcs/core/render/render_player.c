/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:53:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 15:09:39 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

#define TRANSP_COLOR 0xFF00FF  // Magenta as transparent color

static t_img	*merge_player_sprite(t_game *game)
{
	t_img	*merged;
	int		i;
	int		j;
	int		bg_color;
	int		pl_color;
	char	*bg_data;
	char	*player_data;
	char	*merged_data;

	merged = malloc(sizeof(t_img));
	if (!merged)
		return (NULL);
	merged->img = mlx_new_image(game->mlx, SPRITE_SIZE, SPRITE_SIZE);
	if (!merged->img)
	{
		free(merged);
		return (NULL);
	}
	merged_data = mlx_get_data_addr(merged->img, &merged->bits_per_pixel,
		&merged->line_length, &merged->endian);
	bg_data = mlx_get_data_addr(game->background.img, &game->background.bits_per_pixel,
		&game->background.line_length, &game->background.endian);
	player_data = mlx_get_data_addr(game->player.img, &game->player.bits_per_pixel,
		&game->player.line_length, &game->player.endian);
	j = 0;
	while (j < SPRITE_SIZE)
	{
		i = 0;
		while (i < SPRITE_SIZE)
		{
			bg_color = *((int *)(bg_data + (j * game->background.line_length
				+ i * (game->background.bits_per_pixel / 8))));
			pl_color = *((int *)(player_data + (j * game->player.line_length
				+ i * (game->player.bits_per_pixel / 8))));
			if (pl_color == TRANSP_COLOR)
				*((int *)(merged_data + (j * merged->line_length
					+ i * (merged->bits_per_pixel / 8)))) = bg_color;
			else
				*((int *)(merged_data + (j * merged->line_length
					+ i * (merged->bits_per_pixel / 8)))) = pl_color;
			i++;
		}
		j++;
	}
	merged->width = SPRITE_SIZE;
	merged->height = SPRITE_SIZE;
	return (merged);
}

void	render_player(t_game *game)
{
	t_img	*merged;
	int		x;
	int		y;

	merged = merge_player_sprite(game);
	if (!merged)
		return ;
	x = game->map->player_x * SPRITE_SIZE;
	y = game->map->player_y * SPRITE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, merged->img, x, y);
	mlx_destroy_image(game->mlx, merged->img);
	free(merged);
}
