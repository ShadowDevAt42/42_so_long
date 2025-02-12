/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:06:56 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/12 09:41:00 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	check_line_length(t_map *map, int i)
{
	int	len;

	if (!map->grid[i])
		return (0);
	len = ft_strlen(map->grid[i]);
	if (map->grid[i][len - 1] == '\n')
		len--;
	if (i == 0)
		map->width = len;
	else if (len != map->width)
		return (0);
	return (1);
}

int	check_rectangle(t_map *map)
{
	int	i;

	if (!map || !map->grid || map->height <= 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (!check_line_length(map, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((i == 0 || i == map->height - 1
					|| j == 0 || j == map->width - 1))
			{
				if (map->grid[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

int	validate_dimensions(t_map *map)
{
	if (!map)
		return (0);
	if (map->width <= 2 || map->height <= 2)
		return (0);
	if (map->width * SPRITE_SIZE > MAX_WIDTH)
		return (0);
	if (map->height * SPRITE_SIZE > MAX_HEIGHT)
		return (0);
	return (1);
}
