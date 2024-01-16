/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:17:59 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:20:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	i = 0;
	if (dest == src || n == 0)
		return (dest);
	while (n-- > 0)
	{
		*dest_cpy++ = *src_cpy++;
		i++;
	}
	dest_cpy = dest_cpy - i;
	return ((void *)dest);
}
