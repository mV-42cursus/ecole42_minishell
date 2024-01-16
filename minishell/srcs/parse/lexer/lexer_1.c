/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:23:44 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

int	is_redirection_type(int *lexer, char *input, int *i)
{
	if (lexer[*i] == REDIRECTION_TYPE)
	{
		if (input[*i + 1])
		{
			if (lexer[*i + 1] == REDIRECTION_TYPE)
				*i = *i + 1;
			return (TRUE);
		}
		return (TRUE);
	}
	return (FALSE);
}

void	redirection_arg_idx(int *lexer, int *_data, char *input, char *type)
{
	int	i;

	(void)_data;
	i = -1;
	while (input[++i])
	{
		if (is_redirection_type(lexer, input, &i))
			hasing_redirection_argument(lexer, input, &i, type);
		if (input[i] == '\0')
			break ;
	}
}

void	redirection_type_idx(char *input, int *lexer)
{
	char	*_input;
	int		**redirection_type_idx;
	int		data[2];
	char	type;

	_input = ft_strdup(input);
	_input = syntax_preprocess_tr_quotes_space(_input);
	data[_CNT] = syntax_count_redirections(_input);
	if (data[_CNT] == 0)
	{
		free_str(&_input);
		return ;
	}
	redirection_type_idx = ft_calloc_exit(data[_CNT], sizeof(int *));
	syntax_calculate_idx3(_input, redirection_type_idx);
	free_str(&_input);
	data[ROTATION] = -1;
	while (++data[ROTATION] < data[_CNT])
	{
		lexer[redirection_type_idx[data[ROTATION]][START]] = REDIRECTION_TYPE;
		lexer[redirection_type_idx[data[ROTATION]][END]] = REDIRECTION_TYPE;
	}
	free_int_double_array(data[_CNT], redirection_type_idx);
	redirection_arg_idx(lexer, data, input, &type);
}

int	*idx_info(char *input)
{
	int	*lexer;
	int	i;

	lexer = ft_calloc(ft_strlen(input), sizeof(int));
	i = -1;
	while (++i < ft_strlen(input))
		lexer[i] = EXECUTION;
	redirection_type_idx(input, lexer);
	return (lexer);
}
