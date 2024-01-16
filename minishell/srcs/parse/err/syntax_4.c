/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 02:33:30 by marvin            #+#    #+#             */
/*   Updated: 2023/10/07 17:52:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

int	export_value_syntax_error(char *cmd)
{
	char	*value;
	int		i;	

	value = determine_value(cmd);
	i = -1;
	while (value && value[++i])
	{
		if (value[i] == ' ')
		{
			ft_putstr_fd("export value syntax error (no space allowed)\n", \
						STDERR_FILENO);
			free_str(&value);
			return (TRUE);
		}
	}
	free_str(&value);
	return (FALSE);
}

int	is_redirection_error(int **redirection_type_idx, \
						int redirection_cnt, char *input)
{
	int	rotation;
	int	data[3];
	int	i;

	rotation = 0;
	data[CNT] = redirection_cnt;
	while (rotation < redirection_cnt)
	{
		syntax_calculate_idx4(redirection_type_idx, rotation, input, data);
		i = data[START] - 1;
		while (++i <= data[END])
		{
			if (input[i] == ' ')
				continue ;
			if (input[i] == '\'' || input[i] == '\"')
				break ;
			else
				break ;
		}
		if (is_error(input, i, data))
			return (TRUE);
		rotation++;
	}
	return (FALSE);
}

int	syntax_redirection_error(char *input)
{
	char	*_input;
	int		**redirection_type_idx;
	int		cnt;

	_input = ft_strdup(input);
	_input = syntax_preprocess_tr_quotes_space(_input);
	cnt = syntax_count_redirections(_input);
	if (!cnt)
	{
		free_str(&_input);
		return (FALSE);
	}
	redirection_type_idx = ft_calloc_exit(cnt, sizeof(int *));
	syntax_calculate_idx3(_input, redirection_type_idx);
	if (is_redirection_error(redirection_type_idx, cnt, input))
	{
		ft_putendl_fd("syntax error (redirection)", 2);
		free_int_double_array(cnt, redirection_type_idx);
		free_str(&_input);
		return (TRUE);
	}
	free_int_double_array(cnt, redirection_type_idx);
	free_str(&_input);
	return (FALSE);
}

int	syntax_white_space(char *input)
{
	while (*input)
	{
		if (*input >= 9 && *input <= 13)
		{
			ft_putendl_fd("syntax error (whitespace)", 2);
			return (TRUE);
		}
		input++;
	}
	return (FALSE);
}

int	double_dollar(char *input)
{
	while (*input)
	{
		if (*input == '$' && *(input + 1) == '$')
		{
			ft_putendl_fd("syntax error (no consecutive $)", 2);
			return (TRUE);
		}
		input++;
	}
	return (FALSE);
}
