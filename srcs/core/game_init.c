#include "../../includes/so_long.h"

int	init_game(t_game *game)
{
	game->img_width = 32;
	game->img_height = 32;
	game->scale = 1;
	game->moves = 0;
	game->map = NULL;
	game->wall_img = NULL;
	game->player_img = NULL;
	game->win = NULL;
	
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error\nFailed to initialize MLX\n", 30);
		return (0);
	}
	return (1);
}

int	init_sprites(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", 
		&game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", 
		&game->img_width, &game->img_height);
	
	if (!game->wall_img || !game->player_img)
	{
		write(2, "Error\nFailed to load sprites\n", 28);
		return (0);
	}
	return (1);
}