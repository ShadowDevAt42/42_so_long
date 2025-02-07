/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:27:14 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 13:06:56 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	check_collectible(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'C')
		game->collected++;
}

void	check_exit(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'E')
	{
		if (game->collected == game->map->collectibles)
		{
			if (game->moves <= game->map->optimal_path)
				ft_printf("\nPerfect! You found the optimal path in %d moves! "
					"Optimal path: %d!\n", game->moves,
					game->map->optimal_path);
			else
				ft_printf("\nGame Over! Path was not optimal. Your moves: %d,"
					" Optimal path: %d\n", game->moves,
					game->map->optimal_path);
			close_window(game);
		}
		game->on_exit = 1;
	}
	else
		game->on_exit = 0;
}
