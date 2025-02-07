/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdi-tria <fdi-tria@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:21:00 by fdi-tria          #+#    #+#             */
/*   Updated: 2025/02/07 12:21:48 by fdi-tria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

t_queue_node	*create_node(int x, int y, int dist)
{
	t_queue_node	*node;

	node = malloc(sizeof(t_queue_node));
	if (!node)
		return (NULL);
	node->x = x;
	node->y = y;
	node->dist = dist;
	node->next = NULL;
	return (node);
}

void	enqueue(t_queue_node **queue, int x, int y, int dist)
{
	t_queue_node	*node;
	t_queue_node	*temp;

	node = create_node(x, y, dist);
	if (!node)
		return ;
	if (!*queue)
	{
		*queue = node;
		return ;
	}
	temp = *queue;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

t_queue_node	*dequeue(t_queue_node **queue)
{
	t_queue_node	*temp;

	if (!*queue)
		return (NULL);
	temp = *queue;
	*queue = (*queue)->next;
	return (temp);
}
