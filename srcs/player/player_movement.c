#include "../../includes/so_long.h"

static int	can_move_to(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (0);
	return (game->map[y][x] != '1');
}

int	handle_movement(t_game *game, int keysym)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keysym == KEY_W || keysym == KEY_UP)
		new_y--;
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		new_y++;
	else if (keysym == KEY_A || keysym == KEY_LEFT)
		new_x--;
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		new_x++;
	if (can_move_to(game, new_x, new_y))
	{
		game->player_x = new_x;
		game->player_y = new_y;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		return (1);
	}
	return (0);
}