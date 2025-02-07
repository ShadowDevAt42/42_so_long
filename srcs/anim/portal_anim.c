/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:04:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 09:49:48 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_portal_anim(t_game *game)
{
	if (!game->portal.is_animating)
		return ;
	game->portal.current_frame = (game->portal.current_frame + 1) % 6;
}

void	start_portal_anim(t_game *game)
{
	if (!game->portal.is_animating)
	{
		game->portal.is_animating = 1;
		game->portal.current_frame = 0;
	}
}
