#include "../../includes/so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
		return (handle_close(game));
	
	if (handle_movement(game, keysym))
	{
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
	}
	return (0);
}

int	handle_destroy(t_game *game)
{
	clean_game(game);
	exit(0);
	return (0);
}

int	redraw(t_game *game)
{
	draw_map(game);
	return (0);
}