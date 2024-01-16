/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_export_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:53:19 by marvin            #+#    #+#             */
/*   Updated: 2023/10/10 20:35:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	export_lst_sort(t_export **begin_list, \
						int (*cmp)(const char *, const char *))
{
	t_export	*p;
	void		*temp;

	p = *begin_list;
	temp = NULL;
	while ((*begin_list)->next)
	{
		if (cmp((*begin_list)->src, (*begin_list)->next->src) > 0)
		{
			temp = (*begin_list)->src;
			(*begin_list)->src = (*begin_list)->next->src;
			(*begin_list)->next->src = temp;
			*begin_list = p;
		}
		else
			*begin_list = (*begin_list)->next;
	}
	*begin_list = p;
}

void	allocate_values(t_env *begin_list, void	*temp_src, \
						void	*temp_key, void	*temp_value)
{
	begin_list->src = begin_list->next->src;
	begin_list->key = begin_list->next->key;
	begin_list->value = begin_list->next->value;
	begin_list->next->src = temp_src;
	begin_list->next->key = temp_key;
	begin_list->next->value = temp_value;
}

void	env_lst_sort(t_env **begin_list, \
						int (*cmp)(const char *, const char *))
{
	t_env		*p;
	void		*temp_src;
	void		*temp_key;
	void		*temp_value;

	p = *begin_list;
	while ((*begin_list) && (*begin_list)->next)
	{
		if ((*begin_list)->src && (*begin_list)->next->src && \
			cmp((*begin_list)->src, (*begin_list)->next->src) > 0)
		{
			temp_src = (*begin_list)->src;
			temp_key = (*begin_list)->key;
			temp_value = (*begin_list)->value;
			allocate_values(*begin_list, temp_src, temp_key, temp_value);
			*begin_list = p;
		}
		else
			*begin_list = (*begin_list)->next;
	}
	*begin_list = p;
}

char	*create_export_value(char *key, char *value)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*ret;

	s1 = ft_strdup("declare -x ");
	s2 = key;
	s3 = "=";
	s4 = value;
	ret = NULL;
	ret = ft_strjoin_free(s1, s2, FIRST);
	ret = ft_strjoin_free(ret, s3, FIRST);
	ret = ft_strjoin_free(ret, "\"", FIRST);
	ret = ft_strjoin_free(ret, s4, FIRST);
	ret = ft_strjoin_free(ret, "\"", FIRST);
	return (ret);
}
