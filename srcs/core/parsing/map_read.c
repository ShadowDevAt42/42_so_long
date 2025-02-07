/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 23:08:07 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/05 02:18:52 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/**
 * @brief Vérifie si un caractère est valide dans la configuration de la map.
 *
 * Cette fonction détermine si le caractère passé en
 * paramètre correspond à un des
 * caractères autorisés pour la définition de la carte du jeu :
 *   - '0' : espace vide,
 *   - '1' : mur ou obstacle,
 *   - 'C' : collectible (objet à récupérer),
 *   - 'E' : sortie,
 *   - 'P' : position initiale du joueur,
 *   - '\n': saut de ligne pour la délimitation des lignes de la map.
 *
 * Cette vérification permet de s'assurer que la structure
 * de la carte respecte le format
 * attendu par le programme lors du chargement et du rendu de la map.
 *
 * @param c Le caractère à évaluer.
 * @return Un entier non nul (vrai) si le caractère est
 * valide, zéro (faux) sinon.
 */
static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P'
		|| c == '\n');
}

/**
 * @brief Valide les caractères d'une ligne de texte.
 *
 * Cette fonction examine chaque caractère de la chaîne
 * de caractères passée en
 * paramètre (jusqu'à rencontrer le caractère de nouvelle
 * ligne ou la fin de chaîne)
 * et vérifie si chaque caractère est valide à l'aide de
 * la fonction is_valid_char().
 *
 * Si un caractère non valide est détecté, la fonction s'arrête et retourne 0.
 * En l'absence de caractères invalides, la fonction retourne 1.
 *
 * @param line La chaîne de caractères à valider. Doit être non nulle.
 * @return int 1 si tous les caractères de la ligne sont valides, 0 sinon.
 */
int	validate_line_chars(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_valid_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Lit une ligne du fichier et l'intègre dans la grille de la carte.
 *
 * Cette fonction lit une ligne à partir du descripteur de fichier
 * fourni à l'aide de get_next_line.
 * Elle vérifie si la ligne est bien formée en contrôlant les
 * caractères par validate_line_chars.
 * Si la ligne est valide, elle est dupliquée et intégrée dans la
 * grille de la structure map à l'indice
 * spécifié par line_num. En cas d'erreur lors de la lecture, de la
 * validation ou de l'allocation mémoire,
 * la fonction libère la mémoire allouée et renvoie 0 pour signaler
 * un échec. Sinon, elle renvoie 1 pour
 * indiquer que la lecture et l'intégration de la ligne se sont
 * déroulées correctement.
 *
 * @param fd Descripteur de fichier à partir duquel la ligne doit être lue.
 * @param map Pointeur vers la structure t_map contenant la grille de la carte.
 * @param line_num Indice où la ligne lue sera stockée dans la grille.
 * @return int Retourne 1 en cas de succès, 0 en cas d'échec.
 */
int	read_map_line(int fd, t_map *map, int line_num)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	if (!validate_line_chars(line))
	{
		free(line);
		return (0);
	}
	map->grid[line_num] = ft_strdup(line);
	free(line);
	if (!map->grid[line_num])
		return (0);
	return (1);
}

/**
 * @brief Compte le nombre de lignes valides dans une carte.
 *
 * Cette fonction ouvre le fichier dont le chemin est spécifié par @p filename
 * en mode lecture.
 * Elle lit le fichier ligne par ligne en utilisant la fonction get_next_line,
 * et pour chaque ligne,
 * elle vérifie que tous les caractères sont valides grâce à la fonction
 * validate_line_chars.
 *
 * Si une ligne contient des caractères non valides, la ligne lue est libérée,
 * le fichier est fermé
 * et la fonction retourne -1 pour indiquer une erreur. En cas d'erreur lors de
 * l'ouverture du fichier,
 * la fonction retourne également -1.
 *
 * Si toutes les lignes sont valides, la fonction retourne le nombre
 * total de lignes lues.
 *
 * @param filename Chemin du fichier à lire.
 * @return int Nombre de lignes de la carte en cas de succès, ou
 * -1 en cas d'erreur.
 */
int	count_map_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!validate_line_chars(line))
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
		lines++;
	}
	close(fd);
	return (lines);
}
