/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:17:50 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:20:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_cpy;
	size_t	loc;

	loc = 0;
	s_cpy = (char *)s;
	while (loc < n)
	{
		if (s_cpy[loc] == (char)c)
			return ((void *)(s_cpy + loc));
		loc++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <unistd.h>
// int main()
// {
// 	puts("\n[BASIC TEST]\n");
// 	printf("[%p] : (%s)\n", ft_memchr("bonjour", 's', 7), 
//                             (char *)ft_memchr("bonjour", 's', 7));
// 	printf("[%p] : (%s)\n", ft_memchr("bonjour", 'j', 6), 
//                             (char *)ft_memchr("bonjour", 'j', 6));
// 	printf("[%p] : (%s)\n", ft_memchr("bonjour", 'n', 2), 
//                             (char *)ft_memchr("bonjour", 'n', 2));
// 	printf("[%p] : (%s)\n", ft_memchr("bonjour", 'o', 7), 
//                             (char *)ft_memchr("bonjour", 'o', 7));
// 	printf("[%p] : (%s)\n", ft_memchr("bonjour", 'b', 4), 
//                             (char *)ft_memchr("bonjour", 'b', 4));
// 	puts("");

// 	puts("\n\n[ADVANCED TEST]\n");
// 	char s[] = {0, 1, 102 ,97 ,4 ,5, -1};
// 	printf("[%p] : (%s)\n", ft_memchr(s, -1, 1), 
//                             (char *)ft_memchr(s, -1, 1));
// 	printf("[%p] : (%s)\n", ft_memchr(s, 0, 1), 
//                             (char *)ft_memchr(s, 0, 1));
// 	printf("[%p] : (%s)\n", ft_memchr(s, 102, 3), 
//                             (char *)ft_memchr(s, 102, 3));
// 	printf("[%p] : (%s)\n", ft_memchr(s, 2 + 256, 3), 
//                             (char *)ft_memchr(s, 2 + 256, 3));
// 	puts("");

//     puts("\n\n[KEY TAKEAWAY]\n");
//     printf("255 + 1 == 1 == \'\\0\'\n");
//     printf("(%c)\n", 2);
//     printf("(%c)\n", 2 + 256);
//     printf("(%c)\n", 1);
//     printf("(%c)\n", 255);
//     printf("(%c)\n", 256);
//     char c;
//     int i = -1;
//     c = 0;
//     while (++i <= 256)
//     {
//         c = c + i;
//         write(1, &c , 1);
//         write(1, "\n", 1);
//     }
//     printf("%d\n", i);
//     puts("");
// }
// /*

//     If you want to store 0 to 255 in one byte, use “unsigned char”. 
//     If you want to store -128 to 127 in one byte, used “signed char”. 
//     If you want to store a string, use “array of char”.
// */
