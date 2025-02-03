#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long map.ber\n", 31);
		return (1);
	}
	if (!init_game(&game))
		return (1);
	if (!read_map(&game, argv[1]))
	{
		clean_game(&game);
		return (1);
	}
	if (!init_window_dimensions(&game))
	{
		clean_game(&game);
		return (1);
	}
	if (!init_sprites(&game))
	{
		clean_game(&game);
		return (1);
	}
	launch_game(&game);
	return (0);
}