/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:14:40 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 05:08:11 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H

/**
 * @enum t_error
 * @brief Enumération des différents codes d'erreur utilisés dans le programme.
 *
 * Cette énumération définit l'ensemble des erreurs possibles qui peuvent survenir lors de l'exécution du programme.
 * Chacun de ces codes représente une situation particulière à gérer, de la validation des arguments fournis à la vérification de la
 * structure et de la validité de la carte de jeu.
 *
 * @var ERR_NONE
 * Aucun erreur détectée.
 *
 * @var ERR_ARGS
 * Nombre d'arguments incorrect.
 *
 * @var ERR_EXTENSION
 * Erreur relative à l'extension d'un fichier.
 *
 * @var ERR_OPEN
 * Erreur d'ouverture de fichier.
 *
 * @var ERR_EMPTY
 * Fichier vide.
 *
 * @var ERR_MALLOC
 * Échec de l'allocation mémoire.
 *
 * @var ERR_INVALID_CHAR
 * Présence de caractères non valides dans la donnée.
 *
 * @var ERR_NOT_RECT
 * La structure (par exemple la carte) n'est pas rectangulaire.
 *
 * @var ERR_NO_WALLS
 * Absence de murs, la carte ne présente pas les limites requis.
 *
 * @var ERR_NO_PLAYER
 * Aucun joueur n'est défini dans la carte.
 *
 * @var ERR_MULTI_PLAYER
 * Plusieurs joueurs détectés alors qu'un seul est requis.
 *
 * @var ERR_NO_EXIT
 * Absence de sortie dans le niveau.
 *
 * @var ERR_MULTI_EXIT
 * Plusieurs sorties détectées alors qu'une seule est attendue.
 *
 * @var ERR_NO_COLLECT
 * Aucune collectible (objet à récupérer) présent dans la carte.
 *
 * @var ERR_TOO_BIG
 * La carte dépasse la taille maximale autorisée.
 *
 * @var ERR_PATH
 * Erreur relative à l'inaccessibilité d'un chemin ou d'une route nécessaire dans la carte.
 */
typedef enum e_error
{
	ERR_NONE,
	ERR_ARGS,
	ERR_EXTENSION,
	ERR_OPEN,
	ERR_EMPTY,
	ERR_MALLOC,
	ERR_INVALID_CHAR,
	ERR_NOT_RECT,
	ERR_NO_WALLS,
	ERR_NO_PLAYER,
	ERR_MULTI_PLAYER,
	ERR_NO_EXIT,
	ERR_MULTI_EXIT,
	ERR_NO_COLLECT,
	ERR_TOO_BIG,
	ERR_PATH,
	ERR_MLX_INIT,        // Erreur d'initialisation de MLX
    ERR_WIN_INIT,        // Erreur de création de fenêtre
    ERR_SPRITE_LOAD,     // Erreur de chargement de sprite
    ERR_IMG_CREATE,      // Erreur de création d'image
    ERR_SPRITE_PATH      // Erreur de chemin de sprite
}	t_error;

typedef struct s_error_info
{
    char    *sprite_path;
    char    *additional_info;
}   t_error_info;

/**
 * @brief Structure représentant la carte du jeu.
 * 
 * La structure t_map contient toutes les informations nécessaires pour définir l'état 
 * d'une carte dans le jeu "so_long". Elle englobe la grille de jeu, ses dimensions, 
 * ainsi que les compteurs pour les objets interactifs tels que les collectibles, la sortie 
 * et le joueur. Chaque champ de la structure est utilisé pour gérer et rendre compte d'un 
 * aspect essentiel du fonctionnement de la carte.
 *
 * @param grid         Pointeur vers un tableau de chaînes de caractères, représentant la grille 
 *                     de la carte. Chaque chaîne correspond à une ligne de la carte.
 * @param width        Nombre de colonnes de la grille (largeur de la carte).
 * @param height       Nombre de lignes de la grille (hauteur de la carte).
 * @param collectibles Nombre de collectibles placés sur la carte.
 * @param exit         Nombre de sorties disponibles sur la carte (indice valide de la position de la sortie).
 * @param player       Indicateur de la présence du joueur sur la carte, normalement utilisé pour vérifier
 *                     qu'il y a exactement un point de départ pour le joueur.
 * @param player_x     Coordonnée X du joueur dans la grille, permettant de situer sa position horizontale.
 * @param player_y     Coordonnée Y du joueur dans la grille, permettant de situer sa position verticale.
 */
typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_img {
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}   t_img;

typedef struct s_game {
    void    *mlx;
    void    *win;
    t_img   wall;
	t_img   player;
	t_img   collectible;
    t_img   exit;
	t_img   exit_open;
    t_map   *map;
	int     moves;
	int     collected;
	int     on_exit;
}   t_game;

#endif