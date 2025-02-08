/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:38:01 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/06 02:38:14 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_strcpy(char *dst, const char *src, size_t *index)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[*index] = src[i];
		(*index)++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (joined_str == NULL)
		return (NULL);
	index = 0;
	ft_strcpy(joined_str, s1, &index);
	ft_strcpy(joined_str, s2, &index);
	joined_str[index] = '\0';
	return (joined_str);
}