/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:37:07 by marvin            #+#    #+#             */
/*   Updated: 2023/10/05 22:11:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_former(char *str, int start, int end)
{
	int		i;
	int		len;
	char	*ret;

	(void)end;
	i = 0;
	len = 0;
	while (len < start)
		len++;
	if (len == 0)
		return (NULL);
	ret = ft_calloc_exit(len + 1, sizeof(char));
	while (i < start)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static char	*create_latter(char *str, int start, int end)
{
	int		_end;
	int		i;
	int		k;
	int		len;
	char	*ret;

	i = 0;
	k = 0;
	_end = end;
	len = 0;
	if (!str[end + 1])
		return (NULL);
	while (str[_end + 1])
	{
		len++;
		_end++;
	}
	ret = ft_calloc_exit(len + 1, sizeof(char));
	i = end + 1;
	while (str[i])
		ret[k++] = str[i++];
	ret[k] = 0;
	return (ret);
}

char	*ft_erase(char *str, int start, int end)
{
	char	*former;
	char	*latter;

	if (!str || start - end > 0 || start < 0)
		return (NULL);
	former = create_former(str, start, end);
	latter = create_latter(str, start, end);
	if (str)
		free(str);
	str = NULL;
	if (!former && !latter)
		return (NULL);
	if (!former && latter)
		return (ft_strjoin_free(former, latter, SECOND));
	if (former && !latter)
		return (ft_strjoin_free(former, latter, FIRST));
	if (former && latter)
		;
	return (ft_strjoin_free(former, latter, BOTH));
}

// int main()
// {
// 	printf("[%s]\n", ft_erase("''$''HOME $HOME", 0, 0));
// 	return (0);
// }
