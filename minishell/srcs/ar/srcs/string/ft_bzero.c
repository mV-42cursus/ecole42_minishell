/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:50 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		*ptr++ = '\0';
	}
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
//     char str[50];
//     printf("---------------[original bzero]----------------------\n");
//     strcpy(str,"This is string.h library function");
//     puts(str);
//     bzero(str, 50);
//     puts(str);
//     printf("---------------[42:ft_bzero]----------------------\n");
//     strcpy(str,"This is string.h library function");
//     ft_bzero(str, 50);
//     puts(str);
//     return(0);
// }
