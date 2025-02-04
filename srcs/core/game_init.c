#include "../../includes/so_long.h"

int	init_game(t_game *game)
{
	game->img_width = 64;
	game->img_height = 64;
	// game->scale = 1;
	game->moves = 0;
	game->player_screen_x = 0;
    game->player_screen_y = 0;
    game->is_moving = 0;
    game->move_direction_x = 0;
    game->move_direction_y = 0;
    game->target_x = 0;
    game->target_y = 0;
	game->collected = 0;
	game->collectible_count = 0;
	game->map = NULL;
	game->player_img = NULL;
	game->win = NULL;
	game->walls.top = NULL;
	game->walls.bottom = NULL;
	game->walls.left = NULL;
	game->walls.right = NULL;
	game->walls.corner_tl = NULL;
	game->walls.corner_tr = NULL;
	game->walls.corner_bl = NULL;
	game->walls.corner_br = NULL;
	game->walls.block = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error\nFailed to initialize MLX\n", 30);
		return (0);
	}
	return (1);
}

static int  load_wall_sprites(t_game *game)
{
    game->walls.top = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/top.xpm", &game->img_width, &game->img_height);
    game->walls.bottom = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/bottom.xpm", &game->img_width, &game->img_height);
    game->walls.left = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/wall_l.xpm", &game->img_width, &game->img_height);
    game->walls.right = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/wall_r.xpm", &game->img_width, &game->img_height);
    game->walls.corner_tl = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/corner_h_l.xpm", &game->img_width, &game->img_height);
    game->walls.corner_tr = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/corner_h_r.xpm", &game->img_width, &game->img_height);
    game->walls.corner_bl = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/corner_b_l.xpm", &game->img_width, &game->img_height);
    game->walls.corner_br = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/corner_b_r.xpm", &game->img_width, &game->img_height);
    game->walls.block = mlx_xpm_file_to_image(game->mlx,
        "srcs/assets/wall/bloc.xpm", &game->img_width, &game->img_height);
    return (game->walls.top && game->walls.bottom && game->walls.left
        && game->walls.right && game->walls.corner_tl && game->walls.corner_tr
        && game->walls.corner_bl && game->walls.corner_br && game->walls.block);
}

int	init_sprites(t_game *game)
{
	int	i;

	if (!load_wall_sprites(game))
	{
		write(2, "Error\nFailed to load wall sprites\n", 33);
		return (0);
	}
	// Initialiser les frames à NULL
	i = 0;
	while (i < 10)
	{
		game->collectibles.frames[i] = NULL;
		i++;
	}
	if (!init_collectible_sprites(game))
	{
		return (0);
	}
	if (!init_door_sprites(game))
	{
    write(2, "Error\nFailed to load door sprites\n", 33);
    return (0);
	}
	game->player_img = mlx_xpm_file_to_image(game->mlx, 
		"srcs/assets/player/player.xpm",
		&game->img_width, &game->img_height);
	if (!game->player_img)
	{
		write(2, "Error\nFailed to load player sprite\n", 34);
		return (0);
	}
	return (1);
}