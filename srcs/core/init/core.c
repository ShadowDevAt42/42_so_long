/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:07:18 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 11:36:35 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->player_x = -1;
	map->player_y = -1;
	map->optimal_path = -1;
	return (map);
}

static t_game	*init_game_struct(t_map *map)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		handle_error(ERR_MALLOC);
		return (NULL);
	}
	game->map = map;
	game->moves = 0;
	game->collected = 0;
	game->on_exit = 0;
	game->optimal_path = find_shortest_valid_path(map);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		handle_error(ERR_MLX_INIT);
		free_window(game);
		return (NULL);
	}
	return (game);
}

t_game	*init_window(t_map *map)
{
	t_game	*game;

	game = init_game_struct(map);
	if (!game)
		return (NULL);
	game->win = mlx_new_window(game->mlx, map->width * SPRITE_SIZE,
			map->height * SPRITE_SIZE, "so_long");
	if (!game->win)
	{
		handle_error(ERR_WIN_INIT);
		close_window(game);
		return (NULL);
	}
	setup_hooks(game);
	return (game);
}

t_error	load_sprites(t_game *game)
{
	t_error	error;

	error = init_wall_and_background(game);
	if (error != ERR_NONE)
		return (error);
	error = init_corner(game);
	if (error != ERR_NONE)
		return (error);
	error = init_player_and_exit(game);
	if (error != ERR_NONE)
		return (error);
	error = init_coin_anim(game);
	if (error != ERR_NONE)
		return (error);
	error = init_portal_anim(game);
	if (error != ERR_NONE)
		return (error);
	error = init_ui(game);
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}
