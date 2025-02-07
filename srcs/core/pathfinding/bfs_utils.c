/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:22:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:48:35 by fdi-tria         ###   ########.fr       */
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
	int				i;

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

static void	init_directions(int *dx, int *dy)
{
	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
}

static int	is_valid_move(t_map *map, int x, int y, int **visited)
{
	return (x >= 0 && x < map->width && y >= 0 && y < map->height
		&& map->grid[y][x] != '1' && !visited[y][x]);
}

int	process_neighbors(t_map *map, t_queue_node *current,
	int **visited, t_queue_node **queue)
{
	int	dx[4];
	int	dy[4];
	int	i;
	int	new_x;
	int	new_y;

	init_directions(dx, dy);
	i = -1;
	while (++i < 4)
	{
		new_x = current->x + dx[i];
		new_y = current->y + dy[i];
		if (is_valid_move(map, new_x, new_y, visited))
		{
			enqueue(queue, new_x, new_y, current->dist + 1);
			visited[new_y][new_x] = 1;
		}
	}
	return (0);
}
