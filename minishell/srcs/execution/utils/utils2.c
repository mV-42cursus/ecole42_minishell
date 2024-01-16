/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:52:29 by jongohlee         #+#    #+#             */
/*   Updated: 2023/10/06 03:00:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

int	str_cmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)*s1 - (int)*s2);
}

int	is_have_equal(char *cmd)
{
	int	j;

	j = 0;
	while (cmd[j] && cmd[j] != '=')
		j++;
	if (cmd[j] == 0)
		return (0);
	return (1);
}
