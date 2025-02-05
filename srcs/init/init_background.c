/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 05:41:20 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 17:49:41 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	fill_background(t_game *game)
{
	int			x;
	int			y;
	char		*dest;

	y = 0;
	while (y < SPRITE_SIZE)
	{
		x = 0;
		while (x < SPRITE_SIZE)
		{
			dest = game->background.addr + (y * game->background.line_length
					+ x * (game->background.bits_per_pixel / 8));
			*(unsigned int *)dest = 0x0087CEEB;
			x++;
		}
		y++;
	}
}

t_error	init_background(t_game *game)
{
	game->background.img = mlx_new_image(game->mlx, SPRITE_SIZE, SPRITE_SIZE);
	if (!game->background.img)
	{
		handle_error(ERR_IMG_CREATE);
		return (ERR_IMG_CREATE);
	}
	game->background.addr = mlx_get_data_addr(game->background.img,
			&game->background.bits_per_pixel, &game->background.line_length,
			&game->background.endian);
	if (!game->background.addr)
	{
		mlx_destroy_image(game->mlx, game->background.img);
		handle_error(ERR_IMG_CREATE);
		return (ERR_IMG_CREATE);
	}
	game->background.width = SPRITE_SIZE;
	game->background.height = SPRITE_SIZE;
	fill_background(game);
	return (ERR_NONE);
}
