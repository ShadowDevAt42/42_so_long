/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:01:30 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 17:47:53 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_sprites(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
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
	return (ERR_NONE);
}
