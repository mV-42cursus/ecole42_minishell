/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:04 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:20:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_cpy;
	unsigned char	*src_cpy;
	size_t			idx;

	dst_cpy = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	idx = 0;
	if (dst_cpy == src_cpy || len == 0)
		return (dst);
	if (dst_cpy > src_cpy)
	{
		while (len--)
			dst_cpy[len] = src_cpy[len];
		return (dst);
	}
	else
	{
		while (idx < len)
		{
			dst_cpy[idx] = src_cpy[idx];
			idx++;
		}
	}
	return (dst);
}

// #include <stdio.h>
// int main()
// {
// 	// char	src[] = "lorem ipsum dolor sit amet"; 
// 	// char	*dest; //orem ipsum doloar sit amet ->
// 	// dest = src + 1;
// 	// ft_memmove(dest, src, 8);
// 	// puts(dest);
// 	// char	src1[] = "lorem ipsum dolor sit amet";
// 	// char	*dest1;
// 	// dest1 = src1 + 1;
// 	// memmove(dest1, src1, 8);
// 	// puts(dest1);
// 	char dst[50] = "0123456789";
// 				//  23456789
// 	memmove((void *)dst, dst + 2, 8);
// 	puts("\n원본함수 결과물");
// 	puts(dst);	
// 	char dst1[50] = "0123456789";
// 	ft_memmove((void *)dst1, dst1 + 2, 8);
// 	puts("\nft 결과물");
// 	puts(dst1);		
// }