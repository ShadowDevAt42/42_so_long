/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_collector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:22:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:45:21 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static int	count_points(t_map *map)
{
	int	count;
	int	i;
	int	j;

	count = 1;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (map->grid[i][j] == 'C' || map->grid[i][j] == 'E')
				count++;
	}
	return (count);
}

static void	fill_points_array(t_map *map, t_point *points, int count)
{
	int	i;
	int	j;
	int	idx;

	points[0] = (t_point){map->player_x, map->player_y};
	idx = 1;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == 'C')
				points[idx++] = (t_point){j, i};
			else if (map->grid[i][j] == 'E')
				points[count - 1] = (t_point){j, i};
		}
	}
}

t_point	*collect_important_points(t_map *map, int *nb_points)
{
	t_point	*points;

	*nb_points = count_points(map);
	points = malloc(sizeof(t_point) * (*nb_points));
	if (!points)
		return (NULL);
	fill_points_array(map, points, *nb_points);
	return (points);
}
