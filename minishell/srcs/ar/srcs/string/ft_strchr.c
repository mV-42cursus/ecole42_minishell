/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:59 by marvin            #+#    #+#             */
/*   Updated: 2023/08/30 21:33:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

// #include <stdio.h>
// int main()
// {
// 	puts("\n[ BASIC FUNTIONALITY TEST1 ] ");
// 	char *src = "bonjour";
// 	char *d1 = strchr(src, 'u');
// 	char *d2 = ft_strchr(src, 'u');
// 	puts(d1);
// 	puts(d2);
// 	printf("%p\n", d1);
// 	printf("%p\n\n", d2);

// 	puts("\n[ BASIC FUNTIONALITY TEST2 ] ");
// 	char *src4 = "bonjour";
// 	char *d1_4 = strchr(src4, 'b');
// 	char *d2_4 = ft_strchr(src4, 'b');
// 	puts(d1_4);
// 	puts(d2_4);
// 	printf("%p\n", d1_4);
// 	printf("%p\n\n", d2_4);

// 	puts("\n[ EXCEPTION TEST: int c = \'\\0\' ] case");
// 	char *src1 = "bonjour";
// 	char *d1_1 = strchr(src1, '\0');
// 	char *d2_1 = ft_strchr(src1, '\0');
// 	printf("[%s]\n", d1_1);
// 	printf("[%s]\n", d2_1);
// 	printf("%p\n", d1_1);
// 	printf("%p\n\n", d2_1);

// 	puts("\n[ c NOT FOUND CASE TEST1 ]");
// 	char *src2 = "bonjour";
// 	char *d1_2 = strchr(src2, 's');
// 	char *d2_2 = ft_strchr(src2, 's');
// 	printf("[%s]\n", d1_2);
// 	printf("[%s]\n", d2_2);
// 	printf("%p\n", d1_2);
// 	printf("%p\n\n", d2_2);

// 	puts("\n[ c NOT FOUND CASE TEST2 ]");
// 	char *src3 = "bonjour";
// 	char *d1_3 = strchr(src3 + 2, 'b');
// 	char *d2_3 = ft_strchr(src3 + 2, 'b');
// 	printf("[%s]\n", d1_3);
// 	printf("[%s]\n", d2_3);
// 	printf("%p\n", d1_3);
// 	printf("%p\n\n", d2_3);

// 	puts("\n[ FOUND \'\\0\' CASE ]");
// 	char *src5 = "";
// 	char *d1_5 = strchr(src5, '\0');
// 	char *d2_5 = ft_strchr(src5, '\0');
// 	printf("[%s]\n", d1_5);
// 	printf("[%s]\n", d2_5);
// 	printf("%p\n", d1_5);
// 	printf("%p\n\n", d2_5);

// 	puts("\n[ FOUND \'\\0\' CASE ]");
// 	printf("----->> [%c]\n", 1024);
// 	printf("----->> [%c]\n", 512);
// 	printf("----->> [%c]\n", 256);
// 	printf("----->> [%c]\n", 0);

// 	char *src6 = "teste";
// 	char *d1_6 = strchr(src6, 1024);
// 	char *d2_6 = ft_strchr(src6, 1024);
// 	printf("[%s]\n", d1_6);
// 	printf("[%s]\n", d2_6);
// 	printf("%p\n", d1_6);
// 	printf("%p\n\n", d2_6);
// }