/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:56:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 11:21:57 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <limits.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_queue_node
{
	int					x;
	int					y;
	int					dist;
	struct s_queue_node	*next;
}	t_queue_node;

static t_queue_node	*create_node(int x, int y, int dist)
{
	t_queue_node	*node;

	node = malloc(sizeof(t_queue_node));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->dist = dist;
	node->next = NULL;
	return (node);
}

static void	enqueue(t_queue_node **queue, int x, int y, int dist)
{
	t_queue_node	*node;
	t_queue_node	*temp;

	node = create_node(x, y, dist);
	if (!node)
		return ;
	if (!*queue)
	{
		*queue = node;
		return ;
	}
	temp = *queue;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

static t_queue_node	*dequeue(t_queue_node **queue)
{
	t_queue_node	*temp;

	if (!*queue)
		return (NULL);
	temp = *queue;
	*queue = (*queue)->next;
	return (temp);
}

static int	bfs_distance(t_map *map, t_point start, t_point target)
{
	t_queue_node	*queue;
	int				**visited;
	int				dx[] = {-1, 1, 0, 0};
	int				dy[] = {0, 0, -1, 1};
	int				i;
	int				new_x;
	int				new_y;
	t_queue_node	*current;
	int				distance;

	queue = NULL;
	visited = ft_calloc(map->height, sizeof(int *));
	if (!visited)
		return (-1);
	i = -1;
	while (++i < map->height)
	{
		visited[i] = ft_calloc(map->width, sizeof(int));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (-1);
		}
	}
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
		i = -1;
		while (++i < 4)
		{
			new_x = current->x + dx[i];
			new_y = current->y + dy[i];
			if (new_x >= 0 && new_x < map->width && new_y >= 0 && new_y < map->height
				&& map->grid[new_y][new_x] != '1' && !visited[new_y][new_x])
			{
				enqueue(&queue, new_x, new_y, current->dist + 1);
				visited[new_y][new_x] = 1;
			}
		}
		free(current);
	}
	while (queue)
	{
		current = dequeue(&queue);
		free(current);
	}
	i = -1;
	while (++i < map->height)
		free(visited[i]);
	free(visited);
	return (distance);
}

static int	**compute_distance_matrix(t_map *map, t_point *nodes, int nb_nodes)
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

static int	tsp_dp(int **dist, int nb_nodes)
{
	int	num_collect;
	int	all_mask;
	int	**dp;
	int	i;
	int	j;
	int	mask;
	int	best;
	int	next_mask;

	num_collect = nb_nodes - 2;
	all_mask = (1 << num_collect) - 1;
	dp = malloc(sizeof(int *) * (all_mask + 1));
	if (!dp)
		return (-1);
	i = -1;
	while (++i <= all_mask)
	{
		dp[i] = malloc(sizeof(int) * (num_collect + 1));
		if (!dp[i])
		{
			while (--i >= 0)
				free(dp[i]);
			free(dp);
			return (-1);
		}
		j = -1;
		while (++j <= num_collect)
			dp[i][j] = INT_MAX;
	}
	i = 0;
	while (++i <= num_collect)
		if (dist[0][i] != -1)
			dp[1 << (i - 1)][i] = dist[0][i];
	mask = -1;
	while (++mask <= all_mask)
	{
		i = 0;
		while (++i <= num_collect)
		{
			if (!(mask & (1 << (i - 1))))
				continue ;
			j = 0;
			while (++j <= num_collect)
			{
				if (mask & (1 << (j - 1)))
					continue ;
				next_mask = mask | (1 << (j - 1));
				if (dp[mask][i] != INT_MAX && dist[i][j] != -1)
					dp[next_mask][j] = ft_min(dp[next_mask][j],
							dp[mask][i] + dist[i][j]);
			}
		}
	}
	best = INT_MAX;
	i = 0;
	while (++i <= num_collect)
		if (dp[all_mask][i] != INT_MAX && dist[i][nb_nodes - 1] != -1)
			best = ft_min(best, dp[all_mask][i] + dist[i][nb_nodes - 1]);
	i = -1;
	while (++i <= all_mask)
		free(dp[i]);
	free(dp);
	return (best == INT_MAX ? -1 : best);
}

static t_point	*collect_important_points(t_map *map, int *nb_points)
{
	t_point	*points;
	int		count;
	int		i;
	int		j;
	int		idx;

	count = 1;  // Player
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (map->grid[i][j] == 'C' || map->grid[i][j] == 'E')
				count++;
	}
	*nb_points = count;
	points = malloc(sizeof(t_point) * count);
	if (!points)
		return (NULL);
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
	return (points);
}

int	find_shortest_valid_path(t_map *map)
{
	t_point	*points;
	int		nb_points;
	int		**dist_matrix;
	int		shortest_path;
	int		i;
	int		j;

	points = collect_important_points(map, &nb_points);
	if (!points)
	{
		ft_printf("Debug: Failed to collect points\n");
		return (-1);
	}
	ft_printf("Debug: Found %d points (including player and exit)\n", nb_points);
	ft_printf("Debug: Player at (%d,%d)\n", points[0].x, points[0].y);
	ft_printf("Debug: Exit at (%d,%d)\n", points[nb_points - 1].x, points[nb_points - 1].y);
	for (i = 1; i < nb_points - 1; i++)
		ft_printf("Debug: Collectible %d at (%d,%d)\n", i, points[i].x, points[i].y);

	dist_matrix = compute_distance_matrix(map, points, nb_points);
	if (!dist_matrix)
	{
		ft_printf("Debug: Failed to compute distance matrix\n");
		free(points);
		return (-1);
	}

	ft_printf("Debug: Distance matrix:\n");
	for (i = 0; i < nb_points; i++)
	{
		for (j = 0; j < nb_points; j++)
			ft_printf("%3d ", dist_matrix[i][j]);
		ft_printf("\n");
	}

	shortest_path = tsp_dp(dist_matrix, nb_points);
	ft_printf("Debug: TSP returned path length: %d\n", shortest_path);

	free(points);
	while (--nb_points >= 0)
		free(dist_matrix[nb_points]);
	free(dist_matrix);
	return (shortest_path);
}
