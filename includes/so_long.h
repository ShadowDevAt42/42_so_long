#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <../libft/includes/libft.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_wall_sprites
{
    void    *top;
    void    *bottom;
    void    *left;
    void    *right;
    void    *corner_tl;
    void    *corner_tr;
    void    *corner_bl;
    void    *corner_br;
    void    *block;
}   t_wall_sprites;

typedef struct s_game
{
    void            *mlx;
    void            *win;
    char            **map;
    t_wall_sprites  walls;
    void            *player_img;
    int             width;
    int             height;
    int             img_width;
    int             img_height;
    int             player_x;
    int             player_y;
    float           player_screen_x;  // Position réelle à l'écran
    float           player_screen_y;  // Position réelle à l'écran
    int             target_x;        // Position cible
    int             target_y;        // Position cible
    int             is_moving;       // Flag pour indiquer si en mouvement
    int             move_direction_x; // Direction actuelle
    int             move_direction_y; // Direction actuelle
    int             moves;
}   t_game;

/* srcs/utils/memory_utils.c */
void    *ft_calloc(size_t count, size_t size);
void    free_ptr(void **ptr);
void    free_map(t_game *game);

/* srcs/core/game_init.c */
int     init_game(t_game *game);
int     init_sprites(t_game *game);

/* srcs/core/game_loop.c */
int     launch_game(t_game *game);
int     game_update(t_game *game);  // Ajout du prototype


/* srcs/core/game_cleanup.c */
void    clean_game(t_game *game);
int     handle_close(t_game *game);

/* srcs/map/map_reader.c */
int     read_map(t_game *game, char *filename);

/* srcs/map/map_utils.c */
int     check_map_dimensions(t_game *game);

/* srcs/player/player_init.c */
void    find_player_position(t_game *game);
int     validate_player_position(t_game *game);

/* srcs/player/player_movement.c */
int     handle_movement(t_game *game, int keysym);

/* srcs/window/window_init.c */
int     init_window_dimensions(t_game *game);
void    draw_map(t_game *game);

/* srcs/window/window_events.c */
int     handle_keypress(int keysym, t_game *game);
int     handle_destroy(t_game *game);
int     redraw(t_game *game);

#endif