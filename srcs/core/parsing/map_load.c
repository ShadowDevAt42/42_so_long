/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:08:34 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 02:35:22 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Alloue et initialise une structure t_map avec
 * une grille de hauteur précisée.
 *
 * Cette fonction commence par initialiser une nouvelle
 * structure t_map via la fonction
 * init_map(). Une fois la structure obtenue, elle définit
 * la hauteur de la grille et
 * alloue la mémoire nécessaire pour le tableau de pointeurs
 * de type char (chaque pointeur
 * représentant une ligne de la grille). Si l'allocation
 * pour la grille échoue, la mémoire
 * allouée pour la structure est libérée et la fonction retourne NULL.
 *
 * @param height La hauteur (nombre de lignes) souhaitée
 *        pour la grille de la map.
 * @return Un pointeur vers la structure t_map correctement
 *         initialisée et contenant la grille,
 *         ou NULL en cas d'échec de l'allocation de la mémoire.
 */
static t_map	*allocate_map_grid(int height)
{
	t_map	*map;

	map = init_map();
	if (!map)
		return (NULL);
	map->height = height;
	map->grid = malloc(sizeof(char *) * height);
	if (!map->grid)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

/**
 * @brief Analyse et charge les lignes d'une carte
 * depuis un descripteur de fichier.
 *
 * Cette fonction lit successivement chaque ligne d'
 * une carte à partir du descripteur
 * de fichier fourni. Pour chaque ligne, elle appelle
 * la fonction sur "read_map_line" pour
 * charger et valider la ligne correspondante dans la
 * structure de la carte. Si la lecture d'une 
 * ligne échoue, la fonction libère la mémoire allouée
 * pour la carte et ferme le descripteur, 
 * retournant ainsi NULL pour signaler une erreur.
 *
 * @param fd Le descripteur de fichier ouvert pointant
 *           vers le fichier de la carte.
 * @param map Un pointeur vers la structure contenant
 *            les informations de la carte.
 * @param height Le nombre total de lignes à lire pour constituer la carte.
 * @return t_map* Un pointeur vers la structure de
 *                carte mise à jour en cas de succès, 
 *                ou NULL si une erreur survient durant la lecture.
 */
static t_map	*parse_map_lines(int fd, t_map *map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (!read_map_line(fd, map, i))
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
		i++;
	}
	return (map);
}

/**
 * @brief Charge une carte à partir d'un fichier.
 *
 * Cette fonction lit un fichier contenant la représentation
 * d'une carte pour le jeu,
 * et retourne une structure t_map préalablement allouée et
 * remplie par la lecture des lignes.
 *
 * Le processus se déroule en plusieurs étapes :
 *  - Comptage du nombre de lignes de la carte dans le fichier via
 *    la fonction count_map_lines.
 *    * Si le nombre de lignes est égal à 0, la fonction retourne (t_map *)-1.
 *    * Si le nombre de lignes est égal à -1, la fonction retourne (t_map *)-2.
 *    * Si le nombre de lignes est négatif (autre cas), la fonction
 *      retourne NULL.
 *
 *  - Allocation de la structure t_map via la fonction allocate_map_grid.
 *    * En cas d'échec de l'allocation, la fonction retourne NULL.
 *
 *  - Ouverture du fichier en lecture avec open.
 *    * Si l'ouverture échoue (fd < 0), la mémoire allouée est
 * libérée via free_map et la fonction retourne NULL.
 *
 *  - Lecture et parsing des lignes du fichier pour remplir la
 * structure t_map en appelant parse_map_lines.
 *
 *  - Fermeture du descripteur de fichier avec close.
 *
 * @param filename Le chemin vers le fichier contenant la carte à charger.
 *
 * @return t_map* Un pointeur sur la structure t_map contenant la carte chargée,
 *                ou un code d'erreur spécifique ((t_map *)-1 ou (t_map *)-2)
 *                en fonction des erreurs de comptage,
 *                ou NULL en cas d'erreur d'allocation ou d'ouverture du fichier.
 */
t_map	*load_map(char *filename)
{
	t_map	*map;
	int		fd;
	int		height;

	height = count_map_lines(filename);
	if (height == 0)
		return ((t_map *)-1);
	if (height == -1)
		return ((t_map *)-2);
	if (height < 0)
		return (NULL);
	map = allocate_map_grid(height);
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		return (NULL);
	}
	map = parse_map_lines(fd, map, height);
	close(fd);
	return (map);
}
