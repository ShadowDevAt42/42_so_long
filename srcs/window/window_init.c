#include "../../includes/so_long.h"

int	init_window_dimensions(t_game *game)
{
	int	window_width;
	int	window_height;

	if (!check_map_dimensions(game))
		return (0);
	window_width = game->width * game->img_width;
	window_height = game->height * game->img_height;
	game->win = mlx_new_window(game->mlx, window_width, 
		window_height, "so_long");
	return (game->win != NULL);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, 
					game->wall_img, x * game->img_width, 
					y * game->img_height);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_img,
		game->player_x * game->img_width,
		game->player_y * game->img_height);
}