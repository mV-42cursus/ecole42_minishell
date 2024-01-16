/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:20:12 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_size(char const *s, unsigned int start, size_t len)
{
	if (*s == '\0')
		return (0);
	if (len == 0)
		return (0);
	if (start >= ft_strlen(s))
		return (0);
	if (len > ft_strlen(s + start))
		return (ft_strlen(s + start));
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*buffer;

	size = ft_find_size(s, start, len);
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	if (size == 0)
		return (buffer);
	i = -1;
	while (++i < size)
		buffer[i] = s[start + i];
	return (buffer);
}

// #include <stdio.h>
// int main(void)
// {
// 	puts(ft_substr("hola", 2, 3));
// 	puts(ft_substr("hola", 2, 30));
// 	puts(ft_substr("hola", 3, 2));
// 	puts(ft_substr("tripouille", 0, 42000));
// 	puts(ft_substr("", 0, 0));
// 	puts("---------------------------------");
// 	puts("[ BASIC FUNCTIONALITY TEST0]");
// 	puts(ft_substr("hello world!", 1, 12));
// 	puts("-------------------------------");
// 	puts("[ BASIC FUNCTIONALITY TEST1 ]");
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	printf("[test1]\t"); puts(ft_substr(str, 400, 20));
// 	printf("[test2]\t"); puts(ft_substr(str, 0, 0));
// 	printf("[test3]\t"); puts(ft_substr(str, 7, 0));
// 	printf("[test4]\t"); puts(ft_substr(str, 7, 10));
// 	printf("[test5]\t"); puts(ft_substr(str, 0, 10));
// 	puts("\n-------------------------------");
// 	puts("[ ADVANCED FUNCTIONALITY TEST ]");
// 	char *str1= "01234";
// 	size_t size = 10;	
// 	printf("[test6]\t"); puts(ft_substr(str1, 10, size));
// 	puts("\n-------------------------------");
// 	puts("[ ADVANCED FUNCTIONALITY TEST ]");
// 	char *str2= "";
// 	size_t size1 = 10;	
// 	printf("[test6]\t"); puts(ft_substr(str2, 10, size1));
// 	return (0);
// }