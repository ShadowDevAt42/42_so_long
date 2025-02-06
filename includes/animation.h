/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:41:21 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 04:41:23 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "struc.h"

// Portal animation functions
void		update_portal_anim(t_game *game);
void		start_portal_anim(t_game *game);
void		render_portal(t_game *game, int x, int y);
t_error		init_portal_anim(t_game *game);

// Coin animation functions
void		update_coin_anim(t_game *game);
void		render_coin(t_game *game, int x, int y);
t_error		init_coin_anim(t_game *game);

#endif