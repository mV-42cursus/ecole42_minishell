/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_execution2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:26:01 by jongohlee         #+#    #+#             */
/*   Updated: 2023/10/10 16:37:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

void	do_pipe_child(t_class *node, int *pipe_fd)
{
	if (node->r_child != 0)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	pre_order_execution(node->l_child, pipe_fd);
}

void	do_pipe_parent(t_class *node, int *pipe_fd)
{
	set_signal(IGN, IGN);
	if (node->r_child == 0)
	{
		close(STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		wait_child();
		set_signal(SHE, SHE);
	}
	else
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		pre_order_execution(node->r_child, pipe_fd);
	}
}

int	do_pipe(t_class *node, int *pipe_fd)
{
	pid_t	child;

	if (*pipe_fd == -1)
		pre_order_execution(node->l_child, pipe_fd);
	else
	{
		err_fd_fork_pipe_dup(pipe(pipe_fd));
		set_signal(DFL, DFL);
		child = fork();
		err_fd_fork_pipe_dup(child);
		if (child == 0)
			do_pipe_child(node, pipe_fd);
		else
			do_pipe_parent(node, pipe_fd);
	}	
	return (0);
}

int	do_cmd(t_class *node, int *pipe_fd)
{
	if (!pre_order_execution(node->l_child, pipe_fd))
		pre_order_execution(node->r_child, pipe_fd);
	else
	{
		if (*pipe_fd != -1)
			exit(g_signal);
	}
	return (0);
}
