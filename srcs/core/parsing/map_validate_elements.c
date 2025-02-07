/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:07:29 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 10:46:50 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	count_element(char **grid, int height, int width, char element)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (grid[i][j] == element)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	count_map_elements(t_map *map)
{
	map->collectibles = count_element(map->grid, map->height, map->width, 'C');
	map->exit = count_element(map->grid, map->height, map->width, 'E');
	map->player = count_element(map->grid, map->height, map->width, 'P');
}

int	validate_elements(t_map *map)
{
	if (!map || !map->grid)
		return (0);
	count_map_elements(map);
	if (map->collectibles < 1 || map->exit != 1 || map->player != 1)
		return (0);
	find_player_pos(map);
	return (1);
}

void	find_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_map *map, char **visited, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (visited[y][x] || map->grid[y][x] == '1')
		return ;
	visited[y][x] = 1;
	flood_fill(map, visited, x + 1, y);
	flood_fill(map, visited, x - 1, y);
	flood_fill(map, visited, x, y + 1);
	flood_fill(map, visited, x, y - 1);
}
