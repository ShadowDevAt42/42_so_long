/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:13:32 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 04:35:10 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	render_portal_if_needed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->grid[i][j] == 'E' && 
				(game->portal.is_animating || game->portal.is_open))
				render_portal(game, j, i);
			j++;
		}
		i++;
	}
}

int	render_next_frame(void *param)
{
	static int	portal_counter = 0;
	static int	coin_counter = 0;
	t_game		*game;

	game = (t_game *)param;
	portal_counter++;
	coin_counter++;

	if (portal_counter >= PORTAL_ANIM_SPEED)
	{
		portal_counter = 0;
		update_portal_anim(game);
		if (game->portal.is_animating || game->portal.is_open)
			render_portal_if_needed(game);
	}
	if (coin_counter >= COIN_ANIM_SPEED)
	{
		coin_counter = 0;
		update_coin_anim(game);
		render_collectibles(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;
	t_error	error;

	if (argc != 2)
	{
		handle_error(ERR_ARGS);
		return (1);
	}
	map = NULL;
	error = validate_all(argv[1], &map);
	if (error != ERR_NONE)
	{
		handle_error(error);
		return (1);
	}
	game = init_window(map);
	if (!game || load_sprites(game) != ERR_NONE)
	{
		free_map(map);
		return (1);
	}
	render_game(game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}