#include "../../includes/so_long.h"

static void clean_wall_sprites(t_game *game)
{
    if (game->walls.top)
        mlx_destroy_image(game->mlx, game->walls.top);
    if (game->walls.bottom)
        mlx_destroy_image(game->mlx, game->walls.bottom);
    if (game->walls.left)
        mlx_destroy_image(game->mlx, game->walls.left);
    if (game->walls.right)
        mlx_destroy_image(game->mlx, game->walls.right);
    if (game->walls.corner_tl)
        mlx_destroy_image(game->mlx, game->walls.corner_tl);
    if (game->walls.corner_tr)
        mlx_destroy_image(game->mlx, game->walls.corner_tr);
    if (game->walls.corner_bl)
        mlx_destroy_image(game->mlx, game->walls.corner_bl);
    if (game->walls.corner_br)
        mlx_destroy_image(game->mlx, game->walls.corner_br);
    if (game->walls.block)
        mlx_destroy_image(game->mlx, game->walls.block);
}

static void	clean_collectible_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collectibles.frame_count)
	{
		if (game->collectibles.frames[i])
			mlx_destroy_image(game->mlx, game->collectibles.frames[i]);
		i++;
	}
}

static void	clean_door_sprites(t_game *game)
{
	int	i;

	if (game->door.closed)
		mlx_destroy_image(game->mlx, game->door.closed);
	i = 0;
	while (i < game->door.frame_count)
	{
		if (game->door.frames[i])
			mlx_destroy_image(game->mlx, game->door.frames[i]);
		i++;
	}
}

void	clean_game(t_game *game)
{
	clean_wall_sprites(game);
	clean_collectible_sprites(game);
	clean_door_sprites(game);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->map)
		free_map(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

int	handle_close(t_game *game)
{
	clean_game(game);
	exit(0);
	return (0);
}