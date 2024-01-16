/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_env_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:45:56 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:04:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	*preprocess_value(char *str, int *i)
{
	str = ft_erase(str, *i, *i);
	*i = -1;
	return (str);
}

void	preprocess_envp_value(char **str, int i)
{
	while (str[0] && str[0][++i])
	{
		if (str[0] && str[0][0])
		{
			if (!i && str[0][0] == ' ')
			{
				str[0] = ft_erase(str[0], 0, 0);
				i = -1;
				continue ;
			}
		}
		if (str[0] && str[0][i] && str[0][i] == ' ')
		{
			if (str[0] && str[0][i + 1] && str[0][i + 1] == ' ')
			{
				str[0] = ft_erase(str[0], i, i);
				i = -1;
				continue ;
			}
		}
		if (str[0] && str[0][i] && str[0][i] == ' ' && !str[0][i + 1])
			str[0] = preprocess_value(str[0], &i);
	}
}

char	*determine_key(char *envp)
{
	char		*ret;
	int			size;
	int			i;

	size = 0;
	while (envp[size] && envp[size] != '=')
		size++;
	ret = ft_calloc_exit(size + 1, sizeof(char));
	i = -1;
	while (++i < size)
		ret[i] = envp[i];
	ret[i] = 0;
	return (ret);
}

char	*determine_value(char *envp)
{
	char	*ret;
	int		size;
	int		i;

	size = -1;
	while (*envp && *envp != '=')
		envp++;
	if (!*envp)
		return (0);
	if (*envp == '=')
		envp++;
	while (envp[++size])
		;
	ret = ft_calloc_exit(size + 1, sizeof(char));
	i = -1;
	while (++i < size)
		ret[i] = envp[i];
	ret[i] = 0;
	return (ret);
}
