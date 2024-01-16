/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:19:42 by jongohlee         #+#    #+#             */
/*   Updated: 2023/10/06 03:02:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

int	infile_red(int *fd, t_redirection *_red_lst)
{
	*fd = open(_red_lst -> argument, O_RDONLY);
	if (*fd < 0)
	{
		ft_strerror(_red_lst->argument, ERR_NO_FILE);
		return (g_signal);
	}
	else
		dup2(*fd, STDIN_FILENO);
	return (0);
}

int	append_red(int *fd, t_redirection *_red_lst)
{
	if (!check_outfile(_red_lst->argument, 0))
	{
		*fd = open(_red_lst -> argument, \
		O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (*fd < 0)
		{
			ft_strerror(_red_lst->argument, ERR_NO_FILE);
			return (g_signal);
		}
		else
			dup2(*fd, STDOUT_FILENO);
	}
	else
		return (g_signal);
	return (0);
}

int	outfile_red(int *fd, t_redirection *_red_lst)
{
	if (!check_outfile(_red_lst->argument, 0))
	{
		*fd = open(_red_lst -> argument, \
		O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (*fd < 0)
		{
			ft_strerror(_red_lst->argument, ERR_NO_FILE);
			return (g_signal);
		}
		else
			dup2(*fd, STDOUT_FILENO);
	}
	else
		return (g_signal);
	return (0);
}

int	heredoc_red(int *fd, t_redirection *_red_lst)
{
	*fd = open(_red_lst->src, O_RDONLY);
	if (*fd < 0)
	{
		ft_strerror(_red_lst->src, ERR_NO_FILE);
		return (g_signal);
	}
	else
		dup2(*fd, STDIN_FILENO);
	return (0);
}
