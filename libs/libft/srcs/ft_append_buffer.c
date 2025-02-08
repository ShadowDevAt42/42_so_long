/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:49:49 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/03 15:50:32 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_append_buffer(t_fd_list *node, char *data, size_t data_len)
{
	char	*new_data;
	size_t	new_capacity;

	if (node->len + data_len + 1 > node->capacity)
	{
		new_capacity = node->capacity * 2 + data_len + 1;
		new_data = malloc(new_capacity);
		if (!new_data)
			return (-1);
		if (node->data)
		{
			ft_memcpy(new_data, node->data, node->len);
			free(node->data);
		}
		node->data = new_data;
		node->capacity = new_capacity;
	}
	ft_memcpy(node->data + node->len, data, data_len);
	node->len += data_len;
	node->data[node->len] = '\0';
	return (0);
}