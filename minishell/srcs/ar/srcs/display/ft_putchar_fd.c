/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:15 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:19:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// #include <stdio.h>
// int main()
// {
//     int i = 96;
//     while (++i <= 122)
//         ft_putchar_fd(i, 0);
//     i = 96;
// 	write(1, "\n", 1);
//     while (++i <= 122)
//         ft_putchar_fd(i, 1);
//     i = 96;
// 	write(1, "\n", 1);
//     while (++i <= 122)
//         ft_putchar_fd(i, 2);
// }
