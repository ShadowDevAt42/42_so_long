/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:01:30 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 01:07:06 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_sprites(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->wall_top.img)
		mlx_destroy_image(game->mlx, game->wall_top.img);
	if (game->wall_bottom.img)
		mlx_destroy_image(game->mlx, game->wall_bottom.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->exit_open.img)
		mlx_destroy_image(game->mlx, game->exit_open.img);
	if (game->background.img)
		mlx_destroy_image(game->mlx, game->background.img);
	if (game->corner.top_left.img)
		mlx_destroy_image(game->mlx, game->corner.top_left.img);
	if (game->corner.top_right.img)
		mlx_destroy_image(game->mlx, game->corner.top_right.img);
	if (game->corner.bottom_left.img)
		mlx_destroy_image(game->mlx, game->corner.bottom_left.img);
	if (game->corner.bottom_right.img)
		mlx_destroy_image(game->mlx, game->corner.bottom_right.img);
}

t_error	load_sprites(t_game *game)
{
	t_error	error;

	error = init_background(game);
	if (error != ERR_NONE)
		return (error);
	error = init_wall(game);
	if (error != ERR_NONE)
		return (error);
	error = init_player(game);
	if (error != ERR_NONE)
		return (error);
	error = init_collectible(game);
	if (error != ERR_NONE)
		return (error);
	error = init_exit(game);
	if (error != ERR_NONE)
		return (error);
	error = init_exit_open(game);
	if (error != ERR_NONE)
		return (error);
	error = init_corner(game);
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}
