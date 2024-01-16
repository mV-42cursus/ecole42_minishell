/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_cmd_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:17:46 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	*expand_cmd(char *str, t_dollar **dollar_lst, t_env *envp_lst, int i)
{
	while (str[i])
	{
		if (str[i] == '$')
		{
			if ((*dollar_lst)->status == REGULAR_STR)
				regular_case(&str, i, dollar_lst, envp_lst);
			else if ((*dollar_lst)->status == DOUBLE_QUOTE)
			{
				double_quote_case(&str, i, dollar_lst, envp_lst);
			}
			else if ((*dollar_lst)->status == SINGLE_QUOTE)
			{
				str[i] = '\t';
				(*dollar_lst) = (*dollar_lst)->next;
			}
			i = 0;
			if (!str || !str[i])
				break ;
			continue ;
		}
		i++;
	}
	return (str);
}

char	**create_cmd_arr(t_token *tokens, int len, int i)
{
	char	**ret;
	int		k;

	k = 0;
	while (++i < tokens[0].cnt)
		if (tokens[i].str != NULL)
			len++;
	ret = ft_calloc_exit(len + 1, sizeof(char *));
	i = -1;
	while (++i < tokens[0].cnt)
	{
		if (tokens[i].str != NULL)
			ret[k++] = ft_strdup(tokens[i].str);
	}
	return (ret);
}

char	**cmd_expansion(t_token *tokens, t_dollar *dollar_lst, t_env *envp_lst)
{
	int	i;
	int	k;

	i = -1;
	k = -1;
	while (++i < tokens[0].cnt)
	{
		tokens[i].str = expand_cmd(tokens[i].str, &dollar_lst, envp_lst, 0);
		k = -1;
		while (++k < ft_strlen_null(tokens[i].str))
			if (tokens[i].str[k] == '\t')
				tokens[i].str[k] = '$';
	}
	i = -1;
	return (create_cmd_arr(tokens, 0, -1));
}
