/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:37:39 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 10:10:30 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_ui(t_game *game)
{
	int		ui_x;
	int		ui_y;
	int		window_width;
	char	*moves_str;
	t_text	text;

	if (!game || !game->mlx || !game->win)
		return ;
	window_width = game->map->width * SPRITE_SIZE;
	ui_y = 0;
	ui_x = window_width - SPRITE_SIZE;
	render_sprite(game, &game->ui.one, ui_x, ui_y);
	render_sprite(game, &game->ui.two, ui_x - SPRITE_SIZE, ui_y);
	moves_str = ft_itoa(game->moves);
	if (moves_str)
	{
		text.x = ui_x - 3;
		text.y = ui_y + (SPRITE_SIZE / 1.8);
		text.color = 0x000000;
		text.str = moves_str;
		render_text(game, text);
		free(moves_str);
	}
}

static char	*create_collectibles_str(t_game *game)
{
	char	*collected_str;
	char	*total_str;
	char	*coll_str;
	char	*final_str;

	collected_str = ft_itoa(game->collected);
	total_str = ft_itoa(game->map->collectibles);
	final_str = NULL;
	if (collected_str && total_str)
	{
		coll_str = ft_strjoin(collected_str, "/");
		if (coll_str)
		{
			final_str = ft_strjoin(coll_str, total_str);
			free(coll_str);
		}
		free(collected_str);
		free(total_str);
	}
	return (final_str);
}

void	render_collectibles_ui(t_game *game)
{
	int		ui_x;
	int		ui_y;
	char	*final_str;
	t_text	text;

	if (!game || !game->mlx || !game->win)
		return ;
	ui_y = 0;
	ui_x = 0;
	render_sprite(game, &game->ui.coll_one, ui_x, ui_y);
	render_sprite(game, &game->ui.coll_two, ui_x + SPRITE_SIZE, ui_y);
	final_str = create_collectibles_str(game);
	if (final_str)
	{
		text.x = ui_x + SPRITE_SIZE - 7;
		text.y = ui_y + (SPRITE_SIZE / 1.8);
		text.color = 0x000000;
		text.str = final_str;
		render_text(game, text);
		free(final_str);
	}
}
