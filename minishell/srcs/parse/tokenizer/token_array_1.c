/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_array_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:02:30 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

int	is_quote(char c, char *type)
{
	if (c == DOUBLE_QUOTE)
	{
		*type = DOUBLE_QUOTE;
		return (TRUE);
	}
	if (c == SINGLE_QUOTE)
	{
		*type = SINGLE_QUOTE;
		return (TRUE);
	}
	return (FALSE);
}

void	quote_handler_word_cnt(char *line, int *i, char type, char sep)
{
	int	inside;

	inside = TRUE;
	while (1)
	{
		if (!line[*i])
			break ;
		if (line[*i] == sep && inside == FALSE)
			break ;
		*i = *i + 1;
		while (line[*i] && line[*i] != type)
			*i = *i + 1;
		if (line[*i] && !is_quote(line[*i], &type))
			*i = *i + 1;
		if (line[*i] && is_quote(line[*i], &type))
			*i = *i + 1;
		while (line[*i] && !is_quote(line[*i], &type) && line[*i] != sep)
			*i = *i + 1;
		if (line[*i] == sep)
			inside = FALSE;
	}
}

int	calculate_cnt(char *line, char sep, char type)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = -1;
	while (line[++i])
	{
		if (is_quote(line[i], &type))
		{
			cnt++;
			quote_handler_word_cnt(line, &i, type, sep);
		}
		if (line[i] == '\0')
			break ;
		if (line[i] != sep && (line[i + 1] == sep || !line[i + 1]))
			cnt++;
	}
	return (cnt);
}

int	calculate_pointer(char *line, char sep, char type)
{
	int	ptr;

	ptr = -1;
	while (line[++ptr])
	{
		if (is_quote(line[ptr], &type))
		{
			quote_handler_word_cnt(line, &ptr, type, sep);
			return (ptr);
		}
		if (line[ptr] == '\0')
			break ;
		if (line[ptr] != sep && (line[ptr + 1] == sep || !line[ptr + 1]))
			return (ptr);
	}
	return (ptr);
}

int	calculate_word_len(char *line, char sep, char type)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (line[++i])
	{
		if (!line[i])
			break ;
		if (line[i] == sep)
			break ;
		if (is_quote(line[i], &type))
		{
			while (line[++i] && line[i] != type)
				len++;
			continue ;
		}
		len++;
	}
	return (len);
}
