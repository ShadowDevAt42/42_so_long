/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 04:01:30 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 04:38:47 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	free_walls_and_background(t_game *game)
{
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->wall_top.img)
		mlx_destroy_image(game->mlx, game->wall_top.img);
	if (game->wall_bottom.img)
		mlx_destroy_image(game->mlx, game->wall_bottom.img);
	if (game->wall_left.img)
		mlx_destroy_image(game->mlx, game->wall_left.img);
	if (game->wall_right.img)
		mlx_destroy_image(game->mlx, game->wall_right.img);
	if (game->background.img)
		mlx_destroy_image(game->mlx, game->background.img);
}

static void	free_gameplay_elements(t_game *game)
{
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
}

static void	free_corner_elements(t_game *game)
{
	if (game->corner.top_left.img)
		mlx_destroy_image(game->mlx, game->corner.top_left.img);
	if (game->corner.top_right.img)
		mlx_destroy_image(game->mlx, game->corner.top_right.img);
	if (game->corner.bottom_left.img)
		mlx_destroy_image(game->mlx, game->corner.bottom_left.img);
	if (game->corner.bottom_right.img)
		mlx_destroy_image(game->mlx, game->corner.bottom_right.img);
}

static void	free_portal_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->portal.frames[i].img)
			mlx_destroy_image(game->mlx, game->portal.frames[i].img);
		i++;
	}
}

void	free_coin_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (game->coin.frames[i].img)
			mlx_destroy_image(game->mlx, game->coin.frames[i].img);
		i++;
	}
}

void	free_sprites(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	free_walls_and_background(game);
	free_gameplay_elements(game);
	free_corner_elements(game);
	free_portal_frames(game);
	free_coin_frames(game);
}

static t_error	init_game_elements(t_game *game)
{
	t_error	error;

	error = init_player(game);
	if (error != ERR_NONE)
		return (error);
	error = init_coin_anim(game);
	if (error != ERR_NONE)
		return (error);
	error = init_exit(game);
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

static t_error	init_map_elements(t_game *game)
{
	t_error	error;

	error = init_background(game);
	if (error != ERR_NONE)
		return (error);
	error = init_wall(game);
	if (error != ERR_NONE)
		return (error);
	error = init_corner(game);
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}

t_error	load_sprites(t_game *game)
{
	t_error	error;

	error = init_map_elements(game);
	if (error != ERR_NONE)
		return (error);
	error = init_game_elements(game);
	if (error != ERR_NONE)
		return (error);
	return (ERR_NONE);
}
