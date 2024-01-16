/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:19:34 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	idx;
	char			*buffer;

	buffer = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!buffer)
		return (NULL);
	buffer[ft_strlen(s)] = '\0';
	idx = -1;
	while (s[++idx])
		buffer[idx] = f(idx, s[idx]);
	return (buffer);
}
