/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:21:14 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 23:24:02 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_error	init_wall_basic(t_game *game)
{
	t_error	error;

	error = load_sprite(game, &game->wall.wall,
			"srcs/assets/wall/interne/bloc.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.top, "srcs/assets/wall/top.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.bottom,
			"srcs/assets/wall/bottom.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.left, "srcs/assets/wall/wall_l.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.right, "srcs/assets/wall/wall_r.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

t_error	init_wall_internal_h(t_game *game)
{
	t_error	error;

	error = load_sprite(game, &game->wall.int_h_left,
			"srcs/assets/wall/interne/int_h_cl.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_h_right,
			"srcs/assets/wall/interne/int_h_cr.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_h_center,
			"srcs/assets/wall/interne/int_h_center.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

t_error	init_wall_internal_v(t_game *game)
{
	t_error	error;

	error = load_sprite(game, &game->wall.int_v_top,
			"srcs/assets/wall/interne/int_v_ct.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_v_center,
			"srcs/assets/wall/interne/int_v_center.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_v_bottom,
			"srcs/assets/wall/interne/int_v_cb.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

t_error	init_wall_internal_m1(t_game *game)
{
	t_error	error;

	error = load_sprite(game, &game->wall.int_m_ctl,
			"srcs/assets/wall/interne/int_m_ctl.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_m_ctr,
			"srcs/assets/wall/interne/int_m_ctr.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_m_cbl,
			"srcs/assets/wall/interne/int_m_cbl.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_m_cbr,
			"srcs/assets/wall/interne/int_m_cbr.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

t_error	init_wall_internal_m2(t_game *game)
{
	t_error	error;

	error = load_sprite(game, &game->wall.int_m_wt,
			"srcs/assets/wall/interne/int_m_wt.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_m_wb,
			"srcs/assets/wall/interne/int_m_wb.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_m_wl,
			"srcs/assets/wall/interne/int_m_wl.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_m_wr,
			"srcs/assets/wall/interne/int_m_wr.xpm");
	if (error != ERR_NONE)
		return (error);
	error = load_sprite(game, &game->wall.int_m_center,
			"srcs/assets/wall/interne/int_m_center.xpm");
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}
