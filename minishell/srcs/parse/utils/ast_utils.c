/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:41:34 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:03:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	*ft_parser(t_class *child, int flag)
{
	int	target;
	int	i;

	i = -1;
	if (flag == COMMAND)
		target = EXECUTION;
	if (flag == REDIRECTION)
		target = REDIRECTION_TYPE;
	if (flag == ARGUMENT)
		target = REDIRECTION_ARGUMENT;
	child->parser = ft_calloc_exit(ft_strlen(child->src) + 1, sizeof(char));
	while (child->src[++i] && i < ft_strlen(child->src))
	{
		if (child->lexer[i] == target)
			child->parser[i] = child->src[i];
		else
			child->parser[i] = ' ';
	}
	return (child->parser);
}

void	quote_push_quote(char *parser, char *ret, int *i, char status)
{
	ret[*i] = status;
	*i = *i + 1;
	while (parser[*i] != status)
	{
		ret[*i] = status;
		*i = *i + 1;
	}
	if (parser[*i] && (parser[*i] == '"' || parser[*i] == '\''))
	{
		ret[*i] = status;
		*i = *i + 1;
	}
}

char	*quote_info(char *parser, int i, char status, int len)
{
	char	*ret;

	len = ft_strlen_null(parser);
	ret = ft_calloc_exit(len + 1, sizeof(char));
	while (i < len)
	{
		ret[i] = REGULAR_STR;
		if (is_quote(parser[i], &status))
		{
			quote_push_quote(parser, ret, &i, status);
			if (!parser[i])
				break ;
			continue ;
		}
		i++;
	}
	return (ret);
}

int	should_remove(char c, char *str, char type, int i)
{
	if (type != REGULAR_STR)
		return (FALSE);
	if (c == '$' && (str[i + 1] == '\'' || str[i + 1] == '"'))
		return (TRUE);
	return (FALSE);
}

char	*dollar_removal(char *str, int i, char **quote_lexer, int *removed)
{
	while (str[++i])
	{
		if (str[i] && (str[i] == '$' && quote_lexer[0][i] == REGULAR_STR))
		{
			if (str[i + 1] && (str[i + 1] == '\'' || str[i + 1] == '"'))
			{
				*removed = TRUE;
				str = ft_erase(str, i, i);
				*quote_lexer = ft_erase(*quote_lexer, i, i);
				i = -1;
			}
			if (!str || !str[++i])
				break ;
		}
	}
	return (str);
}
