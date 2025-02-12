/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:09:56 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/12 08:56:41 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->height && map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}

void	free_window(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->mlx)
	{
		free_sprites(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

int	close_window(t_game *game)
{
	free_window(game);
	exit(0);
	return (0);
}

void	free_sprites(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	free_walls_and_background(game);
	free_gameplay_elements(game);
	free_corner_elements(game);
	free_portal_frames(game);
	free_coin_frames(game);
	free_ui_elements(game);
}
