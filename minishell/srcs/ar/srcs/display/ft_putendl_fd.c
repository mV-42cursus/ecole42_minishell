/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:20 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:19:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

// int main()
// {
// 	ft_putendl_fd("lorem ipsum dolor sit amet", 2);
// 	ft_putendl_fd("  lorem\nipsum\rdolor\tsit amet  ", 1);
// 	ft_putendl_fd("", 2);
// 	ft_putendl_fd("lorem ipsum do\0lor sit amet", 1);
// }