/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:01:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 22:03:11 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/render_wall_utils.h"

int	is_wall(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return (0);
	return (game->map->grid[y][x] == '1');
}

t_wall_info	get_wall_info(t_game *game, int x, int y)
{
	t_wall_info	info;

	info.x = x;
	info.y = y;
	info.has_left = is_wall(game, x - 1, y);
	info.has_right = is_wall(game, x + 1, y);
	info.has_top = is_wall(game, x, y - 1);
	info.has_bottom = is_wall(game, x, y + 1);
	if (info.has_left && x - 1 == 0)
		info.has_left = 0;
	if (info.has_right && x + 1 == game->map->width - 1)
		info.has_right = 0;
	if (info.has_top && y - 1 == 0)
		info.has_top = 0;
	if (info.has_bottom && y + 1 == game->map->height - 1)
		info.has_bottom = 0;
	return (info);
}
