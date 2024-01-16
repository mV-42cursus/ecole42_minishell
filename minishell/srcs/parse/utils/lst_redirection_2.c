/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_redirection_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:56:34 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:04:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

int	determine_type(char *type)
{
	if (!ft_strcmp("<", type))
		return (IN_FILE);
	if (!ft_strcmp("<<", type))
		return (IN_HEREDOC);
	if (!ft_strcmp(">", type))
		return (OUT_FILE);
	if (!ft_strcmp(">>", type))
		return (OUT_HEREDOC);
	return (-1);
}

int	no_redirection(t_class *left_child)
{
	int	found;
	int	i;

	i = -1;
	found = 0;
	while (++i < ft_strlen(left_child->src))
		if (left_child->lexer[i] == REDIRECTION_TYPE)
			found = TRUE;
	if (found == TRUE)
		return (FALSE);
	return (TRUE);
}

char	*final_arg(char *arguments)
{
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = -1;
	while (arguments[len] && arguments[len] != ' ')
		len++;
	ret = NULL;
	ret = ft_calloc_exit(len + 1, sizeof(char));
	while (++i < len)
		ret[i] = arguments[i];
	return (ret);
}
