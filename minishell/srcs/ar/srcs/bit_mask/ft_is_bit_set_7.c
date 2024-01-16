/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bit_set_7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:17:06 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:18:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_bit_set_7(char variable, int bit_position)
{
	char	bitmask;
	char	result;

	bitmask = 1 << bit_position;
	result = variable & bitmask;
	return (result != 0);
}

// #include <stdio.h>
// int main()
// {
// 	unsigned char bit;

// 	bit = 0;
// 	printf("%d\n", bit);
// 	bit |= (1 << 0);
// 	printf("%d\n", bit);
// 	bit |= (1 << 1);
// 	printf("%d\n", bit);
// 	bit |= (1 << 2);
// 	printf("%d\n", bit);
// 	bit |= (1 << 3);
// 	printf("%d\n", bit);
// 	bit |= (1 << 4);
// 	printf("%d\n", bit);
// 	bit |= (1 << 5);
// 	printf("%d\n", bit);
// 	bit |= (1 << 6);
// 	printf("%d\n", bit);
// 	bit |= (1 << 7);
// 	printf("value of current bit %d\n", bit);

// 	printf("%d\n", ft_is_bit_set_7(bit, 6));
// 	return (0);
// }
