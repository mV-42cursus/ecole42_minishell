/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 20:16:11 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:06:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

void	set_ast(t_class *root, int *stdin, int *stdout)
{
	int		pipe_fd[2];
	int		counter;

	counter = 0;
	if (!root->r_child)
		*pipe_fd = -1;
	count_here_doc(root, &counter);
	get_here_doc(root);
	if (g_signal == SIGUSR1)
		g_signal = 1;
	else
		pre_order_execution(root, pipe_fd);
	remove_dir();
	pre_order_free(&root);
	dup2(*stdin, STDIN_FILENO);
	dup2(*stdout, STDOUT_FILENO);
	close(*stdin);
	close(*stdout);
}

void	init_ast(t_class *root, t_queue **cmd_queue, t_env *env_lst)
{
	t_queue	*queue;
	t_class	*node;
	int		stdin;
	int		stdout;

	stdin = dup(STDIN_FILENO);
	stdout = dup(STDOUT_FILENO);
	root->type = PIPELINE;
	root->l_child = NULL;
	root->r_child = NULL;
	root->envp_lst = env_lst;
	queue = ft_calloc_exit(1, sizeof(t_queue));
	enqueue(queue, root);
	while (!is_empty(&queue))
	{
		node = dequeue(queue);
		create_left_child(node, *cmd_queue, queue);
		create_right_child(node, *cmd_queue, queue, env_lst);
	}
	set_ast(root, &stdin, &stdout);
	free(queue);
	free(*cmd_queue);
	*cmd_queue = NULL;
	queue = NULL;
}
