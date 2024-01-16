/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:11 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:20:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = str;
	while (n--)
	{
		*ptr++ = (unsigned char)c;
	}
	ptr = str;
	return (ptr);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char str[50];
//     strcpy(str,"This is string.h library function");
//     puts(str);
//     memset(str,'$',7);
//     puts(str);
//     ft_memset(str,'#', 7);
//     puts(str);
//     return(0);
// }

// #include "libft.h"

// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t			i;
// 	unsigned char	*d;
// 	unsigned char	ch;

// 	d = (unsigned char *) b;
// 	ch = (unsigned char) c;
// 	i = 0;
// 	while (i < len)
// 	{
// 		d[i] = ch;
// 		i++;
// 	}
// 	return (b);
// }
