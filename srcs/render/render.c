/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:39:55 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 00:25:57 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_background(game);
	render_walls(game);
	render_corner(game); // appel ajouté pour afficher les coins
	render_collectibles(game);
	render_exit(game);
	render_player(game);
	render_ui(game);
	render_collectibles_ui(game);
}
