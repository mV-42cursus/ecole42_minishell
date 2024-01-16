/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:19:38 by marvin            #+#    #+#             */
/*   Updated: 2023/09/04 23:33:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && (unsigned char)s1[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// [fail]: your strncmp does not cast in unsigned char the diff
// [fail]: your strncmp does not work with non ascii chars
// #include <stdio.h>
// int main()
// {
// size_t x = 4;
// printf("[%d][%d]",strncmp("hello","hell",x),ft_strncmp("hello", "hell", x));
//  char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
//  char *s2 = "\x12\x02";
//  printf("[%d]", s1[1] - s2[1]);
//size_t size = 6;
//printf("[%d][%d]",strncmp(s1,s2,size),ft_strncmp(s1,s2,size));
// }
// int i1 = ((strncmp(s1,s2,size)>0)?1:((strncmp(s1,s2,size)<0)?-1:0));
// int i2 = ((ft_strncmp(s1,s2,size)>0)?1:((ft_strncmp(s1,s2,size)<0)?-1:0));
// if (i1 == i2)
//         exit(TEST_SUCCESS);
// exit(TEST_FAILED);