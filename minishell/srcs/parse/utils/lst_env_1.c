/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:55:11 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 14:36:58 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*p;

	p = env_lstlast(*lst);
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		p = env_lstlast(*lst);
		p->next = new;
	}
}

t_env	*env_lstlast(t_env *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

t_env	*env_lstnew(char *envp)
{
	t_env	*ptr;

	ptr = NULL;
	ptr = ft_calloc(1, sizeof(t_env));
	ptr->src = ft_strdup(envp);
	ptr->key = determine_key(envp);
	ptr->value = determine_value(envp);
	ptr->is_export = TRUE;
	ptr->next = NULL;
	return (ptr);
}

char	*env_search_value_lst(t_env *env_lst, char *key, \
								int (*cmp)(char *, char *))
{
	while (env_lst)
	{
		if (env_lst->key && key && cmp(env_lst->key, key) == 0)
		{
			preprocess_envp_value(&env_lst->value, -1);
			return (env_lst->value);
		}
		env_lst = env_lst->next;
	}
	return (NULL);
}

struct s_env	*create_environment_lst(char **envp)
{
	t_env	*env;
	int		size;
	int		rotation;

	size = -1;
	rotation = -1;
	env = NULL;
	while (envp[++size])
		;
	while (++rotation < size)
		env_lstadd_back(&env, env_lstnew(envp[rotation]));
	return (env);
}
