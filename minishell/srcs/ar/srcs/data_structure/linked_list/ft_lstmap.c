/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:15:42 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:18:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_node	*node_check(void *value, t_node *begin_lst, void (*del)(void *))
{
	del(value);
	ft_lstclear(&begin_lst, del);
	return (NULL);
}

t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node	*begin_lst;
	t_node	*node;
	void	*value;

	begin_lst = NULL;
	node = NULL;
	while (lst)
	{
		value = f(lst->content);
		if (value)
		{
			node = ft_lstnew(value);
			if (!node)
				return (node_check(value, begin_lst, del));
			ft_lstadd_back(&begin_lst, node);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&begin_lst, del);
			return (NULL);
		}
	}
	return (begin_lst);
}
