/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:27:14 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 18:47:43 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	check_collectible(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'C')
	{
		game->collected++;
	}
}

void	check_exit(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'E')
	{
		if (game->collected == game->map->collectibles && 
			game->portal.is_open && !game->portal.in_transition)
		{
			game->moves++;
			ft_printf("Congratulations! You won in %d moves!\n", game->moves);
			close_window(game);
		}
		game->on_exit = 1;
	}
	else
		game->on_exit = 0;
}
