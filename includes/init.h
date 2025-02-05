/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:05:46 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 03:03:02 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struc.h"

t_map		*init_map(void);
void		free_map(t_map *map);

t_game	*init_game(t_map *map);
void	render_map(t_game *game);
int close_window(t_game *game);

#endif