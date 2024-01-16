/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:15:52 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:18:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_node *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

// #include <stdio.h>
// #include "ft_lstnew.c"
// #include "ft_lstadd_front.c"
// void ft_display_lst(t_node *head)
// {
// 	while (head)
// 	{
// 		printf("[%p]\t", head);
// 		printf("[%s]\n", head->content);
// 		head = head->next;
// 	}
// }
// int main()
// {
// 	t_node *head = ft_lstnew("world");
// 	t_node *node1 = ft_lstnew("hello");

// 	puts("");
// 	ft_lstadd_front(&head, node1);
// 	ft_display_lst(head);
// 	printf("\nft_lstsize(t_node *head) = [%d]\n", ft_lstsize(head));
// 	puts("");
// 	return (0);
// }