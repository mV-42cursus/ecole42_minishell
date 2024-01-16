/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_cmd_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:15:17 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	*exit_status_expansion(char **str, char *key)
{
	char	*ascii_signal;
	char	*ret;
	char	*temp;

	(void)key;
	ret = NULL;
	temp = NULL;
	ascii_signal = NULL;
	ascii_signal = ft_itoa(g_signal);
	temp = ft_strdup(str[0] + 2);
	ret = ft_strjoin_free(ascii_signal, temp, BOTH);
	free_str(&str[0]);
	return (ret);
}

void	value_not_found_case(char **str, char *key, \
							int i, t_dollar **dollar_lst)
{
	(void)dollar_lst;
	if (str[0][i] == '\t')
	{
		if (!key[0])
			;
		else
		{
			if (str[0] && str[0][i + 1])
			{
				str[0] = ft_erase(str[0], i, \
										i + ft_strlen_null((*dollar_lst)->arg));
				if (str[0] == NULL)
					str[0] = ft_strdup("");
			}
		}
	}
}

void	value_found_case(char **str, char *value, int i, t_dollar **dollar_lst)
{
	str[0] = ft_erase(str[0], i, i + ft_strlen_null((*dollar_lst)->arg));
	str[0] = ft_insert(str[0], i, value);
}

void	regular_case(char **str, int i, t_dollar **dollar_lst, t_env *envp_lst)
{
	char	*key;
	char	*value;

	str[0][i] = '\t';
	key = (*dollar_lst)->arg;
	if (key && key[0] == '?')
	{
		str[0] = exit_status_expansion(str, key);
		return ;
	}
	value = env_search_value_lst(envp_lst, key, &ft_strcmp);
	if (!value)
		value_not_found_case(str, key, i, dollar_lst);
	else
		value_found_case(str, value, i, dollar_lst);
	(*dollar_lst) = (*dollar_lst)->next;
}

void	double_quote_case(char **str, int i, \
							t_dollar **dollar_lst, t_env *envp_lst)
{
	char	*key;
	char	*value;

	str[0][i] = '\t';
	key = (*dollar_lst)->arg;
	if (key && key[0] == '?')
	{
		str[0] = exit_status_expansion(str, key);
		return ;
	}
	value = env_search_value_lst(envp_lst, key, &ft_strcmp);
	if (!value)
		value_not_found_case(str, key, i, dollar_lst);
	else
		value_found_case(str, value, i, dollar_lst);
	(*dollar_lst) = (*dollar_lst)->next;
}
