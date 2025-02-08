/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:02:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 09:47:45 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_sprite(t_game *game, t_img *sprite, int x, int y)
{
	if (sprite && sprite->img)
		mlx_put_image_to_window(game->mlx, game->win, sprite->img, x, y);
}

void	render_text(t_game *game, t_text text)
{
	if (text.str)
		mlx_string_put(game->mlx, game->win, text.x, text.y,
			text.color, text.str);
}
