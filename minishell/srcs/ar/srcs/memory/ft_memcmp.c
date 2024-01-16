/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:17:54 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:20:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (n != 0)
	{
		p1 = s1;
		p2 = s2;
		while (n)
		{
			if (*p1 != *p2)
				return (*p1 - *p2);
			p1++;
			p2++;
			n--;
		}
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 0), 
//                               ft_memcmp("teste", "testex", 0));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 1), 
//                               ft_memcmp("teste", "testex", 1));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 2), 
//                               ft_memcmp("teste", "testex", 2));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 3), 
//                               ft_memcmp("teste", "testex", 3));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 4), 
//                               ft_memcmp("teste", "testex", 4));
//     printf("[%d] <-> [%d]\n", memcmp("teste", "testex", 5), 
//                             ft_memcmp("teste", "testex", 5));
//     printf("[%d] <-> [%d]\n", memcmp("testexaa", "testeax", 6), 
//                               ft_memcmp("testexaa", "testeax", 6));
//     printf("[%d] <-> [%d]\n", memcmp("atestexaa", "etesteax", 6), 
//                               ft_memcmp("atestexaa", "etesteax", 6));
// }
