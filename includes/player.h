/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:34:28 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:34:53 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "struc.h"

// Prototypes
int     move_player(t_game *game, int dx, int dy);
void    handle_player_movement(t_game *game, int keycode);
int     is_valid_move(t_game *game, int new_x, int new_y);

#endif