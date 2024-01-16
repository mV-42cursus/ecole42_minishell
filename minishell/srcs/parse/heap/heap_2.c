/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:27:51 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 14:44:06 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_macro.h"
#include "structure.h"

void	env_lstclear(t_env **lst, void (*del)(char **))
{
	t_env	*ptr;

	while (*lst)
	{
		ptr = *lst;
		del(&((*lst)->src));
		del(&((*lst)->key));
		del(&((*lst)->value));
		*lst = (*lst)->next;
		free(ptr);
	}
	*lst = NULL;
}

void	redirection_lstclear(t_redirection **lst, void (*del)(char **))
{
	t_redirection	*ptr;

	while (*lst)
	{
		ptr = *lst;
		del(&((*lst)->argument));
		*lst = (*lst)->next;
		free(ptr);
	}
	*lst = NULL;
}

void	dollar_lstclear(t_dollar **lst, void (*del)(char **))
{
	t_dollar	*ptr;

	while (*lst)
	{
		ptr = *lst;
		del(&((*lst)->arg));
		*lst = (*lst)->next;
		free(ptr);
	}
	*lst = NULL;
}
