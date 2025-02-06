/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:39:36 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 04:46:49 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include "init.h"
# include "error.h"
# include "map.h"
# include "render.h"
# include "event.h"
# include "player.h"
# include "animation.h"
# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"
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