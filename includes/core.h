/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:59 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 23:28:36 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// core/handle_event.c
void	setup_hooks(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
int		handle_expose(t_game *game);

// core/utils.c
t_error load_sprite(t_game *game, t_img *img, char *sprite_path);
char *build_anim_sprite_path(const char *base_path, int frame_num, const char *suffix);
void	free_sprite(t_game *game, t_img *sprite);
void	free_sprite_frames(t_game *game, t_img *sprites, int count);

// core/init/core.c
t_map	*init_map(void);
t_game	*init_window(t_map *map);
t_error	load_sprites(t_game *game);

//core/free/core.c
void	free_map(t_map *map);
void	free_window(t_game *game);
int		close_window(t_game *game);
void	free_sprites(t_game *game);

// core/init/static_assets.c
t_error	init_wall_and_background(t_game *game);
t_error	init_corner(t_game *game);
t_error	init_player_and_exit(t_game *game);
t_error	init_ui(t_game *game);

// core/init/anim_assets.c
t_error	init_coin_anim(t_game *game);
t_error	init_portal_anim(t_game *game);

// core/init/anim_assets.c
void	free_coin_frames(t_game *game);
void	free_portal_frames(t_game *game);

// core/free/static_assets.c
void	free_walls_and_background(t_game *game);
void	free_corner_elements(t_game *game);
void	free_gameplay_elements(t_game *game);
void	free_ui_elements(t_game *game);

#endif