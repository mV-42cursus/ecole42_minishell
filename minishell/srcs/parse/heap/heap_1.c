/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:27:51 by marvin            #+#    #+#             */
/*   Updated: 2023/10/10 18:47:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_macro.h"
#include "structure.h"

void	free_str(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

void	free_tokens(t_token *token)
{
	int	start;
	int	end;

	start = -1;
	end = token[0].cnt;
	while (++start < end)
		free_str(&token[start].str);
	free(token);
}

void	free_int_double_array(int row, int **array)
{
	int	row_idx;

	row_idx = -1;
	while (++row_idx < row)
		free(array[row_idx]);
	free(array);
}

void	free_char_double_pointer(char ***arr)
{
	int	i;

	i = -1;
	while (arr[0][++i])
		free(arr[0][i]);
	free(*arr);
	*arr = NULL;
}
