/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:19:58 by marvin            #+#    #+#             */
/*   Updated: 2023/09/05 01:08:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(char *_big, char *little, size_t b_c_idx, size_t len)
{
	int	b_i;
	int	l_i;

	b_i = 0;
	l_i = 0;
	while (little[l_i])
	{
		if (little[l_i] == _big[b_i] && b_c_idx < len)
		{
			l_i++;
			b_i++;
			b_c_idx++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b_c;
	char	*l_c;
	size_t	b_c_idx;

	b_c = (char *)big;
	l_c = (char *)little;
	b_c_idx = 0;
	if (!l_c[0])
		return (b_c);
	while (b_c[b_c_idx])
	{
		if (is_valid(b_c + b_c_idx, l_c, b_c_idx, len) && (b_c_idx < len))
			return (b_c + b_c_idx);
		b_c_idx++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main()
// {
//     const char *largestring = "Foo Bar Baz";
//     const char *smallstring = "Bar";
//     char *ptr;

//     ptr = ft_strnstr(largestring, smallstring, 8);
//     printf("%s", ptr);
// }
