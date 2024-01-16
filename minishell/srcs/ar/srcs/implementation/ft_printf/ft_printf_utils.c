/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:47 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:19:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display_character(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}

int	display_string(va_list args)
{
	char	*str;
	int		len;
	int		res;

	len = 0;
	res = 0;
	str = (char *)va_arg(args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		res = write(1, str++, 1);
		if (res == -1)
			return (-1);
		len = len + res;
	}
	return (len);
}

int	display_ptr_address(va_list args)
{
	unsigned long long	addr;
	int					len;
	int					res;

	addr = va_arg(args, unsigned long long);
	len = 0;
	res = 0;
	if (addr == 0)
		return (write(1, "0x0", 3));
	res = write(1, "0x", 2);
	if (res == -1)
		return (-1);
	else
		len += 2;
	dfs_hex(addr, &len);
	return (len);
}

int	display_digit(va_list args)
{
	int	len;
	int	num;
	int	res;

	len = 0;
	num = (int)va_arg(args, int);
	res = 0;
	res = ft_putnbr(num);
	if (res == -1)
		return (-1);
	if (num < 1)
	{
		if (num == 0)
			return (1);
		else
			len = 1;
	}
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}
