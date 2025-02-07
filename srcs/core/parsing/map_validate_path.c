/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:13:22 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 02:31:02 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Vérifie si tous les éléments essentiels de la carte sont accessibles.
 *
 * La fonction parcourt la grille représentée dans la structure
 * de carte et vérifie :
 * - Que tous les collectibles ('C') présents dans la carte ont
 * été visités (selon la matrice "visited").
 * - Qu'une sortie ('E') a été visitée.
 *
 * @param map Pointeur vers la structure de la carte contenant les
 *            informations telles que la grille, la hauteur,
 *            la largeur et le nombre de collectibles requis.
 * @param visited Matrice de suivi indiquant les positions visitées de la carte.
 * @return int Renvoie 1 si le nombre de collectibles trouvés dans les
 *         cases visitées est égal au nombre requis et si la
 *         sortie a été visitée, sinon renvoie 0.
 *
 * La fonction utilise deux compteurs locaux : "collect_found"
 * pour compter les collectibles trouvés,
 * et "exit_found" pour signaler la présence d'une sortie visitée.
 * Elle itère sur chaque cellule de la grille en vérifiant la
 * condition d'appartenance de la cellule à un collectible ou à une sortie,
 * puis ajuste les compteurs en fonction du résultat et des
 * informations de la matrice "visited".
 */
int	check_reachable_elements(t_map *map, char **visited)
{
	int	i;
	int	j;
	int	collect_found;
	int	exit_found;

	collect_found = 0;
	exit_found = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->grid[i][j] == 'C' && visited[i][j])
				collect_found++;
			else if (map->grid[i][j] == 'E' && visited[i][j])
				exit_found = 1;
		}
	}
	return (collect_found == map->collectibles && exit_found);
}

/**
 * @brief Alloue et initialise une matrice de visite pour la carte.
 *
 * Cette fonction crée un tableau 2D de caractères en allouant dynamiquement une
 * première dimension correspondant à la hauteur de la carte,
 * puis en allouant pour
 * chaque ligne un tableau de 'map->width' caractères
 * initialisés à zéro grâce à ft_calloc.
 * Si l'allocation d'une ligne échoue, la fonction libère
 * toutes les allocations précédentes
 * pour éviter toute fuite de mémoire.
 *
 * @param map Pointeur vers une structure t_map contenant
 *             au minimum les attributs
 *            'height' (nombre de lignes) et 'width'
 *             (nombre de colonnes) de la carte.
 *
 * @return char** Retourne un pointeur vers le tableau alloué en cas de succès,
 *         ou NULL si une erreur d'allocation survient.
 */
static char	**allocate_visited(t_map *map)
{
	int		i;
	char	**visited;

	visited = malloc(sizeof(char *) * map->height);
	if (!visited)
		return (NULL);
	i = -1;
	while (++i < map->height)
	{
		visited[i] = ft_calloc(map->width, sizeof(char));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
	}
	return (visited);
}

/**
 * @brief Libère la mémoire allouée pour le tableau 'visited'.
 *
 * Cette fonction libère dynamiquement un tableau à deux
 * dimensions de chaînes de caractères.
 * Pour chaque ligne dans le tableau, la mémoire allouée est
 * libérée, puis le tableau principal
 * de pointeurs est également libéré. Ceci permet d'éviter
 * les fuites de mémoire après utilisation.
 *
 * @param visited Pointeur vers un tableau de chaînes de caractères à libérer.
 * @param height Nombre de chaînes (lignes) contenues dans le tableau 'visited'.
 */
static void	free_visited(char **visited, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(visited[i]);
	free(visited);
}

/**
 * @brief Vérifie la validité du chemin dans la carte.
 *
 * Cette fonction détermine si toutes les zones
 * essentielles de la carte, telles que
 * les éléments à récupérer et la sortie, sont
 * accessibles depuis la position du joueur.
 * Elle utilise une approche de flood fill pour
 * marquer les positions atteignables et ensuite
 * vérifie si tous les éléments requis sont atteints.
 *
 * @param map Pointeur vers la structure t_map contenant
 *            les informations de la carte,
 *            y compris la position du joueur
 *            (player_x, player_y) et les dimensions.
 *
 * @return Un entier indiquant si le chemin est valide
 * (généralement 1 pour vrai et 0 pour faux).
 *         Retourne 0 en cas d'échec d'allocation de mémoire.
 */
int	validate_path(t_map *map)
{
	char	**visited;
	int		valid;

	visited = allocate_visited(map);
	if (!visited)
		return (0);
	flood_fill(map, visited, map->player_x, map->player_y);
	valid = check_reachable_elements(map, visited);
	free_visited(visited, map->height);
	return (valid);
}
