#include "../../includes/so_long.h"

#define MOVE_SPEED 0.5f

static int	setup_game_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L<<0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, handle_destroy, game);
	mlx_hook(game->win, 12, 1L<<15, redraw, game);
	return (1);
}

int launch_game(t_game *game)
{
    find_player_position(game);
    if (!validate_player_position(game))
    {
        write(2, "Error\nInvalid player position\n", 29);
        return (0);
    }
    game->player_screen_x = game->player_x * game->img_width;
    game->player_screen_y = game->player_y * game->img_height;
	game->collectibles.anim_timer = 0;  // Initialisation du timer
    
    setup_game_hooks(game);
    mlx_loop_hook(game->mlx, game_update, game);
    draw_map(game);
    mlx_loop(game->mlx);
    return (1);
}

static int update_player_position(t_game *game)
{
    float target_screen_x;
    float target_screen_y;
    int movement_completed;

    if (!game->is_moving)
        return (0);

    // Calculer les positions cibles en pixels
    target_screen_x = game->target_x * game->img_width;
    target_screen_y = game->target_y * game->img_height;

    // Mettre à jour la position du joueur
    game->player_screen_x += game->move_direction_x * MOVE_SPEED;
    game->player_screen_y += game->move_direction_y * MOVE_SPEED;

    movement_completed = 0;

    // Vérifier si on a atteint ou dépassé la cible
    if (game->move_direction_x > 0 && game->player_screen_x >= target_screen_x)
        movement_completed = 1;
    else if (game->move_direction_x < 0 && game->player_screen_x <= target_screen_x)
        movement_completed = 1;
    else if (game->move_direction_y > 0 && game->player_screen_y >= target_screen_y)
        movement_completed = 1;
    else if (game->move_direction_y < 0 && game->player_screen_y <= target_screen_y)
        movement_completed = 1;

    if (movement_completed)
    {
        // Alignement final sur la grille
        game->player_screen_x = target_screen_x;
        game->player_screen_y = target_screen_y;
        game->player_x = game->target_x;
        game->player_y = game->target_y;
        
        // Vérifier si on peut continuer dans la même direction
        if (game->map[game->player_y + game->move_direction_y]
            [game->player_x + game->move_direction_x] != '1')
        {
            game->target_x += game->move_direction_x;
            game->target_y += game->move_direction_y;
        }
        else
            game->is_moving = 0;
    }

    return (1);
}

int	game_update(t_game *game)
{
	update_collectible_animation(game);
	
	if (update_player_position(game))
	{
		check_collectible(game);
	}
	
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	
	return (0);
}