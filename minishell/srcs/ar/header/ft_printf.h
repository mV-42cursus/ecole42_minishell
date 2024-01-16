/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:11:36 by marvin            #+#    #+#             */
/*   Updated: 2023/07/22 15:06:22 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putnbr(int nb);
int		display_percent_sign(void);
int		display_digit(va_list args);
int		display_string(va_list args);
int		display_decimal(va_list args);
int		ft_display_nbr(long long nbr);
int		display_character(va_list arg);
int		ft_put_decimal(unsigned int nbr);
int		display_ptr_address(va_list args);
int		ft_printf(const char *format, ...);
int		ft_parse(va_list args, const char c);
int		ft_display_decimal(unsigned int nbr);
int		display_hex_small_case(va_list args);
int		display_hex_capital_case(va_list args);
int		dfs_hex(unsigned long long addr, int *len);
int		dfs_hex_small_case(unsigned int num, int *len);
int		dfs_hex_capital_case(unsigned int num, int *len);

#endif
