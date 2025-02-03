#include "../../includes/so_long.h"

// static int	can_move_to(t_game *game, int x, int y)
// {
// 	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
// 		return (0);
// 	return (game->map[y][x] != '1');
// }

// static int	move_until_wall(t_game *game, int dx, int dy)
// {
// 	int	new_x;
// 	int	new_y;
// 	int	moved;

// 	moved = 0;
// 	new_x = game->player_x;
// 	new_y = game->player_y;
// 	while (new_x + dx >= 0 && new_x + dx < game->width &&
// 		new_y + dy >= 0 && new_y + dy < game->height &&
// 		game->map[new_y + dy][new_x + dx] != '1')
// 	{
// 		new_x += dx;
// 		new_y += dy;
// 		moved = 1;
// 	}
// 	if (moved)
// 	{
// 		game->player_x = new_x;
// 		game->player_y = new_y;
// 		game->moves++;
// 		ft_printf("Moves: %d\n", game->moves);
// 	}
// 	return (moved);
// }

int handle_movement(t_game *game, int keysym)
{
    int dx;
    int dy;

    if (game->is_moving)
        return (0);

    dx = 0;
    dy = 0;

    if (keysym == KEY_W || keysym == KEY_UP)
        dy = -1;
    else if (keysym == KEY_S || keysym == KEY_DOWN)
        dy = 1;
    else if (keysym == KEY_A || keysym == KEY_LEFT)
        dx = -1;
    else if (keysym == KEY_D || keysym == KEY_RIGHT)
        dx = 1;
    
    if (dx == 0 && dy == 0)
        return (0);

    if (game->map[game->player_y + dy][game->player_x + dx] != '1')
    {
        game->is_moving = 1;
        game->move_direction_x = dx;
        game->move_direction_y = dy;
        game->target_x = game->player_x + dx;
        game->target_y = game->player_y + dy;
        game->moves++;
        ft_printf("Moves: %d\n", game->moves);
        return (1);
    }

    return (0);
}