/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 21:02:08 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 23:18:40 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_error	load_coin_frame(t_game *game, int i)
{
	char	*sprite_path;
	t_error	error;

	sprite_path = build_anim_sprite_path("srcs/assets/collectible/coins", i,
			".xpm");
	if (!sprite_path)
		return (ERR_MALLOC);
	error = load_sprite(game, &game->coin.frames[i], sprite_path);
	free(sprite_path);
	if (error != ERR_NONE)
		return (ERR_SPRITE_LOAD);
	return (ERR_NONE);
}

static t_error	load_portal_transition_frame(t_game *game, int i)
{
	char	*sprite_path;
	t_error	error;

	sprite_path = build_anim_sprite_path
		("srcs/assets/portal/transition/exit", i, ".xpm");
	if (!sprite_path)
		return (ERR_MALLOC);
	error = load_sprite(game, &game->portal.transition_frames[i], sprite_path);
	free(sprite_path);
	if (error != ERR_NONE)
		return (ERR_SPRITE_LOAD);
	return (ERR_NONE);
}

static t_error	load_portal_open_frame(t_game *game, int i)
{
	char	*sprite_path;
	t_error	error;

	sprite_path = build_anim_sprite_path("srcs/assets/portal/open/exit", i,
			".xpm");
	if (!sprite_path)
		return (ERR_MALLOC);
	error = load_sprite(game, &game->portal.open_frames[i], sprite_path);
	free(sprite_path);
	if (error != ERR_NONE)
		return (ERR_SPRITE_LOAD);
	return (ERR_NONE);
}

t_error	init_coin_anim(t_game *game)
{
	int		i;
	t_error	error;

	game->coin.current_frame = 0;
	game->coin.is_animating = 1;
	i = 0;
	while (i < 9)
	{
		error = load_coin_frame(game, i);
		if (error != ERR_NONE)
			return (error);
		i++;
	}
	return (ERR_NONE);
}

t_error	init_portal_anim(t_game *game)
{
	int		i;
	t_error	error;

	game->portal.current_frame = 0;
	game->portal.is_animating = 0;
	game->portal.is_open = 0;
	game->portal.in_transition = 0;
	game->portal.transition_done = 0;
	i = 0;
	while (i < 24)
	{
		error = load_portal_transition_frame(game, i);
		if (error != ERR_NONE)
			return (error);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		error = load_portal_open_frame(game, i);
		if (error != ERR_NONE)
			return (error);
		i++;
	}
	return (ERR_NONE);
}
