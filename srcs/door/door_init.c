/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 06:56:47 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/04 07:15:20 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	find_door_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
			{
				game->door.pos_x = x;
				game->door.pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	game->door.pos_x = -1;
	game->door.pos_y = -1;
}

static int	load_closed_door(t_game *game)
{
	ft_printf("Loading closed door sprite...\n");
	game->door.closed = mlx_xpm_file_to_image(game->mlx,
			"srcs/assets/door/Idle.xpm",
			&game->img_width, &game->img_height);
	if (!game->door.closed)
	{
		ft_printf("Error: Failed to load Idle.xpm\n");
		return (0);
	}
	ft_printf("Closed door sprite loaded successfully\n");
	return (1);
}

static int	load_door_frame(t_game *game, int frame_num)
{
	char	path[50];

	ft_memset(path, 0, 50);
	ft_strlcpy(path, "srcs/assets/door/anim0", 22);
	path[21] = (frame_num + 1) + '0';
	ft_strlcpy(path + 22, ".xpm", 5);
	
	ft_printf("Loading door frame: %s\n", path);
	game->door.frames[frame_num] = mlx_xpm_file_to_image(game->mlx,
			path, &game->img_width, &game->img_height);
	if (!game->door.frames[frame_num])
	{
		ft_printf("Error: Failed to load %s\n", path);
		return (0);
	}
	ft_printf("Frame %d loaded successfully\n", frame_num + 1);
	return (1);
}

static void	init_door_values(t_game *game)
{
	int	i;

	game->door.frame_count = 5;
	game->door.current_frame = 0;
	game->door.is_animating = 0;
	game->door.is_open = 0;
	game->door.anim_timer = 0;
	
	// Initialiser tous les pointeurs à NULL
	game->door.closed = NULL;
	i = 0;
	while (i < game->door.frame_count)
	{
		game->door.frames[i] = NULL;
		i++;
	}
	ft_printf("Initial collectibles: %d/%d\n", 
		game->collected, game->collectible_count);
}

int	init_door_sprites(t_game *game)
{
	int	i;

	if (!game || !game->mlx)
		return (0);

	init_door_values(game);
	find_door_position(game);
	
	if (game->door.pos_x == -1 || game->door.pos_y == -1)
	{
		ft_printf("Error: No exit door (E) found in map\n");
		return (0);
	}

	if (!load_closed_door(game))
		return (0);

	i = 0;
	while (i < game->door.frame_count)
	{
		if (!load_door_frame(game, i))
		{
			// En cas d'erreur, on nettoie les frames déjà chargées
			while (--i >= 0)
			{
				if (game->door.frames[i])
					mlx_destroy_image(game->mlx, game->door.frames[i]);
			}
			if (game->door.closed)
				mlx_destroy_image(game->mlx, game->door.closed);
			return (0);
		}
		i++;
	}
	ft_printf("Door initialization completed successfully\n");
	return (1);
}