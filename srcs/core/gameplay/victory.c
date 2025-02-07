/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:27:14 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 11:19:34 by fdi-tria         ###   ########.fr       */
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
			t_map	temp_map;
			int		optimal_path;
			int		i;
			int		j;

			temp_map = *game->map;
			temp_map.grid = malloc(sizeof(char *) * temp_map.height);
			if (!temp_map.grid)
				return ;
			i = -1;
			while (++i < temp_map.height)
			{
				temp_map.grid[i] = malloc(sizeof(char) * (temp_map.width + 1));
				if (!temp_map.grid[i])
				{
					while (--i >= 0)
						free(temp_map.grid[i]);
					free(temp_map.grid);
					return ;
				}
				j = -1;
				while (++j < temp_map.width)
					temp_map.grid[i][j] = game->map->grid[i][j];
				temp_map.grid[i][temp_map.width] = '\0';
			}
			optimal_path = find_shortest_valid_path(&temp_map);
			i = -1;
			while (++i < temp_map.height)
				free(temp_map.grid[i]);
			free(temp_map.grid);

			if (optimal_path != -1 && game->moves <= optimal_path)
				ft_printf("\nPerfect! You found the optimal path in %d moves!\n", 
					game->moves);
			else if (optimal_path != -1)
				ft_printf("\nGame Over! Path was not optimal. Your moves: %d, Optimal path: %d\n", 
					game->moves, optimal_path);
			else
				ft_printf("\nGame Over! Could not calculate optimal path.\n");
			close_window(game);
		}
		game->on_exit = 1;
	}
	else
		game->on_exit = 0;
}
