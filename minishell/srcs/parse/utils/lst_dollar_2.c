/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dollar_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:38:25 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:04:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	*determine_arg(char *s, char *ret, int i, int k)
{
	while (s[i])
	{
		if (!(!s[i] || s[i] == '\'' || \
			s[i] == '"' || s[i] == '$' || s[i] == ' '))
			ret[k++] = s[i++];
		else
			break ;
	}
	return (ret);
}

char	*dollar_determine_arg(char *s, int i, int len, int k)
{
	char	*ret;
	int		_i;

	_i = i;
	i++;
	while (s[i])
	{
		if (!(!s[i] || s[i] == '\'' || s[i] == '"' || \
			s[i] == '$' || s[i] == ' '))
			i++;
		else
			break ;
		len++;
	}
	ret = ft_calloc_exit(len + 1, sizeof(char));
	i = _i;
	i++;
	ret = determine_arg(s, ret, i, k);
	return (ret);
}
