/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_anim_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 18:11:09 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_collectibles(t_game *game)
{
	int		x;
	int		y;
	t_img	*current_frame;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == 'C')
			{
				current_frame = &game->coin.frames[game->coin.current_frame];
				render_sprite(game, current_frame, x * SPRITE_SIZE,
					y * SPRITE_SIZE);
			}
			x++;
		}
		y++;
	}
}

static void	set_exit_portal(t_game *game, t_img **current_frame)
{
	if (game->portal.is_animating)
	{
		if (game->portal.in_transition)
		{
			if (game->portal.current_frame == 0)
				*current_frame = &game->exit;
			else
				*current_frame = &game->portal.transition_frames[game->portal.current_frame];
		}
		else if (game->portal.transition_done)
			*current_frame = &game->portal.open_frames[game->portal.current_frame];
	}
	else
		*current_frame = &game->exit;
}

static void	check_and_start_portal(t_game *game, int i, int j)
{
	if (game->map->grid[i][j] == 'E')
	{
		if (game->collected == game->map->collectibles
			&& !game->portal.is_open && !game->portal.is_animating)
		{
			start_portal_anim(game);
		}
	}
}

void	render_exit(t_game *game)
{
	int		i;
	int		j;
	t_img	*current_frame;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			check_and_start_portal(game, i, j);
			if (game->map->grid[i][j] == 'E')
			{
				set_exit_portal(game, &current_frame);
				render_sprite(game, current_frame, j * SPRITE_SIZE,
					i * SPRITE_SIZE);
			}
			j++;
		}
		i++;
	}
}
