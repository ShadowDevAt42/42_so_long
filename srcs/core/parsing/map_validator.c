/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:08:51 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/12 09:03:31 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_error	validate_map_content(t_map *map)
{
	if (!check_rectangle(map))
		return (ERR_NOT_RECT);
	if (!check_walls(map))
		return (ERR_NO_WALLS);
	if (!validate_elements(map))
	{
		if (map->player == 0)
			return (ERR_NO_PLAYER);
		if (map->player > 1)
			return (ERR_MULTI_PLAYER);
		if (map->exit == 0)
			return (ERR_NO_EXIT);
		if (map->exit > 1)
			return (ERR_MULTI_EXIT);
		if (map->collectibles == 0)
			return (ERR_NO_COLLECT);
	}
	if (!validate_dimensions(map))
		return (ERR_TOO_BIG);
	if (!validate_path(map))
		return (ERR_PATH);
	return (ERR_NONE);
}

t_error	validate_map_file(char *map_path, t_map **map)
{
	if (!map_path)
	{
		return (ERR_ARGS);
	}
	if (!validate_extension(map_path))
	{
		return (ERR_EXTENSION);
	}
	*map = load_map(map_path);
	if (*map == (t_map *)-1)
	{
		return (ERR_EMPTY);
	}
	if (*map == (t_map *)-2)
	{
		return (ERR_INVALID_CHAR);
	}
	if (*map == (t_map *)-3)
	{
		return (ERR_NOT_RECT);
	}
	if (!*map)
	{
		return (ERR_OPEN);
	}
	return (ERR_NONE);
}

t_error	validate_all(char *map_path, t_map **map)
{
	t_error	error;

	error = validate_map_file(map_path, map);
	if (error != ERR_NONE)
		return (error);
	error = validate_map_content(*map);
	if (error != ERR_NONE)
	{
		free_map(*map);
		*map = NULL;
		return (error);
	}
	return (ERR_NONE);
}
