/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:08:07 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/12 09:35:10 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == '?' || c == '\n');
}

int	validate_line_chars(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_valid_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	process_map_elements(t_map *map, int line_num, int line_length)
{
	int	i;

	i = 0;
	while (map->grid[line_num][i] && i < line_length)
	{
		if (map->grid[line_num][i] == 'C')
			map->collectibles++;
		else if (map->grid[line_num][i] == 'E')
			map->exit++;
		else if (map->grid[line_num][i] == 'P')
		{
			map->player++;
			map->player_x = i;
			map->player_y = line_num;
		}
		i++;
	}
}

int	read_map_line(int fd, t_map *map, int line_num)
{
	char	*line;
	int		line_length;

	line = get_next_line(fd);
	if (!line || !validate_line_chars(line))
	{
		free(line);
		return (0);
	}
	line_length = ft_strlen(line);
	if (!validate_map_line(line, map, line_length))
	{
		free(line);
		return (0);
	}
	map->grid[line_num] = ft_strdup(line);
	if (!map->grid[line_num])
	{
		free(line);
		return (0);
	}
	process_map_elements(map, line_num, line_length);
	free(line);
	return (1);
}

int	count_map_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!validate_line_chars(line))
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		lines++;
	}
	close(fd);
	return (lines);
}
