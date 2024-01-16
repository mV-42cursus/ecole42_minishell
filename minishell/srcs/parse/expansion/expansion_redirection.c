/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:08:49 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	*expand_redirection(char *str, t_dollar **dollar_lst, \
						t_env *envp_lst, int i)
{
	while (str[i])
	{
		if (str[i] == '$')
		{
			if ((*dollar_lst)->status == REGULAR_STR)
				regular_case(&str, i, dollar_lst, envp_lst);
			else if ((*dollar_lst)->status == DOUBLE_QUOTE)
				double_quote_case(&str, i, dollar_lst, envp_lst);
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

void	redirection_expansion(t_redirection *redirection_lst, \
								t_dollar *dollar_lst, t_env *envp_lst)
{
	int	i;

	i = -1;
	while (redirection_lst)
	{
		if (redirection_lst->type != IN_HEREDOC)
			redirection_lst->argument = expand_redirection \
				(redirection_lst->argument, &dollar_lst, envp_lst, 0);
		i = -1;
		while (++i < ft_strlen_null(redirection_lst->argument))
			if (redirection_lst->argument[i] == '\t')
				redirection_lst->argument[i] = '$';
		redirection_lst = redirection_lst->next;
	}
}
