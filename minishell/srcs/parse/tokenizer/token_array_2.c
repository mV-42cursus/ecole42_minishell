/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_array_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:34:35 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	*allocate_characters(char *line, char type, char *str, char sep)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (line[++i])
	{
		if (!line[i] || line[i] == sep)
			break ;
		if (is_quote(line[i], &type))
		{
			while (line[++i] && line[i] != type)
			{
				str[k] = line[i];
				k++;
			}
			continue ;
		}
		if (line[i] && line[i] != sep)
		{
			str[k] = line[i];
			k++;
		}
	}
	return (str);
}

int	meta_character(char *line, int dest)
{
	int	i;

	i = -1;
	while (++i < dest)
	{
		if (line[i] == '$')
			return (TRUE);
	}
	return (FALSE);
}

t_token	*create_token_arr(char *line, char sep, char type)
{
	t_token	*ret;
	int		cnt;
	int		i;
	int		word_len;
	int		ptr;

	i = -1;
	cnt = calculate_cnt(line, sep, type);
	ret = ft_calloc_exit(cnt + 1, sizeof(t_token));
	while (++i < cnt)
	{
		while (*line == sep)
			line++;
		word_len = calculate_word_len(line, type, sep);
		ret[i].cnt = cnt;
		ret[i].str = ft_calloc_exit(word_len + 1, sizeof(char));
		ret[i].str = allocate_characters(line, type, ret[i].str, sep);
		ptr = calculate_pointer(line, sep, type);
		line = line + ptr + 1;
	}
	return (ret);
}
