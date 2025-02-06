#include "../../includes/so_long.h"

void	render_corner(t_game *game)
{
	int	tile_w;
	int	tile_h;

	if (!game || !game->mlx || !game->win || !game->corner.top_left.img ||
		!game->corner.top_right.img || !game->corner.bottom_left.img ||
		!game->corner.bottom_right.img)
		return;

	tile_w = game->corner.top_left.width;
	tile_h = game->corner.top_left.height;
	
	// Affichage du coin en haut à gauche
	mlx_put_image_to_window(game->mlx, game->win, game->corner.top_left.img, 0, 0);
	
	// Affichage du coin en haut à droite
	mlx_put_image_to_window(game->mlx, game->win, game->corner.top_right.img, 
		(game->map->width - 1) * tile_w, 0);
	
	// Affichage du coin en bas à gauche
	mlx_put_image_to_window(game->mlx, game->win, game->corner.bottom_left.img, 
		0, (game->map->height - 1) * tile_h);
	
	// Affichage du coin en bas à droite
	mlx_put_image_to_window(game->mlx, game->win, game->corner.bottom_right.img, 
		(game->map->width - 1) * tile_w, (game->map->height - 1) * tile_h);
}

// ...existing code...
