/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:15:14 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:18:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	t_node	*ptr;

	if (!new)
		return ;
	ptr = new;
	ptr->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main()
// {
// 	t_node *head;
// 	t_node *new;

// 	head = (t_node *)malloc(sizeof(t_node) * 1);
// 	new = (t_node *)malloc(sizeof(t_node) * 1);
// 	head->content = (void *)"Wolrd";
// 	head->next = NULL;
// 	new->content = (void *)"Hello";
// 	new->next = NULL;
// 	ft_lstadd_front(&head, new);
// 	while (head)
// 	{
// 		printf("[%p]\t->\t", head->next);
// 		printf("[%s]\n", (char *)head->content);
// 		head = head->next;
// 	}
// 	return (0);
// }