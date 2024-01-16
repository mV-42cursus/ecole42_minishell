/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:19:31 by marvin            #+#    #+#             */
/*   Updated: 2023/09/16 18:45:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_null(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
	{
		len++;
	}
	return (len);
}
