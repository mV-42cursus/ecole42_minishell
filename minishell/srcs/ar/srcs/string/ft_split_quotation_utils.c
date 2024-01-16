/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotation_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 04:54:15 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	quote(int *i, size_t *cnt, char const *s, int flag)
{
	if (flag == 2)
	{
		*i += 1;
		*cnt += 1;
		while (s[*i] && s[*i] != '"')
			*i += 1;
	}
	if (flag == 1)
	{
		*i += 1;
		*cnt += 1;
		while (s[*i] && s[*i] != '\'')
			*i += 1;
	}
}

void	delimeter(char const *s, int *i, char c, size_t *cnt)
{
	if (s[*i])
		if (s[*i] != c && (s[*i + 1] == c || s[*i + 1] == '\0'))
			*cnt += 1;
	if (s[*i])
		*i += 1;
}
