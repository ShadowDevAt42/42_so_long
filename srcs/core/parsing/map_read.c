/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:08:07 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/12 11:28:09 by fdi-tria         ###   ########.fr       */
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

static void	cleanup_remaining_lines(int fd)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
	}
}

int	read_map_line(int fd, t_map *map, int line_num)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	if (!validate_line_chars(line))
	{
		free(line);
		cleanup_remaining_lines(fd);
		return (0);
	}
	map->grid[line_num] = ft_strdup(line);
	free(line);
	if (!map->grid[line_num])
		return (0);
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
			cleanup_remaining_lines(fd);
			close(fd);
			return (-1);
		}
		free(line);
		lines++;
	}
	close(fd);
	return (lines);
}
