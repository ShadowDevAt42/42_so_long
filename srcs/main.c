/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:13:32 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 01:22:06 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_error	error;

	if (argc != 2)
	{
		handle_error(ERR_ARGS);
		return (1);
	}
	map = NULL;
	error = validate_all(argv[1], &map);
	if (error != ERR_NONE)
	{
		handle_error(error);
		return (1);
	}
	// Ici, la map est valide et prête à être utilisée
	free_map(map);
	return (0);
}
// #include "../includes/core.h"

// static void	print_test_result(char *map_path, char *expected, t_error error)
// {
// 	ft_printf("\nTesting map: %s\n", map_path);
// 	ft_printf("Expected: %s\n", expected);
// 	ft_printf("Result: %s\n", get_error_message(error));
// }

// static t_error	validate_map(t_map *map)
// {
// 	if (!map)
// 		return (ERR_MALLOC);
// 	if (!check_rectangle(map))
// 		return (ERR_NOT_RECT);
// 	if (!check_walls(map))
// 		return (ERR_NO_WALLS);
// 	if (!validate_elements(map))
// 	{
// 		if (map->player == 0)
// 			return (ERR_NO_PLAYER);
// 		if (map->player > 1)
// 			return (ERR_MULTI_PLAYER);
// 		if (map->exit == 0)
// 			return (ERR_NO_EXIT);
// 		if (map->exit > 1)
// 			return (ERR_MULTI_EXIT);
// 		if (map->collectibles == 0)
// 			return (ERR_NO_COLLECT);
// 	}
// 	if (!validate_dimensions(map))
// 		return (ERR_TOO_BIG);
// 	return (ERR_NONE);
// }

// static void	test_map(char *map_path, char *expected_error)
// {
// 	t_map	*map;
// 	t_error	error;

// 	if (!validate_extension(map_path))
// 	{
// 		print_test_result(map_path, expected_error, ERR_EXTENSION);
// 		return ;
// 	}
// 	map = load_map(map_path);
// 	if (!map)
// 	{
// 		print_test_result(map_path, expected_error, ERR_OPEN);
// 		return ;
// 	}
// 	error = validate_map(map);
// 	print_test_result(map_path, expected_error, error);
// 	free_map(map);
// }
// int	main(void)
// {
// 	ft_printf("Starting map validation tests:\n");
// 	ft_printf("--------------------------------\n");

// 	test_map("maps/test/map1.ber", "Valid map");
// 	test_map("maps/test/test.ber", "Valid map");
// 	test_map("maps/test/no_exist.ber", "File not found");
// 	test_map("maps/test/wrong_ext.txt", "Wrong extension");
// 	test_map("maps/test/empty.ber", "Empty map");
// 	test_map("maps/test/no_player.ber", "No player");
// 	test_map("maps/test/no_exit.ber", "No exit");
// 	test_map("maps/test/no_collect.ber", "No collectibles");
// 	test_map("maps/test/multi_player.ber", "Multiple players");
// 	test_map("maps/test/multi_exit.ber", "Multiple exits");
// 	test_map("maps/test/invalid_char.ber", "Invalid characters");
// 	test_map("maps/test/not_rect.ber", "Not rectangular");
// 	test_map("maps/test/open_walls.ber", "Walls not closed");
// 	test_map("maps/test/too_big.ber", "Map too big");
// 	return (0);
// }