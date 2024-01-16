/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:15:59 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:43:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dequeue(struct s_queue *queue)
{
	t_node	*tmp;
	void	*ret;

	if (queue == NULL)
		exit(EXIT_FAILURE);
	if (queue->rear == NULL)
		return (NULL);
	tmp = queue->rear;
	ret = tmp->content;
	if (queue->rear == queue->front)
	{
		queue->front = NULL;
		queue->rear = NULL;
		free(tmp);
		return (ret);
	}
	queue->rear = queue->rear->next;
	free(tmp);
	return (ret);
}
