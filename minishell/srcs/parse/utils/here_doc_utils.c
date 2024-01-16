/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:17:47 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:03:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	*ft_heredoc_parser(char *src, char *parser, int *lexer, int flag)
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
	parser = ft_calloc_exit(ft_strlen(src) + 1, sizeof(char));
	while (src[++i] && i < ft_strlen(src))
	{
		if (lexer[i] == target)
			parser[i] = src[i];
		else
			parser[i] = ' ';
	}
	return (parser);
}
