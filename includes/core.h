/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:32:59 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/08 23:25:21 by fdi-tria         ###   ########.fr       */
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

// core/init/wall_init.c
t_error	init_wall_basic(t_game *game);
t_error	init_wall_internal_h(t_game *game);
t_error	init_wall_internal_v(t_game *game);
t_error	init_wall_internal_m1(t_game *game);
t_error	init_wall_internal_m2(t_game *game);

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
void	update_portal_anim(t_game *game);
void	start_portal_anim(t_game *game);
void	update_coin_anim(t_game *game);

// core/parsing/map_load.c
t_map	*load_map(char *filename);

// core/parsing/map_read.c
int		validate_line_chars(char *line);
int		read_map_line(int fd, t_map *map, int line_num);
int		count_map_lines(char *filename);

// core/parsing/map_validate_basic.c
int		check_rectangle(t_map *map);
int		check_walls(t_map *map);
int		validate_extension(char *filename);
int		validate_dimensions(t_map *map);

// core/parsing/map_validate_elements.c
int		validate_elements(t_map *map);
void	find_player_pos(t_map *map);
void	flood_fill(t_map *map, char **visited, int x, int y);

// core/parsing/map_validate_path.c
int		check_reachable_elements(t_map *map, char **visited);
int		validate_path(t_map *map);

// core/parsing/map_validator.c
t_error	validate_map_file(char *map_path, t_map **map);
t_error	validate_all(char *map_path, t_map **map);

#endif
