/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:45:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 02:16:02 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Retourne le message d'erreur correspondant à un code d'erreur.
 *
 * Cette fonction reçoit en paramètre un code d'erreur de type t_error et
 * retourne une chaîne de caractères décrivant précisément l'erreur
 * rencontrée lors de la gestion de la carte du jeu. Elle traite plusieurs
 * cas, chacun correspondant à une erreur spécifique liée
 * à la validation du contenu et des dimensions de la carte :
 *
 * - ERR_NO_PLAYER : Aucune position de joueur (P) détectée dans la carte.
 * - ERR_MULTI_PLAYER : Plusieurs positions de joueur (P) ont été trouvées,
 * alors qu'il ne doit y en avoir qu'une seule.
 * - ERR_NO_EXIT : Aucune sortie (E) n'est présente, or la carte doit contenir
 * exactement une sortie.
 * - ERR_MULTI_EXIT : Plus d'une sortie (E) est présente dans la carte,
 * ce qui est invalide.
 * - ERR_NO_COLLECT : Aucun collectible (C) n'est présent, alors qu'au moins
 * un est requis.
 * - ERR_TOO_BIG : Les dimensions de la carte dépassent la taille maximale
 * autorisée.
 * - ERR_PATH : Aucun chemin valide n'existe pour relier le joueur aux
 * collectibles et à la sortie.
 *
 * Si le code d'erreur ne correspond à aucun de ces cas, la fonction
 * retourne un message indiquant
 * qu'une erreur inconnue est survenue.
 *
 * @param error_code Un code d'erreur de type t_error indiquant le
 * type d'erreur rencontré.
 * @return const char* La chaîne de caractères contenant le message
 * d'erreur approprié.
 */
static char	*get_error_message2(t_error error_code)
{
	if (error_code == ERR_NO_PLAYER)
		return ("Map must contain exactly one player position (P)");
	if (error_code == ERR_MULTI_PLAYER)
		return ("Map contains multiple player positions (P)");
	if (error_code == ERR_NO_EXIT)
		return ("Map must contain exactly one exit (E)");
	if (error_code == ERR_MULTI_EXIT)
		return ("Map contains multiple exits (E)");
	if (error_code == ERR_NO_COLLECT)
		return ("Map must contain at least one collectible (C)");
	if (error_code == ERR_TOO_BIG)
		return ("Map dimensions exceed maximum allowed size");
	if (error_code == ERR_PATH)
		return ("No valid path exists between player, collectibles and exit");
	return ("Unknown error occurred");
}

/**
 * @brief Renvoie le message d'erreur associé au code d'erreur fourni.
 *
 * Cette fonction analyse la valeur de l'énumération t_error passée
 * en paramètre et renvoie
 * une chaîne de caractères statique décrivant l'erreur correspondante. 
 * Chaque valeur de t_error
 * (par exemple, ERR_ARGS, ERR_EXTENSION, ERR_OPEN, etc.) est associée à 
 * un message explicatif
 * précis. Si le code d'erreur ne correspond à aucune des valeurs gérées dans
 * cette fonction, celle-ci
 * délègue la gestion à la fonction get_error_message2 qui prend en charge
 * les autres cas d'erreur.
 *
 * @param error_code Le code d'erreur dont on souhaite obtenir
 * le message explicatif.
 * @return char* Une chaîne de caractères décrivant l'erreur
 * pour le code spécifié.
 */
char	*get_error_message(t_error error_code)
{
	if (error_code == ERR_NONE)
		return ("No error");
	if (error_code == ERR_ARGS)
		return ("Usage: ./so_long <map.ber>");
	if (error_code == ERR_EXTENSION)
		return ("Map file must have .ber extension");
	if (error_code == ERR_OPEN)
		return ("Failed to open or read map file");
	if (error_code == ERR_EMPTY)
		return ("Map file is empty");
	if (error_code == ERR_MALLOC)
		return ("Memory allocation failed");
	if (error_code == ERR_INVALID_CHAR)
		return ("Map contains invalid characters (only 0,1,C,E,P allowed)");
	if (error_code == ERR_NOT_RECT)
		return ("Map must be rectangular");
	if (error_code == ERR_NO_WALLS)
		return ("Map must be surrounded by walls");
	return (get_error_message2(error_code));
}

/**
 * @brief Affiche un message d'erreur correspondant au code d'erreur fourni.
 *
 * Cette fonction prend un code d'erreur de type t_error et récupère le message 
 * d'erreur associé à l'aide de la fonction get_error_message.
 * Elle affiche ensuite 
 * le message formaté, précédé du mot "Error", sur la sortie standard. Cette 
 * documentation fournit des informations détaillées qui apparaîtront au survol 
 * de la fonction dans les environnements de développement
 * supportant les docstrings.
 *
 * @param error_code Le code d'erreur qui a déclenché l'affichage du message.
 */
void	handle_error(t_error error_code)
{
	ft_printf("Error\n%s\n", get_error_message(error_code));
}
