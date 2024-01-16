/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:23:55 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

int	queue_count_pipeline(char *input)
{
	char	*_input;
	int		i;
	int		cnt;

	i = -1;
	cnt = 0;
	_input = ft_strdup(input);
	_input = syntax_preprocess_tr_quotes_space(_input);
	while (_input[++i])
		if (_input[i] == PIPE)
			cnt++;
	free_str(&_input);
	return (cnt);
}

void	queue_loc_pipeline(char *input, int *pipe_loc)
{
	char	*_input;
	int		i;
	int		k;

	i = -1;
	k = 0;
	_input = ft_strdup(input);
	_input = syntax_preprocess_tr_quotes_space(_input);
	while (_input[++i])
		if (_input[i] == PIPE)
			pipe_loc[k++] = i;
	free(_input);
}
