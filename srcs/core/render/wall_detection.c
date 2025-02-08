/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 08:32:17 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 22:13:15 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"
#include "../../../includes/render_wall_utils.h"

void	get_rect_size(t_game *game, int x, int y, t_rect *rect)
{
	int	i;
	int	w;
	int	h;

	w = 0;
	while (x + w < game->map->width && is_wall(game, x + w, y))
		w++;
	h = 0;
	while (y + h < game->map->height)
	{
		i = 0;
		while (i < w && is_wall(game, x + i, y + h))
			i++;
		if (i < w)
			break ;
		h++;
	}
	rect->width = w;
	rect->height = h;
}

int	check_rect_walls(t_game *game, int x, int y, t_rect rect)
{
	int	i;
	int	j;

	j = 0;
	while (j < rect.height)
	{
		i = 0;
		while (i < rect.width)
		{
			if (!is_wall(game, x + i, y + j))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	is_uniform_rect(t_game *game, int x, int y, t_rect *rect)
{
	get_rect_size(game, x, y, rect);
	if (rect->width < 2 || rect->height < 2)
		return (0);
	if (x == 0 || y == 0 || x + rect->width == game->map->width
		|| y + rect->height == game->map->height)
		return (0);
	return (check_rect_walls(game, x, y, *rect));
}

int	find_rect_start(t_game *game, int x, int y, t_point *start)
{
	int	i;
	int	j;

	i = x;
	while (i >= 0 && is_wall(game, i - 1, y))
		i--;
	j = y;
	while (j >= 0 && is_wall(game, i, j - 1))
		j--;
	start->x = i;
	start->y = j;
	return (1);
}

int	is_border_wall(t_game *game, int x, int y)
{
	return (x == 0 || y == 0 || x == game->map->width - 1
		|| y == game->map->height - 1);
}
