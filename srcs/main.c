/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:13:32 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 17:27:57 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	mlx_loop(game->mlx);
	return (0);
}
