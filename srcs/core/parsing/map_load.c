/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:08:34 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 10:43:10 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_map	*allocate_map_grid(int height)
{
	t_map	*map;

	map = init_map();
	if (!map)
		return (NULL);
	map->height = height;
	map->grid = malloc(sizeof(char *) * height);
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

static t_map	*parse_map_lines(int fd, t_map *map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (!read_map_line(fd, map, i))
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
		i++;
	}
	return (map);
}

t_map	*load_map(char *filename)
{
	t_map	*map;
	int		fd;
	int		height;

	height = count_map_lines(filename);
	if (height == 0)
		return ((t_map *)-1);
	if (height == -1)
		return ((t_map *)-2);
	if (height < 0)
		return (NULL);
	map = allocate_map_grid(height);
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		return (NULL);
	}
	map = parse_map_lines(fd, map, height);
	close(fd);
	return (map);
}
