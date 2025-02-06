/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:09:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 16:38:33 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

// # include "struc.h"

t_error		validate_all(char *map_path, t_map **map);
t_error		validate_map_file(char *map_path, t_map **map);

int			check_rectangle(t_map *map);
int			check_walls(t_map *map);
int			validate_extension(char *filename);
int			validate_dimensions(t_map *map);
int			validate_elements(t_map *map);
int			validate_path(t_map *map);

int			count_map_lines(char *filename);
int			validate_line_chars(char *line);
int			read_map_line(int fd, t_map *map, int line_num);
t_map		*load_map(char *filename);

void		find_player_pos(t_map *map);
void		flood_fill(t_map *map, char **visited, int x, int y);
int			check_reachable_elements(t_map *map, char **visited);

#endif
