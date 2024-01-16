/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_export_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:55:11 by marvin            #+#    #+#             */
/*   Updated: 2023/10/07 17:50:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	export_lstadd_back(t_export **lst, t_export *new)
{
	t_export	*p;

	p = export_lstlast(*lst);
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		p = export_lstlast(*lst);
		p->next = new;
	}
}

t_export	*export_lstlast(t_export *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

t_export	*export_lstnew(char *str)
{
	t_export	*ptr;

	ptr = NULL;
	ptr = ft_calloc_exit(1, sizeof(t_export));
	ptr->src = str;
	ptr->next = NULL;
	return (ptr);
}

t_export	*create_export_lst(t_env *envp_lst)
{
	t_export	*export_lst;
	char		*str;
	int			len_key;
	int			len_value;

	export_lst = NULL;
	while (envp_lst)
	{
		len_key = ft_strlen(envp_lst->key);
		len_value = ft_strlen(envp_lst->value);
		str = ft_calloc_exit(11 + len_key + 1 + len_value + 2 + 1, \
							sizeof(char));
		str = create_export_value(envp_lst->key, envp_lst->value);
		export_lstadd_back(&export_lst, export_lstnew(str));
		envp_lst = envp_lst->next;
	}
	export_lst_sort(&export_lst, ft_strcmp);
	return (export_lst);
}
