/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:35:34 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 00:52:50 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map->width
		|| new_y < 0 || new_y >= game->map->height)
		return (0);
	return (game->map->grid[new_y][new_x] != '1');
}

static void	check_collectible(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'C')
	{
		game->collected++;
	}
}

static void	check_exit(t_game *game, int x, int y)
{
	if (game->map->grid[y][x] == 'E')
	{
		if (game->collected == game->map->collectibles)
		{
			ft_printf("\nCongratulations! You won in %d moves!\n", game->moves);
			close_window(game);
		}
		game->on_exit = 1;
	}
	else
		game->on_exit = 0;
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

void	handle_player_movement(t_game *game, int keycode)
{
	if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
}
