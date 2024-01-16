/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:40 by marvin            #+#    #+#             */
/*   Updated: 2023/07/31 13:05:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = sign * (-1);
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = (10 * res) + (*nptr - '0');
		nptr++;
	}
	return ((sign) * res);
}

// #include <stdio.h>
// int main()
// {
//     printf("%d\n", ft_atoi("\t\n\r\v\fd469 \n"));
//     printf("%d\n", ft_atoi("2147483647"));
//     printf("%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
//     printf("%d\n", ft_atoi("\e475"));
//     printf("%d\n", ft_atoi("546:5"));
//     printf("%d\n", ft_atoi("546:5"));
//     printf("%d\n", ft_atoi("9223372036854775807"));
//     printf("%d\n", ft_atoi("9223372036854775808"));
// }
