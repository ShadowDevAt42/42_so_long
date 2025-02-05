/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:02:58 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:50:48 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "struc.h"

void    render_walls(t_game *game);
void    render_player(t_game *game);
void    render_collectibles(t_game *game);
void    render_exit(t_game *game);
void    render_game(t_game *game);

#endif