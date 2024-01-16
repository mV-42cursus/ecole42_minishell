/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:32:13 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

int	syntax_is_all_space(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
		if (input[i] != ' ')
			return (FALSE);
	return (TRUE);
}

int	syntax_error(char *input)
{
	char	*_input;

	_input = NULL;
	if (syntax_is_all_space(input))
		return (TRUE);
	_input = ft_strdup(input);
	_input = syntax_preprocess_tr_quotes_space(_input);
	if (is_syntax_error(_input))
	{
		ft_putendl_fd("syntax error", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	syntax_quote_check(char **input, int *i, char flag)
{
	*i = *i + 1;
	while (input[0][*i] && input[0][*i] != flag)
		*i = *i + 1;
	if (input[0][*i] != flag)
	{
		if (flag == DOUBLE_QUOTE)
			ft_putendl_fd("syntax error: unclosed double quote (\")", 2);
		if (flag == SINGLE_QUOTE)
			ft_putendl_fd("syntax error: unclosed single quote (')", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	syntax_unclosed_quote(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == SINGLE_QUOTE)
			if (syntax_quote_check(&input, &i, SINGLE_QUOTE))
				return (TRUE);
		if (input[i] == DOUBLE_QUOTE)
			if (syntax_quote_check(&input, &i, DOUBLE_QUOTE))
				return (TRUE);
		i++;
	}
	return (FALSE);
}

void	syntax_calculate_idx2(int *data, int rot, int *pipe_loc, char *input)
{
	if (rot == 0)
	{
		data[START] = 0;
		data[END] = pipe_loc[rot] - 1;
	}
	else if (rot < data[CNT])
	{
		data[START] = pipe_loc[rot - 1] + 1;
		data[END] = pipe_loc[rot] - 1;
	}
	else
	{
		data[START] = pipe_loc[rot - 1] + 1;
		data[END] = ft_strlen(input);
	}
}
