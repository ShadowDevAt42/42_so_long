/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:22:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:22:06 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	**init_visited_array(t_map *map)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(sizeof(int *) * map->height);
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		visited[i] = malloc(sizeof(int) * map->width);
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		j = -1;
		while (++j < map->width)
			visited[i][j] = 0;
	}
	return (visited);
}

void	cleanup_bfs(t_queue_node **queue, int **visited, int height)
{
	t_queue_node	*current;
	int			i;

	while (*queue)
	{
		current = dequeue(queue);
		free(current);
	}
	i = -1;
	while (++i < height)
		free(visited[i]);
	free(visited);
}

int	process_neighbors(t_map *map, t_queue_node *current,
	int **visited, t_queue_node **queue)
{
	int	dx[4];
	int	dy[4];
	int	i;
	int	new_x;
	int	new_y;

	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
	i = -1;
	while (++i < 4)
	{
		new_x = current->x + dx[i];
		new_y = current->y + dy[i];
		if (new_x >= 0 && new_x < map->width && new_y >= 0
			&& new_y < map->height && map->grid[new_y][new_x] != '1'
			&& !visited[new_y][new_x])
		{
			enqueue(queue, new_x, new_y, current->dist + 1);
			visited[new_y][new_x] = 1;
		}
	}
	return (0);
}

int	bfs_distance(t_map *map, t_point start, t_point target)
{
	t_queue_node	*queue;
	int			**visited;
	t_queue_node	*current;
	int			distance;

	queue = NULL;
	visited = init_visited_array(map);
	if (!visited)
		return (-1);
	ft_printf("Debug: BFS from (%d,%d) to (%d,%d)\n",
		start.x, start.y, target.x, target.y);
	enqueue(&queue, start.x, start.y, 0);
	visited[start.y][start.x] = 1;
	distance = -1;
	while (queue)
	{
		current = dequeue(&queue);
		if (!current)
			break ;
		if (current->x == target.x && current->y == target.y)
		{
			distance = current->dist;
			free(current);
			break ;
		}
		process_neighbors(map, current, visited, &queue);
		free(current);
	}
	cleanup_bfs(&queue, visited, map->height);
	return (distance);
}
