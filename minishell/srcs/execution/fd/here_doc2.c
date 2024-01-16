/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:06:35 by jongohlee         #+#    #+#             */
/*   Updated: 2023/10/10 18:49:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

void	here_doc_counter(t_class *node, int *count)
{
	t_redirection	*_red;

	_red = node->redirection_lst;
	while (_red)
	{
		if (_red->type == IN_HEREDOC)
		{
			(*count)++;
			if (*count == 17)
			{
				ft_strerror("maximum here-document count exceeded\n", \
				ERR_MAX_HERE_DOC);
				exit(g_signal);
			}
		}
		_red = _red ->next;
	}
}

void	count_here_doc(t_class *node, int *count)
{
	if (node)
	{
		if (node->type == PIPELINE)
		{
			count_here_doc(node->l_child, count);
			count_here_doc(node->r_child, count);
		}
		else if (node->type == CMD)
			count_here_doc(node->l_child, count);
		else if (node->type == REDIRECTS)
			here_doc_counter(node, count);
	}
}

void	make_dir(t_class *node)
{
	pid_t			child;
	char			**path;
	DIR				*dir;
	int				status;

	dir = opendir("/tmp/.shell_tmp");
	if (dir != 0)
	{
		closedir(dir);
		return ;
	}
	path = ft_calloc_exit(3, sizeof(char *));
	path[0] = "mkdir";
	path[1] = "/tmp/.shell_tmp";
	path[2] = 0;
	child = fork();
	if (child == 0)
		execve("/bin/mkdir", path, set_envp(node->envp_lst));
	wait(&status);
	free(path);
}

void	remove_dir(void)
{
	pid_t			child;
	char			**path;
	int				status;

	path = ft_calloc_exit(4, sizeof(char *));
	path[0] = "rm";
	path[1] = "-rf";
	path[2] = "/tmp/.shell_tmp";
	path[3] = 0;
	child = fork();
	if (child == 0)
		execve("/bin/rm", path, NULL);
	wait(&status);
	free(path);
	path = NULL;
}
