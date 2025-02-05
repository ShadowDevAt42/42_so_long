/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:10:57 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:11:02 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# include "struc.h"

// Codes des touches
# define KEY_ESC 65307

// Gestionnaires d'événements
void    setup_hooks(t_game *game);
int     handle_keypress(int keycode, t_game *game);
int     handle_close(t_game *game);
int     handle_expose(t_game *game);

#endif