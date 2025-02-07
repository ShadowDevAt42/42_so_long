/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:22:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:57:25 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

static int	process_current_node(t_queue_node *current, t_point target,
	t_map *map, t_bfs_data *data)
{
	if (current->x == target.x && current->y == target.y)
	{
		data->distance = current->dist;
		free(current);
		return (1);
	}
	process_neighbors(map, current, data->visited, &data->queue);
	free(current);
	return (0);
}

int	bfs_distance(t_map *map, t_point start, t_point target)
{
	t_bfs_data		data;
	t_queue_node	*current;

	data.queue = NULL;
	data.visited = init_visited_array(map);
	data.distance = -1;
	if (!data.visited)
		return (-1);
	enqueue(&data.queue, start.x, start.y, 0);
	data.visited[start.y][start.x] = 1;
	while (data.queue)
	{
		current = dequeue(&data.queue);
		if (!current)
			break ;
		if (process_current_node(current, target, map, &data))
			break ;
	}
	cleanup_bfs(&data.queue, data.visited, map->height);
	return (data.distance);
}
