/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:23:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:45:12 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	find_shortest_valid_path(t_map *map)
{
	t_point	*points;
	int		nb_points;
	int		**dist_matrix;
	int		shortest_path;

	points = collect_important_points(map, &nb_points);
	if (!points)
		return (-1);
	dist_matrix = compute_distance_matrix(map, points, nb_points);
	if (!dist_matrix)
	{
		free(points);
		return (-1);
	}
	shortest_path = tsp_dp(dist_matrix, nb_points);
	free(points);
	cleanup_matrix(dist_matrix, nb_points);
	return (shortest_path);
}
