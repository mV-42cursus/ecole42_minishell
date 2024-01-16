/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:04 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:43:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	enqueue(struct s_queue *queue, void *data)
{
	struct s_node	*node;
	struct s_node	*p;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	if (!node)
		exit(EXIT_FAILURE);
	node->content = data;
	node->next = NULL;
	if (queue == NULL)
		exit(EXIT_FAILURE);
	if (queue->front == NULL && queue->rear == NULL)
	{
		queue->front = node;
		queue->rear = node;
		p = queue->front;
	}
	else
	{
		p = queue->rear;
		while (p->next)
			p = p->next;
		p->next = node;
		node->next = NULL;
		queue->front = node;
	}
}
