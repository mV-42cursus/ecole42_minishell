/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:09:47 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	syntax_quote_matching_idx(char *_input, int *i, char flag)
{
	*i = *i + 1;
	while (_input[*i] && _input[*i] != flag)
		*i = *i + 1;
}

void	syntax_calculate_idx(int *start, int *end, char *_input)
{
	int	i;

	i = 0;
	while (_input[i])
	{
		if (_input[i] == SINGLE_QUOTE)
		{
			*start = i;
			syntax_quote_matching_idx(_input, &i, SINGLE_QUOTE);
			*end = i;
			return ;
		}
		if (_input[i] == DOUBLE_QUOTE)
		{
			*start = i;
			syntax_quote_matching_idx(_input, &i, DOUBLE_QUOTE);
			*end = i;
			return ;
		}
		i++;
	}
}

char	*syntax_tr_quote(int start, int end, char *_input)
{
	int	i;

	i = start;
	while (i < end + 1)
		_input[i++] = ' ';
	return (_input);
}

int	is_syntax_error(char *_input)
{
	size_t	len;

	len = ft_strlen(_input);
	if (ft_strnstr(_input, ">>>", len) || ft_strnstr(_input, ">><", len) || \
		ft_strnstr(_input, "><", len))
	{
		free(_input);
		return (TRUE);
	}
	if (ft_strnstr(_input, "<<<", len) || ft_strnstr(_input, "<<>", len) || \
		ft_strnstr(_input, "<>", len))
	{
		free(_input);
		return (TRUE);
	}
	if (ft_strnstr(_input, "||", len))
	{
		free(_input);
		return (TRUE);
	}
	free(_input);
	return (FALSE);
}

char	*syntax_preprocess_tr_quotes_space(char *_input)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (1)
	{
		start = 0;
		end = 0;
		syntax_calculate_idx(&start, &end, _input);
		if (!start && !end)
			break ;
		_input = syntax_tr_quote(start, end, _input);
	}
	return (_input);
}
