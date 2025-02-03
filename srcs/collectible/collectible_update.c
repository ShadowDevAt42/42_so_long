/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:48:36 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/03 20:31:26 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_collectible_animation(t_game *game)
{
	game->collectibles.anim_timer++;
	if (game->collectibles.anim_timer >= 500)  // Ajustez cette valeur pour la vitesse
	{
		game->collectibles.current_frame = (game->collectibles.current_frame + 1)
			% game->collectibles.frame_count;
		game->collectibles.anim_timer = 0;
	}
}

void	draw_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectibles.frames[game->collectibles.current_frame],
					x * game->img_width, y * game->img_height);
			}
			x++;
		}
		y++;
	}
}

void	check_collectible(t_game *game)
{
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->collected++;
	}
}