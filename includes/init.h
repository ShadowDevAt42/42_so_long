/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:05:46 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:00:50 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struc.h"

/* init_map.c */
t_map		*init_map(void);
void		free_map(t_map *map);

/* init_window.c */
t_game  *init_window(t_map *map);
void    free_window(t_game *game);
int     close_window(t_game *game);

/* init_sprite.c */
t_error load_sprites(t_game *game);
void    free_sprites(t_game *game);

/* init_wall.c */
t_error init_wall(t_game *game);

#endif