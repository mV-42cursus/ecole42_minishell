/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:20:02 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	not_found(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (0);
		s++;
	}
	return (1);
}

char	*ft_strrchr(const char *s, int c)
{
	long long	idx;

	if (not_found(s, c) && (char)c != '\0')
		return (0);
	idx = ft_strlen(s) - 1;
	while (s[idx] != c && idx >= 0)
	{
		if (s[idx] == (char)c)
			return ((char *)(s + idx));
		idx--;
		if (idx == -1)
			break ;
	}
	if (idx == -1)
		return ((char *)(s + ft_strlen(s)));
	return ((char *)(s + idx));
}

// #include <stdio.h>
// int main()
// {
// 	puts("\n[ BASIC FUNTIONALITY TEST1 ] ");
// 	char *src = "bonjour";
// 	char *d1 = strrchr(src, 'u');
// 	char *d2 = ft_strrchr(src, 'u');
// 	puts(d1);
// 	puts(d2);
// 	printf("%p\n", d1);
// 	printf("%p\n\n", d2);

// 	puts("\n[ BASIC FUNTIONALITY TEST2 ] ");
// 	char *src4 = "bonjour";
// 	char *d1_4 = strrchr(src4, 'b');
// 	char *d2_4 = ft_strrchr(src4, 'b');
// 	puts(d1_4);
// 	puts(d2_4);
// 	printf("%p\n", d1_4);
// 	printf("%p\n\n", d2_4);

// 	puts("\n[ EXCEPTION TEST: int c = \'\\0\' ] case");
// 	/*
// 	 	if (idx == -1)
// 	 	return ((char *)(s + ft_strlen(s)));
// 	*/
// 	char *src1 = "bonjour";
// 	char *d1_1 = strrchr(src1, '\0');
// 	char *d2_1 = ft_strrchr(src1, '\0');
// 	printf("[%s]\n", d1_1);
// 	printf("[%s]\n", d2_1);
// 	printf("%p\n", d1_1);
// 	printf("%p\n\n", d2_1);

// 	puts("\n[ c NOT FOUND CASE TEST1 ]");
// 	/*
// 		if (not_found(s, c) && (char)c != '\0')
// 		return (0);
// 	*/
// 	char *src2 = "bonjour";
// 	char *d1_2 = strrchr(src2, 's');
// 	char *d2_2 = ft_strrchr(src2, 's');
// 	printf("[%s]\n", d1_2);
// 	printf("[%s]\n", d2_2);
// 	printf("%p\n", d1_2);
// 	printf("%p\n\n", d2_2);

// 	puts("\n[ c NOT FOUND CASE TEST2 ]");
// 	/*
// 		if (not_found(s, c) && (char)c != '\0')
// 		return (0);
// 	*/
// 	char *src3 = "bonjour";
// 	char *d1_3 = strrchr(src3 + 2, 'b');
// 	char *d2_3 = ft_strrchr(src3 + 2, 'b');
// 	printf("[%s]\n", d1_3);
// 	printf("[%s]\n", d2_3);
// 	printf("%p\n", d1_3);
// 	printf("%p\n\n", d2_3);

// 	puts("[ STUDY: difference between \'\\0\' & (null) ]");
// 	puts("\0");
// 	puts("");
// 	printf("%s", NULL);
// }
