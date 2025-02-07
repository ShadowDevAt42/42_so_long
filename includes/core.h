/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:59 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 10:38:07 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

// core/handle_event.c
void	setup_hooks(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
int		handle_expose(t_game *game);
void	handle_player_movement(t_game *game, int keycode);

// core/utils_init.c
t_error	load_sprite(t_game *game, t_img *img, char *sprite_path);
char	*build_anim_sprite_path(const char *base_path,
			int frame_num, const char *suffix);
void	free_sprite(t_game *game, t_img *sprite);
void	free_sprite_frames(t_game *game, t_img *sprites, int count);

// core/utils_render.c
void	render_sprite(t_game *game, t_img *sprite, int x, int y);
void	render_text(t_game *game, t_text text);

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

// core/render/render.c
void	render_game(t_game *game);
int		render_next_frame(void *param);

// core/render/render_ui.c
void	render_ui(t_game *game);
void	render_collectibles_ui(t_game *game);

// core/render/render_static_elements.c
void	render_background(t_game *game);
void	render_player(t_game *game);
void	render_walls(t_game *game);
void	render_corner(t_game *game);

// core/render/render_anim_elements.c
void	render_collectibles(t_game *game);
void	render_exit(t_game *game);

// core/gameplay/player.c
int		move_player(t_game *game, int dx, int dy);

// core/gameplay/victory.c
void	check_collectible(t_game *game, int x, int y);
void	check_exit(t_game *game, int x, int y);

// core/anim/update_anim.c
void		update_portal_anim(t_game *game);
void		start_portal_anim(t_game *game);
void		update_coin_anim(t_game *game);

#endif
