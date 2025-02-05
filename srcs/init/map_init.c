/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:06:26 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 02:16:50 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief init_map - Initialise et alloue une nouvelle structure t_map.
 *
 * Cette fonction alloue dynamiquement une structure t_map pour
 * la gestion de la carte
 * dans le programme. Les champs de la structure sont initialisés
 * aux valeurs par défaut :
 *   - grid est initialisé à NULL, indiquant qu'aucune grille n'est définie.
 *   - width et height sont mis à 0, signalant qu'aucune dimension
 * n'est spécifiée.
 *   - collectibles, exit et player sont initialisés à 0, indiquant
 * l'absence d'objets ou d'entrées.
 *   - player_x et player_y sont positionnés à -1, ce qui signifie qu
 * aucune position de joueur
 *     n'a encore été attribuée.
 *
 * @return Un pointeur vers la structure t_map correctement initialisée,
 * ou NULL en cas d'échec
 *         lors de l'allocation de mémoire.
 *
 */
t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	map->collectibles = 0;
	map->exit = 0;
	map->player = 0;
	map->player_x = -1;
	map->player_y = -1;
	return (map);
}

/**
 * @brief Libère toutes les ressources allouées pour la structure t_map.
 *
 * Cette fonction libère la mémoire associée à une structure t_map, incluant son
 * tableau de chaînes (grid). Elle effectue les opérations suivantes :
 *   - Vérifie que le pointeur map n'est pas NULL.
 *   - Pour chaque ligne de la grille, identifiée par l'attribut height,
 *     libère la mémoire allouée.
 *   - Libère ensuite la mémoire du tableau grid lui-même.
 *   - Enfin, libère la structure map.
 *
 * Cette fonction permet d'éviter les fuites de mémoire en s'assurant que toutes
 * les allocations dynamiques effectuées lors de l'initialisation de la map sont
 * correctement désallouées.
 *
 * @param map Pointeur vers la structure t_map à libérer.
 */
void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->grid)
	{
		i = 0;
		while (i < map->height)
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}
