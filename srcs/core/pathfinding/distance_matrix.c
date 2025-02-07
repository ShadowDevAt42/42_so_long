/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:22:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:44:59 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	cleanup_matrix(int **matrix, int size)
{
	while (--size >= 0)
		free(matrix[size]);
	free(matrix);
}

int	**compute_distance_matrix(t_map *map, t_point *nodes, int nb_nodes)
{
	int	**dist;
	int	i;
	int	j;

	dist = malloc(sizeof(int *) * nb_nodes);
	if (!dist)
		return (NULL);
	i = -1;
	while (++i < nb_nodes)
	{
		dist[i] = malloc(sizeof(int) * nb_nodes);
		if (!dist[i])
		{
			while (--i >= 0)
				free(dist[i]);
			free(dist);
			return (NULL);
		}
		j = -1;
		while (++j < nb_nodes)
			dist[i][j] = bfs_distance(map, nodes[i], nodes[j]);
	}
	return (dist);
}
