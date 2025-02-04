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

static void	put_wall_sprite(t_game *game, int x, int y)
{
	if (y == 0)
	{
		if (x == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->walls.corner_tl, x * game->img_width, y * game->img_height);
		else if (x == game->width - 1)
			mlx_put_image_to_window(game->mlx, game->win,
				game->walls.corner_tr, x * game->img_width, y * game->img_height);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->walls.top, x * game->img_width, y * game->img_height);
	}
	else if (y == game->height - 1)
	{
		if (x == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->walls.corner_bl, x * game->img_width, y * game->img_height);
		else if (x == game->width - 1)
			mlx_put_image_to_window(game->mlx, game->win,
				game->walls.corner_br, x * game->img_width, y * game->img_height);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->walls.bottom, x * game->img_width, y * game->img_height);
	}
	else if (x == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->walls.left, x * game->img_width, y * game->img_height);
	else if (x == game->width - 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->walls.right, x * game->img_width, y * game->img_height);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->walls.block, x * game->img_width, y * game->img_height);
}

static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E' && !game->door.is_animating 
				&& !game->door.is_open)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->door.closed, x * game->img_width,
					y * game->img_height);
			}
			x++;
		}
		y++;
	}
}

static void	draw_walls(t_game *game)
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
				put_wall_sprite(game, x, y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	
	draw_floor(game);
	draw_walls(game);
	draw_collectibles(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_img, (int)game->player_screen_x,
		(int)game->player_screen_y);
	if (game->door.is_animating || game->door.is_open)
		draw_door(game);
}