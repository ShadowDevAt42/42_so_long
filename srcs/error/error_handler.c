/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:45:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 18:23:56 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static const t_error_msg	*get_error_table(void)
{
	static const t_error_msg	errors[] = {
	{ERR_NONE, "No error"},
	{ERR_ARGS, "Usage: ./so_long <map.ber>"},
	{ERR_EXTENSION, "Map file must have .ber extension"},
	{ERR_OPEN, "Failed to open or read map file"},
	{ERR_EMPTY, "Map file is empty"},
	{ERR_MALLOC, "Memory allocation failed"},
	{ERR_INVALID_CHAR, "Map contains invalid characters"},
	{ERR_NOT_RECT, "Map must be rectangular"},
	{ERR_NO_WALLS, "Map must be surrounded by walls"},
	{ERR_NO_PLAYER, "Map must contain exactly one player position (P)"},
	{ERR_MULTI_PLAYER, "Map contains multiple player positions (P)"},
	{ERR_NO_EXIT, "Map must contain exactly one exit (E)"},
	{ERR_MULTI_EXIT, "Map contains multiple exits (E)"},
	{ERR_NO_COLLECT, "Map must contain at least one collectible (C)"},
	{ERR_TOO_BIG, "Map dimensions exceed maximum allowed size"},
	{ERR_PATH, "No valid path exists in map"},
	{ERR_MLX_INIT, "Failed to initialize MLX"},
	{ERR_WIN_INIT, "Failed to create window"},
	{ERR_SPRITE_LOAD, "Failed to load sprite"},
	{ERR_IMG_CREATE, "Failed to create image"},
	{ERR_SPRITE_PATH, "Invalid sprite path"}
	};

	return (errors);
}

static char	*get_error_message(t_error error_code)
{
	const t_error_msg	*errors;
	int					i;
	int					count;

	errors = get_error_table();
	i = 0;
	count = 21;
	while (i < count)
	{
		if (errors[i].code == error_code)
			return (errors[i].message);
		i++;
	}
	return ("Unknown error occurred");
}

static void	print_additional_info(t_error_info *error_info)
{
	if (!error_info)
		return ;
	if (error_info->sprite_path)
		ft_printf("Sprite path: %s\n", error_info->sprite_path);
	if (error_info->additional_info)
		ft_printf("Additional info: %s\n", error_info->additional_info);
}

void	handle_error_with_info(t_error error_code, t_error_info *error_info)
{
	ft_printf("Error\n%s\n", get_error_message(error_code));
	print_additional_info(error_info);
}

void	handle_error(t_error error_code)
{
	handle_error_with_info(error_code, NULL);
}
