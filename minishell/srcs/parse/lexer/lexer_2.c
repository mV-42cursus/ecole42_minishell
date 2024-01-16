/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:18:45 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	push(int *lexer, int *i, char *input, char *type)
{
	while (1)
	{
		lexer[*i] = 'A';
		*i = *i + 1;
		if (!input[*i])
			break ;
		if (input[*i] != *type)
			continue ;
		if (input[*i] == *type)
			break ;
	}
}

void	hasing_redirection_argument(int *lexer, char *input, int *i, char *type)
{
	int	space;

	space = 1;
	while (1)
	{
		if (lexer[*i] != 'T')
			lexer[*i] = 'A';
		*i = *i + 1;
		if (!input[*i] || lexer[*i] == 'T' || (input[*i] == ' ' && space == 0))
		{
			if (!input[*i])
				break ;
			if (lexer[*i] == 'T')
				*i = *i - 1;
			break ;
		}
		if (input[*i] == ' ' && space == 1)
			continue ;
		space = 0;
		if (is_quote(input[*i], type))
			push(lexer, i, input, type);
	}
}
