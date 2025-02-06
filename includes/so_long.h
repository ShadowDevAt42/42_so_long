/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:39:36 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 23:03:00 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/includes/libft.h"
# include "struc.h"
# include "core.h"
# include "map.h"
# include "error.h"
# include "render.h"
// # include "event.h"
# include "player.h"
# include "animation.h"
# include <fcntl.h>
# include <stdio.h>

// Constants
# define SPRITE_SIZE 64
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080
# define MAP_CHARS "01CEP\n"
# define COIN_ANIM_SPEED 10000
# define PORTAL_ANIM_SPEED 40000

#endif