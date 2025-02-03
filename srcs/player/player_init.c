#include "../../includes/so_long.h"

void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	game->player_x = -1;
	game->player_y = -1;
}

int	validate_player_position(t_game *game)
{
	return (game->player_x >= 0 && game->player_x < game->width
		&& game->player_y >= 0 && game->player_y < game->height);
}