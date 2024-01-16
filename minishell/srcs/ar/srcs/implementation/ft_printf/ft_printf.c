/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:17:01 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:19:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list args, const char c)
{
	int	displayed;

	displayed = 0;
	if (c == 'c')
		displayed += display_character(args);
	else if (c == 's')
		displayed += display_string(args);
	else if (c == 'p')
		displayed += display_ptr_address(args);
	else if (c == 'd')
		displayed += display_digit(args);
	else if (c == 'i')
		displayed += display_digit(args);
	else if (c == 'u')
		displayed += display_decimal(args);
	else if (c == 'x')
		displayed += display_hex_small_case(args);
	else if (c == 'X')
		displayed += display_hex_capital_case(args);
	else if (c == '%')
		displayed += display_percent_sign();
	else
		displayed += 0;
	return (displayed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		res;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			res = ft_parse(args, *format);
		}
		else
			res = write(1, format, 1);
		if (res == -1)
			return (-1);
		else
			len += res;
		format++;
	}
	va_end(args);
	return (len);
}
