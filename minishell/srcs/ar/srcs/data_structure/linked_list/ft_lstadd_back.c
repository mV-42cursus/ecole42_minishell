/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:15:05 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:18:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*p;

	p = ft_lstlast(*lst);
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
}

// void	ft_print_result(t_node *elem)
// {
// 	int		len;
// 	len = 0;
// 	while (((char *)elem->content)[len])
// 		len++;
// 	write(1, elem->content, len);
// 	write(1, "\n", 1);
// }
// t_node	*ft_lstnewone(void *content)
// {
// 	t_node	*elem;
// 	elem = (t_node *)malloc(sizeof(t_node));
// 	if (!elem)
// 		return (NULL);
// 	if (!content)
// 		elem->content = NULL;
// 	else
// 		elem->content = content;
// 	elem->next = NULL;
// 	return (elem);
// }
// void ft_display_lst(t_node *head)
// {
// 	while (head)
// 	{
// 		printf("[%p]\t", head);
// 		printf("[%s]\n", (char *)head->content);
// 		head = head->next;
// 	}
// }
// #include <stdio.h>
// int main(int argc, const char *argv[])
// {
// 	// t_node		*begin;
// 	// t_node		*elem;
// 	// t_node		*elem2;
// 	// t_node		*elem3;
// 	// t_node		*elem4;
// 	// char		*str = strdup("lorem");
// 	// char		*str2 = strdup("ipsum");
// 	// char		*str3 = strdup("dolor");
// 	// char		*str4 = strdup("sit");
// 	// elem = ft_lstnewone(str);
// 	// elem2 = ft_lstnewone(str2);
// 	// elem3 = ft_lstnewone(str3);
// 	// elem4 = ft_lstnewone(str4);
// 	// // alarm(TIMEOUT);
// 	// if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
// 	// 	return (0);
// 	// else if (atoi(argv[1]) == 1)
// 	// {
// 	// 	begin = NULL;
// 	// 	ft_lstadd_back(&begin, elem);
// 	// 	ft_lstadd_back(&begin, elem2);
// 	// 	ft_lstadd_back(&begin, elem3);
// 	// 	ft_lstadd_back(&begin, elem4);
// 	// 	while (begin)
// 	// 	{
// 	// 		ft_print_result(begin);
// 	// 		begin = begin->next;
// 	// 	}
// 	// }
// 	t_node *l =  NULL; 
// 	t_node *l2 =  NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// 	/* 1 */ 
// 	if (l->content == (void*)1)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 2 */ 
// 	if (l->next == 0)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	ft_lstadd_back(&l, ft_lstnew((void*)2));
// 	/* 3 */ 
// 	if(l->content == (void*)1)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 4 */ 
// 	if(((t_node *)(l->next))->content == (void*)2)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 5 */ 
// 	if(((t_node *)(l->next))->next == 0)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	ft_lstadd_back(&l2, ft_lstnew((void*)3));
// 	ft_lstadd_back(&l2, ft_lstnew((void*)4));
// 	ft_lstadd_back(&l, l2);
// 	/* 6 */ 
// 	if(l->content == (void*)1)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 7 */
// 	if(((t_node *)(l->next))->content == (void*)2)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 8 */ 
// 	if(((t_node *)(((t_node *)(l->next))->next))->content == (void*)3)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 9 */ // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// 	/*
// 		p = ft_lstlast(*lst);
// 		new->next = NULL; @@@@@@@@@@@@@@@@ this was the problem @@@@@@
// 		p->next = new;
// 	*/
// 	if(((t_node *)
// 		 ((t_node *)(((t_node *)(l->next))->next))->next)->content == (void*)4)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	/* 10 */ 
// 	if(((t_node *)((t_node *)(((t_node *)(l->next))->next))->next)->next == 0)
// 		printf("True\n");
// 	else
// 		puts("False\n");
// 	return (0);
// }