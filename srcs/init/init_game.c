/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:54:45 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 03:04:36 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_error	load_wall_sprite(t_game *game)
{
    int	width;
    int	height;

    game->wall.img = mlx_xpm_file_to_image(game->mlx, "srcs/assets/wall/bloc.xpm",
            &width, &height);
    if (!game->wall.img)
        return (ERR_MALLOC);
    game->wall.width = width;
    game->wall.height = height;
    return (ERR_NONE);
}

static void	render_wall(t_game *game, int x, int y)
{
    mlx_put_image_to_window(game->mlx, game->win, game->wall.img,
        x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	render_map(t_game *game)
{
    int	y;
    int	x;

    y = 0;
    while (y < game->map->height)
    {
        x = 0;
        while (x < game->map->width)
        {
            if (game->map->grid[y][x] == '1')
                render_wall(game, x, y);
            x++;
        }
        y++;
    }
}

t_game  *init_game(t_map *map)
{
    t_game  *game;

    ft_printf("Initializing game...\n");  // Debug print
    game = (t_game *)ft_calloc(1, sizeof(t_game));
    if (!game)
    {
        ft_printf("Failed to allocate game structure\n");
        return (NULL);
    }
    game->map = map;
    ft_printf("Initializing MLX...\n");  // Debug print
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_printf("Failed to initialize MLX\n");
        free(game);
        return (NULL);
    }
    ft_printf("Creating window...\n");  // Debug print
    game->win = mlx_new_window(game->mlx,
            map->width * SPRITE_SIZE,
            map->height * SPRITE_SIZE,
            "so_long");
    if (!game->win)
    {
        ft_printf("Failed to create window\n");
        free(game);
        return (NULL);
    }
    ft_printf("Loading wall sprite...\n");  // Debug print
    if (load_wall_sprite(game) != ERR_NONE)
    {
        ft_printf("Failed to load wall sprite\n");
        mlx_destroy_window(game->mlx, game->win);
        free(game);
        return (NULL);
    }
    ft_printf("Rendering map...\n");  // Debug print
    render_map(game);
    ft_printf("Game initialization complete!\n");  // Debug print
    mlx_hook(game->win, 17, 0, close_window, game);  // Ajout de cette ligne
    render_map(game);
    return (game);
}

int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_image(game->mlx, game->wall.img);
    free(game);
    exit(0);
    return (0);
}