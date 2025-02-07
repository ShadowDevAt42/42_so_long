/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:13:22 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 11:44:20 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_reachable_elements(t_map *map, char **visited)
{
	int	i;
	int	j;
	int	collect_found;
	int	exit_found;

	collect_found = 0;
	exit_found = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == 'C' && visited[i][j])
				collect_found++;
			else if (map->grid[i][j] == 'E' && visited[i][j])
				exit_found = 1;
		}
	}
	return (collect_found == map->collectibles && exit_found);
}

static char	**allocate_visited(t_map *map)
{
	int		i;
	char	**visited;

	visited = malloc(sizeof(char *) * map->height);
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		visited[i] = ft_calloc(map->width, sizeof(char));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
	}
	return (visited);
}

static void	free_visited(char **visited, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(visited[i]);
	free(visited);
}

int	validate_path(t_map *map)
{
	char	**visited;
	int		valid;

	visited = allocate_visited(map);
	if (!visited)
		return (0);
	flood_fill(map, visited, map->player_x, map->player_y);
	valid = check_reachable_elements(map, visited);
	free_visited(visited, map->height);
	if (!valid)
		return (0);
	map->optimal_path = find_shortest_valid_path(map);
	return (map->optimal_path != -1);
}
