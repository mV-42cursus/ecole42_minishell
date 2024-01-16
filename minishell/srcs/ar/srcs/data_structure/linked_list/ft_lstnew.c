/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:15:47 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:18:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(void *content)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = (t_node *)malloc(sizeof(t_node) * 1);
	if (!ptr)
		return (NULL);
	ptr->content = (void *)content;
	ptr->next = NULL;
	return (ptr);
}

// #include <stdio.h>
// int main()
// {
// 	puts("\n----------[INT ARRAY TEST]----------\n");
// 	int i = 42;
// 	t_node *p = ft_lstnew((void *)(&i));
// 	int *arr = (int *)(p->content);
// 	printf("p->content   =  [%d]\n", arr[0]);
// 	printf("p->next      =  [%p]\n", p->next);
// 	puts("\n----------[CHAR ARRAY TEST]----------\n");
// 	char *str = "Hello World!";
// 	t_node *p1 = ft_lstnew((void *)str);
// 	printf("p1->content  =  [%s]\n", (char *)p1->content);
// 	printf("p1->next     =  [%p]\n\n", p1->next);
// 	puts("-------------------------------------------");
// }