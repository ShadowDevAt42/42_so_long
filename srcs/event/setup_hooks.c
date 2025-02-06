/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:11:22 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 04:06:31 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	setup_hooks(t_game *game)
{
	// Hooks existants
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0L, handle_close, game);
	mlx_hook(game->win, 12, 1L << 15, handle_expose, game);
	
	// Hook pour l'animation avec intervalle
	mlx_do_sync(game->mlx);  // Synchroniser avec le serveur X
}