/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:11:22 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 04:11:27 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    setup_hooks(t_game *game)
{
    // Gestion de la touche Echap et autres touches
    mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
    
    // Gestion du clic sur la croix de la fenêtre
    mlx_hook(game->win, 17, 0L, handle_close, game);
    
    // Gestion du rafraîchissement de la fenêtre (réduction, etc.)
    mlx_hook(game->win, 12, 1L << 15, handle_expose, game);
}