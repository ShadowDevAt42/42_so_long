#include "../../includes/so_long.h"

void	clean_game(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
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