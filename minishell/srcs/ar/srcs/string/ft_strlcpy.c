/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:19:27 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while ((len + 1 < size) && src[len])
	{
		dst[len] = src[len];
		len++;
	}
	if (size != 0)
		dst[len] = '\0';
	while (src[len])
		len++;
	return (len);
}
