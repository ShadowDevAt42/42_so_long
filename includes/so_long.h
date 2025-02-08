/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:39:36 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 18:27:08 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Includes
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/includes/libft.h"
# include "struc.h"
# include "core.h"
# include "error.h"
# include <fcntl.h>
# include <stdio.h>

// Constants
# define SPRITE_SIZE 64
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1080
# define MAP_CHARS "01CEP\n"
# define COIN_ANIM_SPEED 10000
# define PORTAL_TRANSITION_SPEED 7500
# define PORTAL_OPEN_SPEED 25000
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

#endif
