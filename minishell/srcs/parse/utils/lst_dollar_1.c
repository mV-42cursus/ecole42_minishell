/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dollar_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:43:54 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:04:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

t_dollar	*dollar_lstlast(t_dollar *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

void	dollar_lstadd_back(t_dollar **lst, t_dollar *new)
{
	t_dollar	*p;

	p = dollar_lstlast(*lst);
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		p = dollar_lstlast(*lst);
		p->next = new;
	}
}

t_dollar	*dollar_lstnew(char *str, char *lexer, int i)
{
	t_dollar	*ptr;

	ptr = NULL;
	ptr = ft_calloc(1, sizeof(t_dollar));
	ptr->status = lexer[i];
	ptr->arg = dollar_determine_arg(str, i, 0, 0);
	ptr->next = NULL;
	return (ptr);
}

struct	s_dollar	*create_dollar_lst(char *parser, char *lexer, int i)
{
	t_dollar	*dollar;

	dollar = NULL;
	while (parser[i])
	{
		if (parser[i] == '$')
			dollar_lstadd_back(&dollar, dollar_lstnew(parser, lexer, i));
		i++;
	}
	return (dollar);
}
