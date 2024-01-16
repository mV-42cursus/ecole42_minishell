/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_original.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:18 by marvin            #+#    #+#             */
/*   Updated: 2023/07/31 05:10:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long long	ft_atoll(const char *nptr)
{
	long long	sign;
	long long	res;

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

int	ft_atoi_original(const char *nptr)
{
	return (ft_atoll(nptr));
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_atoi_original("\t\n\r\v\fd469 \n"));
// 	printf("%d\n", ft_atoi_original("2147483647"));
// 	printf("%d\n", ft_atoi_original("\t\n\r\v\f  469 \n"));
// 	printf("%d\n", ft_atoi_original("\e475"));
// 	printf("%d\n", ft_atoi_original("546:5"));
// 	printf("%d\n", ft_atoi_original("546:5"));
//     printf("%d\n", ft_atoi_original("2147483648"));
//     printf("%d\n", ft_atoi_original("9223372036854775807"));
//     printf("%d\n", ft_atoi_original("9223372036854775808"));
// }
