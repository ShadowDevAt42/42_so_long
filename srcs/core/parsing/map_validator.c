/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 00:08:51 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 02:32:54 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Valide le contenu de la carte du jeu.
 *
 * Cette fonction effectue une série de vérifications sur la structure
 * de la carte.
 * Elle s'assure que la carte est rectangulaire (@c check_rectangle),
 * que les murs encadrent bien la carte (@c check_walls),
 * que les éléments essentiels (joueur, sortie, collectibles)
 * sont bien présents et dans un état correct (@c validate_elements),
 * que les dimensions de la carte ne dépassent pas les
 * limites autorisées (@c validate_dimensions),
 * et enfin que le chemin entre les différents
 * éléments est valide (@c validate_path).
 *
 * Les erreurs spécifiques renvoyées sont les suivantes :
 * - @c ERR_NOT_RECT : La carte n'est pas rectangulaire.
 * - @c ERR_NO_WALLS : Les murs de la carte sont manquants ou mal placés.
 * - @c ERR_NO_PLAYER : Aucun joueur n'a été trouvé.
 * - @c ERR_MULTI_PLAYER : Plusieurs joueurs ont été trouvés.
 * - @c ERR_NO_EXIT : Aucune sortie n'a été trouvée.
 * - @c ERR_MULTI_EXIT : Plusieurs sorties ont été trouvées.
 * - @c ERR_NO_COLLECT : Aucun collectible n'a été trouvé.
 * - @c ERR_TOO_BIG : La carte dépasse les dimensions autorisées.
 * - @c ERR_PATH : Le chemin requis pour la validation n'est pas valide.
 *
 * @param map Pointeur vers la structure de la carte à valider.
 *
 * @return t_error Code d'erreur indiquant l'état de la validation:
 *         - @c ERR_NONE si la carte est valide,
 *         - Un autre code d'erreur sinon.
 */
static t_error	validate_map_content(t_map *map)
{
	if (!check_rectangle(map))
		return (ERR_NOT_RECT);
	if (!check_walls(map))
		return (ERR_NO_WALLS);
	if (!validate_elements(map))
	{
		if (map->player == 0)
			return (ERR_NO_PLAYER);
		if (map->player > 1)
			return (ERR_MULTI_PLAYER);
		if (map->exit == 0)
			return (ERR_NO_EXIT);
		if (map->exit > 1)
			return (ERR_MULTI_EXIT);
		if (map->collectibles == 0)
			return (ERR_NO_COLLECT);
	}
	if (!validate_dimensions(map))
		return (ERR_TOO_BIG);
	if (!validate_path(map))
		return (ERR_PATH);
	return (ERR_NONE);
}

/**
 * @brief Valide et charge la carte à partir d'un fichier.
 *
 * Cette fonction vérifie d'abord la validité du chemin de fichier de la carte,
 * notamment son extension grâce à la fonction validate_extension.
 * Elle tente ensuite
 * de charger la carte en utilisant load_map() et 
 * effectue plusieurs vérifications :
 * - Si le chemin est NULL, elle retourne ERR_ARGS.
 * - Si l'extension du fichier est incorrecte, elle retourne ERR_EXTENSION.
 * - Si load_map() retourne (t_map *)-1, cela signifie
 * que la carte est vide, d'où ERR_EMPTY.
 * - Si load_map() retourne (t_map *)-2, cela indique la
 * présence d'un caractère invalide et
 *   la fonction retourne ERR_INVALID_CHAR.
 * - Si la carte ne peut être ouverte, la fonction retourne ERR_OPEN.
 *
 * @param map_path Chemin du fichier contenant la définition de la carte.
 * @param map Adresse d'un pointeur vers une structure t_map
 *            dans laquelle sera stockée la carte.
 *
 * @return t_error Code d'erreur correspondant au résultat 
 *         de la validation et du chargement.
 *         - ERR_NONE indique que la carte a été chargée et validée avec succès.
 */
t_error	validate_map_file(char *map_path, t_map **map)
{
	if (!map_path)
		return (ERR_ARGS);
	if (!validate_extension(map_path))
		return (ERR_EXTENSION);
	*map = load_map(map_path);
	if (*map == (t_map *)-1)
		return (ERR_EMPTY);
	if (*map == (t_map *)-2)
		return (ERR_INVALID_CHAR);
	if (!*map)
		return (ERR_OPEN);
	return (ERR_NONE);
}

/**
 * @brief Valide l'ensemble des données de la carte.
 *
 * Cette fonction réalise une double vérification pour
 * s'assurer de la validité de la carte.
 * Dans un premier temps, elle vérifie le fichier de la
 * carte à partir du chemin fourni (@p map_path),
 * puis elle analyse le contenu de la carte (remplie dans @p map).
 * Si une erreur est détectée lors de la validation
 * du contenu, la mémoire associée à la carte est libérée,
 * et le pointeur est mis à NULL pour éviter des accès invalides.
 *
 * @param map_path Chemin d'accès au fichier de la carte.
 * @param map Pointeur vers le pointeur de la structure
 *            de la carte à initialiser et valider.
 *
 * @return t_error Code d'erreur résultant de la validation :
 *         - ERR_NONE en cas de succès complet.
 *         - Une autre valeur d'erreur si une vérification échoue.
 *
 * @note En cas d'échec lors de la validation du contenu de la
 *       carte, la fonction libère la mémoire allouée
 *       pour la carte et met @p map à NULL afin d'éviter toute
 *       fuite de mémoire et un usage ultérieur incorrect.
 */
t_error	validate_all(char *map_path, t_map **map)
{
	t_error	error;

	error = validate_map_file(map_path, map);
	if (error != ERR_NONE)
		return (error);
	error = validate_map_content(*map);
	if (error != ERR_NONE)
	{
		free_map(*map);
		*map = NULL;
		return (error);
	}
	return (ERR_NONE);
}
