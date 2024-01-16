/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:25 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:43:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dfs(int nb, int fd)
{
	int	rem;

	rem = 0;
	if (nb < 10)
	{
		rem = nb + '0';
		write(fd, &rem, 1);
	}
	else
	{
		rem = (nb % 10) + '0';
		dfs(nb / 10, fd);
		write(fd, &rem, 1);
	}
}

static void	ft_putnbr(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * (-1);
	}
	dfs(nb, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}

// #include <stdio.h>
// int main()
// {
// 	ft_putnbr_fd(-2147483648, 0); printf("\n");
// 	ft_putnbr_fd(-2147483648, 1); printf("\n");
// 	ft_putnbr_fd(-2147483648, 2); printf("\n");
// 	ft_putnbr_fd(0, 0); printf("\n");
// 	ft_putnbr_fd(0, 1); printf("\n");
// 	ft_putnbr_fd(0, 2); printf("\n");
// 	ft_putnbr_fd(2147483647, 0); printf("\n");
// 	ft_putnbr_fd(2147483647, 1); printf("\n");
// 	ft_putnbr_fd(2147483647, 2); printf("\n");
// }