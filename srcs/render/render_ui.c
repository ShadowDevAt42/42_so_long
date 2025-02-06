/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:25:10 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 00:43:56 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_collectibles_ui(t_game *game)
{
	int		ui_x;
	int		ui_y;
	char	*coll_str;

	if (!game || !game->mlx || !game->win)
		return ;
	ui_y = 0;
	ui_x = 0;
	// Position ui_coll_one at the left edge
	if (game->ui_coll_one.img)
		mlx_put_image_to_window(game->mlx, game->win, game->ui_coll_one.img, ui_x, ui_y);
	// Position ui_coll_two to the right of ui_coll_one
	if (game->ui_coll_two.img)
		mlx_put_image_to_window(game->mlx, game->win, game->ui_coll_two.img, 
			ui_x + SPRITE_SIZE, ui_y);
	// Display collectibles counter between sprites in format "collected/total"
	char *collected_str = ft_itoa(game->collected);
	char *total_str = ft_itoa(game->map->collectibles);
	if (collected_str && total_str)
	{
		char *slash = "/";
		coll_str = ft_strjoin(collected_str, slash);
		if (coll_str)
		{
			char *final_str = ft_strjoin(coll_str, total_str);
			if (final_str)
			{
				mlx_string_put(game->mlx, game->win, ui_x + SPRITE_SIZE - 7, 
					ui_y + (SPRITE_SIZE / 1.8), 0x000000, final_str);
				free(final_str);
			}
			free(coll_str);
		}
		free(collected_str);
		free(total_str);
	}
}

void	render_ui(t_game *game)
{
	int		ui_x;
	int		ui_y;
	int		window_width;
	char	*moves_str;

	if (!game || !game->mlx || !game->win)
		return ;
	window_width = game->map->width * SPRITE_SIZE;
	ui_y = 0;
	// Position ui_one at the right edge
	ui_x = window_width - SPRITE_SIZE;
	if (game->ui_one.img)
		mlx_put_image_to_window(game->mlx, game->win, game->ui_one.img, ui_x, ui_y);
	// Position ui_two to the left of ui_one with one sprite gap
	if (game->ui_two.img)
		mlx_put_image_to_window(game->mlx, game->win, game->ui_two.img, 
			ui_x - SPRITE_SIZE, ui_y);
	// Display move counter between sprites
	moves_str = ft_itoa(game->moves);
	if (moves_str)
	{
		mlx_string_put(game->mlx, game->win, ui_x - 3, 
			ui_y + (SPRITE_SIZE / 1.8), 0x000000, moves_str);
		free(moves_str);
	}
}
