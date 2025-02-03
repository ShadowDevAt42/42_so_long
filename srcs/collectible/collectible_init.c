/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:48:22 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/03 20:18:26 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->collectible_count = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
				game->collectible_count++;
			x++;
		}
		y++;
	}
}

int	init_collectible_sprites(t_game *game)
{
	static const char	*base_path = "srcs/assets/collectible/diam";
	char				full_path[50];
	int					i;

	game->collectibles.frame_count = 10;
	game->collectibles.current_frame = 0;
	game->collected = 0;
	i = 0;
	while (i < game->collectibles.frame_count)
	{
		ft_memset(full_path, 0, 50);
		ft_strlcpy(full_path, base_path, 29);
		if (i < 9)
		{
			full_path[28] = '0';
			full_path[29] = (i + 1) + '0';
			full_path[30] = '.';
			full_path[31] = 'x';
			full_path[32] = 'p';
			full_path[33] = 'm';
			full_path[34] = '\0';
		}
		else
		{
			full_path[28] = '1';
			full_path[29] = '0';
			full_path[30] = '.';
			full_path[31] = 'x';
			full_path[32] = 'p';
			full_path[33] = 'm';
			full_path[34] = '\0';
		}
		game->collectibles.frames[i] = mlx_xpm_file_to_image(game->mlx,
				full_path, &game->img_width, &game->img_height);
		if (!game->collectibles.frames[i])
		{
			ft_printf("Error\nFailed to load: %s\n", full_path);
			return (0);
		}
		i++;
	}
	count_collectibles(game);
	return (1);
}