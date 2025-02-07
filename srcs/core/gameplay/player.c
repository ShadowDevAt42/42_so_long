/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:26:49 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 11:06:27 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map->width
		|| new_y < 0 || new_y >= game->map->height)
		return (0);
	return (game->map->grid[new_y][new_x] != '1');
}

int	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;
	int	was_on_exit;

	new_x = game->map->player_x + dx;
	new_y = game->map->player_y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return (0);
	was_on_exit = game->on_exit;
	check_collectible(game, new_x, new_y);
	check_exit(game, new_x, new_y);
	if (was_on_exit)
		game->map->grid[game->map->player_y][game->map->player_x] = 'E';
	else
		game->map->grid[game->map->player_y][game->map->player_x] = '0';
	if (game->map->grid[new_y][new_x] != 'E')
		game->map->grid[new_y][new_x] = 'P';
	game->map->player_x = new_x;
	game->map->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	return (1);
}
