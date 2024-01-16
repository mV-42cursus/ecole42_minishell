/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:57 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:19:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long long	nbr;
	int			res;

	nbr = (long long)nb;
	res = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		res = write(1, "-", 1);
		if (res == -1)
			return (-1);
	}
	if (nbr > 9)
	{
		res = ft_putnbr(nbr / 10);
		if (res == -1)
			return (-1);
	}
	res = ft_display_nbr(nbr % 10);
	if (res == -1)
		return (-1);
	return (1);
}
