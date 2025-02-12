/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:13:32 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/12 10:36:08 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	cleanup(t_game *game)
{
	if (game)
	{
		free_game(game);
	}
	ft_cleanup_gnl();
}

static int	init_game(char *map_path, t_game **game)
{
	t_map	*map;
	t_error	error;

	map = NULL;
	error = validate_all(map_path, &map);
	if (error != ERR_NONE)
	{
		handle_error(error);
		return (1);
	}
	*game = init_window(map);
	if (!*game || load_sprites(*game) != ERR_NONE)
	{
		free_map(map);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		handle_error(ERR_ARGS);
		return (1);
	}
	if (init_game(argv[1], &game))
	{
		cleanup(NULL);
		return (1);
	}
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	cleanup(game);
	return (0);
}
