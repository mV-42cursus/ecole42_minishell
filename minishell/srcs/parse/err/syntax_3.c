/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:32:16 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:05:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

int	syntax_empty_pipeline(char *input, int *pipe_loc, int pipe_cnt)
{
	int	rotation;
	int	data[3];
	int	i;

	rotation = -1;
	data[CNT] = pipe_cnt;
	if (input && input[0] == '|')
		return (TRUE);
	while (++rotation < pipe_cnt + 1)
	{
		syntax_calculate_idx2(data, rotation, pipe_loc, input);
		i = data[START];
		while (input[i] && i < data[END])
		{
			if (input[i] != ' ')
				break ;
			i++;
		}
		if (!input[i] || (i == data[END] && input[data[END]] == ' '))
			return (TRUE);
	}
	return (FALSE);
}

int	syntax_count_redirections(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
		{
			cnt++;
			i++;
			if (str[i])
				if (str[i] == '<' || str[i] == '>')
					i++;
			if (!str[i])
				break ;
		}
		i++;
	}
	return (cnt);
}

void	syntax_calculate_idx3(char *_input, int **redirection_type_idx)
{
	int	i;
	int	rot;

	i = 0;
	rot = 0;
	while (_input[i])
	{
		if (_input[i] == '<' || _input[i] == '>')
		{
			redirection_type_idx[rot] = ft_calloc_exit(2, sizeof(int));
			redirection_type_idx[rot][START] = i;
			if (_input[i + 1] && (_input[i + 1] == '<' || _input[i + 1] == '>'))
			{
				redirection_type_idx[rot][END] = i + 1;
				i++;
			}
			else
				redirection_type_idx[rot][END] = i;
			rot++;
		}
		i++;
	}
}

void	syntax_calculate_idx4(int **redirection_type_idx, \
							int rotation, char *input, int *data)
{
	data[START] = redirection_type_idx[rotation][END] + 1;
	if (rotation + 1 < data[CNT])
		data[END] = redirection_type_idx[rotation + 1][START] - 1;
	else
	{
		if (redirection_type_idx[rotation][END] != ft_strlen(input) - 1)
			data[END] = ft_strlen(input) - 1;
		else
			data[END] = ft_strlen(input);
	}
}

int	is_error(char *input, int i, int *data)
{
	if (!input[i])
		return (TRUE);
	if (i == data[END])
		if (input[i] == ' ' || input[i] == PIPE)
			return (TRUE);
	return (FALSE);
}
