/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:20:34 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 23:21:29 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error	init_wall_and_background(t_game *game)
{
	t_error	error;

	error = init_wall_basic(game);
	if (error != ERR_NONE)
		return (error);
	error = init_wall_internal_h(game);
	if (error != ERR_NONE)
		return (error);
	error = init_wall_internal_v(game);
	if (error != ERR_NONE)
		return (error);
	error = init_wall_internal_m1(game);
	if (error != ERR_NONE)
		return (error);
	error = init_wall_internal_m2(game);
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->background, "srcs/assets/wall/back.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

t_error	init_corner(t_game *game)
{
	t_error	error;

	error = load_sprite(game, &game->corner.top_left,
			"srcs/assets/wall/corner_h_l.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->corner.top_right,
			"srcs/assets/wall/corner_h_r.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->corner.bottom_left,
			"srcs/assets/wall/corner_b_l.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->corner.bottom_right,
			"srcs/assets/wall/corner_b_r.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

t_error	init_player_and_exit(t_game *game)
{
	t_error	error;

	error = load_sprite(game, &game->player, "srcs/assets/player/player.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->exit, "srcs/assets/portal/exit_close.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

t_error	init_ui(t_game *game)
{
	t_error	error;

	error = load_sprite(game, &game->ui.one, "srcs/assets/ui/move2.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->ui.two, "srcs/assets/ui/move1.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->ui.coll_one, "srcs/assets/ui/coll1.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->ui.coll_two, "srcs/assets/ui/coll2.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}
