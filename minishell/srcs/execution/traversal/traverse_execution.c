/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_execution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:14:17 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:02:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

int	check_outfile(char *src, int i)
{
	DIR	*dir;

	dir = opendir(src);
	while (src[i])
	{
		if (src[i] == '/')
			break ;
		i++;
	}
	if (dir && i > 255)
	{
		ft_strerror(src, ERR_NAME_LONG);
		closedir(dir);
		return (g_signal);
	}
	else if (dir && src[i] == '/')
	{
		ft_strerror(src, ERR_IS_DIR);
		closedir(dir);
		return (g_signal);
	}
	else if (dir)
		closedir(dir);
	return (0);
}

int	do_redirect(t_class *node, int *pipe)
{
	t_redirection	*_red_lst;
	int				fd;

	(void)pipe;
	_red_lst = node->redirection_lst;
	while (_red_lst)
	{
		if (!_red_lst)
			return (0);
		if (_red_lst && _red_lst->argument)
		{
			if (_red_lst->type == IN_FILE && infile_red(&fd, _red_lst))
				return (g_signal);
			else if (_red_lst->type == OUT_HEREDOC && append_red(&fd, _red_lst))
				return (g_signal);
			else if (_red_lst->type == OUT_FILE && outfile_red(&fd, _red_lst))
				return (g_signal);
			else if (_red_lst->type == IN_HEREDOC && heredoc_red(&fd, _red_lst))
				return (g_signal);
		}
		_red_lst = _red_lst->next;
	}
	return (0);
}

int	pre_order_execution(t_class *node, int *pipe_fd)
{
	if (node)
	{
		if (node->type == PIPELINE)
			return (do_pipe(node, pipe_fd));
		else if (node->type == CMD)
			return (do_cmd(node, pipe_fd));
		else if (node->type == REDIRECTS)
			return (do_redirect(node, pipe_fd));
		else if (node->type == SIMPLE_CMD)
			return (do_simple_cmd(node, pipe_fd));
	}
	return (EXIT_FAILURE);
}
