/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:52:16 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/03 15:52:26 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_fd_list	*ft_get_fd_node(t_fd_list **head, int fd)
{
	t_fd_list	*node;

	node = *head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->data = NULL;
	node->len = 0;
	node->capacity = 0;
	node->next = *head;
	*head = node;
	return (node);
}