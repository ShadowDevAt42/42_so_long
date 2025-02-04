/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 06:57:16 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/04 07:27:04 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_door_animation(t_game *game)
{
	if (!game || !game->door.is_animating)
		return ;

	game->door.anim_timer++;
	if (game->door.anim_timer >= 200)
	{
		if (game->door.current_frame < game->door.frame_count - 1)
			game->door.current_frame++;
		else
		{
			game->door.is_animating = 0;
			game->door.is_open = 1;
		}
		game->door.anim_timer = 0;
	}
}

void	draw_door(t_game *game)
{
	void	*img_to_use;
	int		x;
	int		y;

	if (!game || !game->mlx || !game->win || 
		game->door.pos_x == -1 || game->door.pos_y == -1)
		return ;

	x = game->door.pos_x * game->img_width;
	y = game->door.pos_y * game->img_height;

	if (game->door.is_animating || game->door.is_open)
	{
		if (game->door.current_frame < 0 || 
			game->door.current_frame >= game->door.frame_count ||
			!game->door.frames[game->door.current_frame])
			return ;
		img_to_use = game->door.frames[game->door.current_frame];
	}
	else
	{
		if (!game->door.closed)
			return ;
		img_to_use = game->door.closed;
	}

	mlx_put_image_to_window(game->mlx, game->win, img_to_use, x, y);
}

void	check_door_condition(t_game *game)
{
	if (!game)
		return ;

	// Vérifie si tous les collectibles sont ramassés
	if (game->collected == game->collectible_count && 
		!game->door.is_animating && !game->door.is_open)
	{
		ft_printf("All collectibles gathered (%d/%d)! Opening door...\n", 
			game->collected, game->collectible_count);
		game->door.is_animating = 1;
		game->door.current_frame = 0;
		game->door.anim_timer = 0;
	}

	// Vérifie si le joueur est sur la porte ouverte
	if (game->door.is_open && 
		game->player_x == game->door.pos_x && 
		game->player_y == game->door.pos_y)
	{
		ft_printf("Level completed! Closing game...\n");
		handle_close(game);
	}
}