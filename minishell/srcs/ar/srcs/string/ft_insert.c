/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:07:43 by marvin            #+#    #+#             */
/*   Updated: 2023/10/05 22:13:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_former2(char *str, int i)
{
	char	*ret;
	int		len;
	int		k;

	len = 0;
	k = -1;
	while (str[len] && len < i)
		len++;
	ret = ft_calloc_exit(len + 1, sizeof(char));
	while (++k < len)
		ret[k] = str[k];
	ret[k] = 0;
	return (ret);
}

static char	*create_latter2(char *str, int i)
{
	char	*ret;
	int		len;
	int		k;
	int		_i;

	len = 0;
	k = 0;
	_i = i;
	if (!str[i])
		return (NULL);
	while (str[i])
	{
		len++;
		i++;
	}
	ret = ft_calloc_exit(len + 1, sizeof(char));
	while (k < len)
	{
		ret[k] = str[_i];
		k++;
		_i++;
	}
	ret[k] = 0;
	return (ret);
}

char	*create_ret(char *former, char *src, char *latter)
{
	char	*ret;
	char	*temp;

	ret = NULL;
	temp = NULL;
	if (!former && !latter)
		ret = ft_strdup(src);
	if (!former && latter)
		ret = ft_strjoin_free(ft_strdup(src), latter, BOTH);
	if (former && !latter)
		ret = ft_strjoin_free(former, ft_strdup(src), BOTH);
	if (former && latter)
	{
		temp = ft_strjoin_free(former, ft_strdup(src), BOTH);
		ret = ft_strjoin_free(temp, latter, BOTH);
	}
	return (ret);
}

char	*ft_insert(char *str, int i, char *src)
{
	char	*former;
	char	*latter;
	char	*ret;

	former = NULL;
	latter = NULL;
	ret = NULL;
	if (str)
		former = create_former2(str, i);
	if (str)
		latter = create_latter2(str, i);
	if (str)
		free(str);
	str = NULL;
	ret = create_ret(former, src, latter);
	return (ret);
}
