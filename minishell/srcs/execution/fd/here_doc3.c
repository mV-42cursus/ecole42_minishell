/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:12:34 by jongolee          #+#    #+#             */
/*   Updated: 2023/10/10 16:42:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

void	make_here_doc_file_sub(int *fd, t_redirection *red)
{
	int		i;
	char	*src;
	char	*file;

	i = 0;
	while (i < 16)
	{
		file = ft_itoa(i);
		src = ft_strjoin("/tmp/.shell_tmp/", file);
		free_str(&file);
		if (access(src, O_RDONLY) >= 0)
		{
			i++;
			free_str(&src);
			src = 0;
		}
		else
		{
			*fd = open(src, O_CREAT | O_RDWR, 0644);
			red->src = src;
			break ;
		}
	}
}

char	*expand_heredoc(char *str, t_dollar **dollar_lst, \
t_env *envp_lst, int i)
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

char	*heredoc_str_expansion(char *str, t_dollar \
**dollar_lst, t_env *envp_lst)
{
	int	k;

	k = -1;
	str = expand_heredoc(str, dollar_lst, envp_lst, 0);
	while (++k < ft_strlen_null(str))
		if (str[k] == '\t')
			str[k] = '$';
	return (str);
}
