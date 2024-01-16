/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:16:42 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:19:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dfs_hex(unsigned long long addr, int *len)
{
	int	res;

	res = 0;
	if (addr == 0)
		return (0);
	else
	{
		dfs_hex(addr / 16, len);
		res = write(1, &"0123456789abcdef"[(addr) % 16], 1);
		if (res == -1)
			return (-1);
		*len = *len + 1;
	}
	if (res == -1)
		return (-1);
	return (1);
}

int	dfs_hex_small_case(unsigned int num, int *len)
{
	int	res;

	res = 0;
	if (num == 0 && *len != 0)
		return (1);
	else
	{
		*len = *len + 1;
		res = dfs_hex_small_case(num / 16, len);
		if (res == -1)
			return (-1);
		res = write(1, &"0123456789abcdef"[(num) % 16], 1);
		if (res == -1)
			return (-1);
	}
	return (1);
}

int	display_hex_small_case(va_list args)
{
	unsigned int	num;
	int				len;
	int				res;

	len = 0;
	num = (unsigned int)va_arg(args, unsigned int);
	res = dfs_hex_small_case(num, &len);
	if (res == -1)
		return (-1);
	return (len);
}

int	dfs_hex_capital_case(unsigned int num, int *len)
{
	int	res;

	res = 0;
	if (num == 0 && *len != 0)
		return (1);
	else
	{
		*len = *len + 1;
		res = dfs_hex_capital_case(num / 16, len);
		if (res == -1)
			return (-1);
		res = write(1, &"0123456789ABCDEF"[(num) % 16], 1);
		if (res == -1)
			return (-1);
	}
	return (1);
}

int	display_hex_capital_case(va_list args)
{
	unsigned int	num;
	int				len;
	int				res;

	len = 0;
	num = (unsigned int)va_arg(args, unsigned int);
	res = dfs_hex_capital_case(num, &len);
	if (res == -1)
		return (-1);
	return (len);
}
