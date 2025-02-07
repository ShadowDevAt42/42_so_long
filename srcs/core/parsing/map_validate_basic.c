/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_basic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:06:56 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 02:23:35 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Vérifie si la carte est rectangulaire.
 *
 * La fonction s'assure que :
 * - La structure t_map et ses attributs (grid, height)
 * sont correctement initialisés.
 * - Chaque ligne de la grille est non nulle.
 * - Si le dernier caractère d'une ligne est '\n', il est ignoré dans
 * le calcul de la longueur.
 * - La largeur (width) de la carte est déterminée à partir de la première
 * ligne et chaque ligne subséquente doit avoir la même longueur.
 *
 * @param map Pointeur vers une structure t_map contenant la grille représentant
 *            la carte, ainsi que 
 *            les attributs @c height (nombre total de lignes) et @c
 *            width (initialisé par cette fonction).
 *
 * @return int 1 si la carte est rectangulaire et correctement formatée, 0 sinon.
 */
int	check_rectangle(t_map *map)
{
	int	i;
	int	len;

	if (!map || !map->grid || map->height <= 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		if (!map->grid[i])
			return (0);
		len = ft_strlen(map->grid[i]);
		if (map->grid[i][len - 1] == '\n')
			len--;
		if (i == 0)
			map->width = len;
		else if (len != map->width)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Vérifie que le contour de la carte est constitué uniquement de murs.
 *
 * Cette fonction parcourt l'ensemble de la grille de la
 * carte et s'assure que les cases
 * situées sur les bords (première et dernière ligne ainsi
 * que première et dernière colonne)
 * contiennent le caractère '1', qui représente un mur.
 *
 * @param map Pointeur vers une structure t_map contenant
 * la grille (grid) et ses dimensions (width et height).
 *
 * @return int Renvoie 1 si toutes les cases du contour
 * sont des murs, ou 0 si au moins une case n'est pas un mur.
 */
int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if ((i == 0 || i == map->height - 1
					|| j == 0 || j == map->width - 1))
			{
				if (map->grid[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * @brief Vérifie que l'extension du nom de fichier est ".ber".
 *
 * Cette fonction s'assure que le nom de fichier fourni se
 * termine par l'extension ".ber".
 * Elle commence par vérifier que le pointeur vers le nom de
 * fichier n'est pas NULL et que
 * la longueur du nom est suffisante pour contenir l'extension
 * attendue. Ensuite, elle
 * compare les quatre derniers caractères du nom de fichier avec ".ber".
 *
 * @param filename Pointeur vers la chaîne de caractères représentant
 * le nom du fichier.
 * @return int Retourne 1 si l'extension correspond à ".ber", sinon retourne 0.
 */
int	validate_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

/**
 * @brief Valide les dimensions de la carte.
 *
 * Cette fonction vérifie si les dimensions de la carte sont
 * valides en s'assurant que :
 * - Le pointeur vers la carte n'est pas NULL.
 * - La largeur et la hauteur de la carte sont strictement supérieures à 2.
 * - La taille totale de la carte (largeur ou hauteur multipliée par SPRITE_SIZE)
 *   ne dépasse pas les limites maximales définies par MAX_WIDTH et MAX_HEIGHT.
 *
 * @param map Pointeur vers une structure t_map représentant la carte à valider.
 *
 * @return int Retourne 1 si toutes les conditions de validation
 * sont satisfaites, sinon retourne 0.
 */
int	validate_dimensions(t_map *map)
{
	if (!map)
		return (0);
	if (map->width <= 2 || map->height <= 2)
		return (0);
	if (map->width * SPRITE_SIZE > MAX_WIDTH)
		return (0);
	if (map->height * SPRITE_SIZE > MAX_HEIGHT)
		return (0);
	return (1);
}
