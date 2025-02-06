#include "../../includes/so_long.h"

t_error	init_corner(t_game *game)
{
	int				width;
	int				height;
	t_error_info	error_info;
	char			*sprite_path;

	// Initialisation du coin en haut à gauche (corner_t_l)
	sprite_path = "srcs/assets/wall/corner_h_l.xpm";
	error_info.sprite_path = sprite_path;
	error_info.additional_info = NULL;
	game->corner.top_left.img = mlx_xpm_file_to_image(game->mlx, sprite_path, &width, &height);
	if (!game->corner.top_left.img)
	{
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	game->corner.top_left.width = width;
	game->corner.top_left.height = height;
	game->corner.top_left.addr = mlx_get_data_addr(game->corner.top_left.img,
		&game->corner.top_left.bits_per_pixel,
		&game->corner.top_left.line_length,
		&game->corner.top_left.endian);

	// Initialisation du coin en haut à droite (corner_t_r)
	sprite_path = "srcs/assets/wall/corner_h_r.xpm";
	error_info.sprite_path = sprite_path;
	game->corner.top_right.img = mlx_xpm_file_to_image(game->mlx, sprite_path, &width, &height);
	if (!game->corner.top_right.img)
	{
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	game->corner.top_right.width = width;
	game->corner.top_right.height = height;
	game->corner.top_right.addr = mlx_get_data_addr(game->corner.top_right.img,
		&game->corner.top_right.bits_per_pixel,
		&game->corner.top_right.line_length,
		&game->corner.top_right.endian);

	// Initialisation du coin en bas à gauche (corner_b_l)
	sprite_path = "srcs/assets/wall/corner_b_l.xpm";
	error_info.sprite_path = sprite_path;
	game->corner.bottom_left.img = mlx_xpm_file_to_image(game->mlx, sprite_path, &width, &height);
	if (!game->corner.bottom_left.img)
	{
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	game->corner.bottom_left.width = width;
	game->corner.bottom_left.height = height;
	game->corner.bottom_left.addr = mlx_get_data_addr(game->corner.bottom_left.img,
		&game->corner.bottom_left.bits_per_pixel,
		&game->corner.bottom_left.line_length,
		&game->corner.bottom_left.endian);

	// Initialisation du coin en bas à droite (corner_b_r)
	sprite_path = "srcs/assets/wall/corner_b_r.xpm";
	error_info.sprite_path = sprite_path;
	game->corner.bottom_right.img = mlx_xpm_file_to_image(game->mlx, sprite_path, &width, &height);
	if (!game->corner.bottom_right.img)
	{
		handle_error_with_info(ERR_SPRITE_LOAD, &error_info);
		return (ERR_SPRITE_LOAD);
	}
	game->corner.bottom_right.width = width;
	game->corner.bottom_right.height = height;
	game->corner.bottom_right.addr = mlx_get_data_addr(game->corner.bottom_right.img,
		&game->corner.bottom_right.bits_per_pixel,
		&game->corner.bottom_right.line_length,
		&game->corner.bottom_right.endian);

	return (ERR_NONE);
}

// ...existing code...
