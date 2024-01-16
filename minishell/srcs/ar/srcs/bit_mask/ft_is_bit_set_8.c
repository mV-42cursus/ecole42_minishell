/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bit_set_8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:14:59 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:18:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_bit_set_8(unsigned char variable, int bit_position)
{
	unsigned char	bitmask;
	unsigned char	result;

	bitmask = 1 << bit_position;
	result = variable & bitmask;
	return (result != 0);
}
