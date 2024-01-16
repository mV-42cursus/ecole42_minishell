/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:19:22 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	_dst_len;
	size_t	src_len;
	size_t	idx;

	idx = 0;
	dst_len = ft_strlen(dst);
	_dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (dst_len + 1 < size && src[idx])
	{
		dst[dst_len] = src[idx];
		dst_len++;
		idx++;
	}
	dst[dst_len] = '\0';
	if (dst_len <= size)
		return (src_len + _dst_len);
	else
		return (src_len + size);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char dest[20] = "BlockDMask";
//     char src[20] = "Hell";
// 	printf("[intput]\n");
//     printf("ft_strlcat count: %zu\n", ft_strlcat(dest, src, 15));
// 	printf("dest :%s\n", dest);
// 	char dest_2[20] = "BlockDMask";
//     char src_2[20] = "Hell";
// 	printf("[ouput]\n");
//     printf("strlcat count: %lu\n", strlcat(dest_2, src_2, 15));
// 	printf("dest_2 :%s\n", dest_2);
//     printf("\n");
// }