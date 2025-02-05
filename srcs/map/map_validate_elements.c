/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_elements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:07:29 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 02:26:44 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Compte le nombre d'occurrences d'un élément donné dans une grille.
 *
 * Cette fonction parcourt une grille de caractères de
 * dimensions spécifiées par height et width,
 * et incrémente un compteur chaque fois que l'élément spécifié est rencontré.
 *
 * @param grid   La grille de caractères à parcourir.
 * @param height Le nombre de lignes dans la grille.
 * @param width  Le nombre de colonnes dans la grille.
 * @param element Le caractère à rechercher dans la grille.
 *
 * @return Le nombre d'occurrences de l'élément dans la grille.
 */
static int	count_element(char **grid, int height, int width, char element)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (grid[i][j] == element)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/**
 * @brief Compte et met à jour les éléments spécifiques de la carte.
 *
 * Cette fonction analyse la grille de la carte contenue dans la structure t_map
 * pour déterminer le nombre d'éléments collectables
 * ('C'), de sorties ('E') et de joueurs ('P').
 * Chaque appel à la fonction count_element parcourt
 * la grille en utilisant les dimensions
 * spécifiées (height et width) et retourne le nombre
 * d'occurrences de l'élément fourni.
 * Les résultats sont ensuite stockés dans les champs
 * correspondants de la structure t_map.
 *
 * @param map Pointeur vers la structure t_map qui contient
 * la grille de la carte et ses dimensions.
 */
static void	count_map_elements(t_map *map)
{
	map->collectibles = count_element(map->grid, map->height, map->width, 'C');
	map->exit = count_element(map->grid, map->height, map->width, 'E');
	map->player = count_element(map->grid, map->height, map->width, 'P');
}

/**
 * @brief Valide les éléments essentiels d'une carte.
 *
 * Cette fonction vérifie que la structure de la carte et sa
 * grille sont correctement initialisées.
 * Elle compte ensuite les différents éléments présents dans
 * la carte (collectibles, sortie, joueur)
 * en appelant la fonction count_map_elements(). La validité
 * de la carte est déterminée selon les critères suivants :
 * - Au moins un collectible présent.
 * - Une unique sortie présente.
 * - Un unique joueur présent.
 *
 * Si ces conditions ne sont pas remplies, la fonction renvoie
 * 0 pour indiquer une carte invalide.
 * Elle met également à jour la position du joueur en appelant
 * find_player_pos() si la carte est valide.
 *
 * @param map Pointeur vers la structure t_map représentant la carte à valider.
 *
 * @return int Retourne 1 si la carte est valide, sinon 0.
 */
int	validate_elements(t_map *map)
{
	if (!map || !map->grid)
		return (0);
	count_map_elements(map);
	if (map->collectibles < 1 || map->exit != 1 || map->player != 1)
		return (0);
	find_player_pos(map);
	return (1);
}

/**
 * @brief Recherche et enregistre la position du joueur dans la grille.
 *
 * Cette fonction parcourt la grille de la map ligne par ligne afin de localiser
 * la première occurrence du caractère 'P', qui représente la position du joueur.
 * Lorsque le caractère est trouvé, les coordonnées du joueur
 * (player_x et player_y)
 * sont mises à jour dans la structure t_map et la fonction se
 * termine immédiatement.
 *
 * @param map Pointeur vers la structure t_map contenant la grille, ainsi que les
 *            dimensions de la grille (width et height). La grille
 *            est une matrice
 *            de caractères où chaque cellule peut représenter un élément du jeu.
 */
void	find_player_pos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

/**
 * @brief Remplit récursivement une zone dans la carte
 *        à partir d'un point initial.
 *
 * Cette fonction implémente l'algorithme de "flood fill" afin de marquer
 * toutes les positions accessibles à partir de la position (x, y) sur la carte.
 * Le remplissage s'effectue uniquement sur les cellules qui ne sont ni des murs
 * (indiqués par '1') ni déjà visitées, en évitant ainsi les débordements hors du
 * tableau et en traitant les conditions limites.
 *
 * @param map Pointer vers la structure de la carte, qui contient notamment
 *            la grille (map->grid) et ses dimensions 
 *            (map->width et map->height).
 * @param visited Matrice indiquant pour chaque cellule si
 *                elle a déjà été visitée.
 *                Cette matrice est utilisée pour éviter les
 *                boucles infinies lors
 *                de l'exécution récursive.
 * @param x Coordonnée horizontale (colonne) du point de départ.
 * @param y Coordonnée verticale (ligne) du point de départ.
 *
 * L'algorithme vérifie d'abord que les coordonnées (x, y)
 * sont bien dans les limites
 * de la carte. Il s'assure également que la cellule n'est
 * ni un mur ni déjà visitée.
 * Si la cellule est valide, elle est marquée comme visitée,
 * puis la fonction s'appelle
 * récursivement sur les cellules adjacentes dans les
 * quatre directions (droite, gauche,
 * bas, haut).
 */
void	flood_fill(t_map *map, char **visited, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (visited[y][x] || map->grid[y][x] == '1')
		return ;
	visited[y][x] = 1;
	flood_fill(map, visited, x + 1, y);
	flood_fill(map, visited, x - 1, y);
	flood_fill(map, visited, x, y + 1);
	flood_fill(map, visited, x, y - 1);
}
