#include "../../includes/so_long.h"

int	check_map_dimensions(t_game *game)
{
	int	window_width;
	int	window_height;

	window_width = game->width * game->img_width;
	window_height = game->height * game->img_height;
	if (window_width <= 0 || window_height <= 0 || 
		window_width > 1920 || window_height > 1080)
	{
		write(2, "Error\nInvalid map dimensions\n", 28);
		return (0);
	}
	return (1);
}