#include "../../includes/so_long.h"

static int	setup_game_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L<<0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, handle_destroy, game);
	mlx_hook(game->win, 12, 1L<<15, redraw, game);
	return (1);
}

int	launch_game(t_game *game)
{
	find_player_position(game);
	if (!validate_player_position(game))
	{
		write(2, "Error\nInvalid player position\n", 29);
		return (0);
	}
	setup_game_hooks(game);
	draw_map(game);
	mlx_loop(game->mlx);
	return (1);
}