/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:34:57 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/12 09:39:29 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	validate_map_line(char *line, t_map *map, int line_length)
{
	if (line[line_length - 1] == '\n')
		line_length--;
	if (map->width == 0)
		map->width = line_length;
	else if (line_length != map->width)
		return (0);
	return (1);
}
