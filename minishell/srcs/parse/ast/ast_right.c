/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:55:13 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 14:12:04 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	right_child_pipeline(t_queue *cmd_queue, t_class *node, \
							t_queue *queue, t_env *env_lst)
{
	t_class	*right_child;

	if (cmd_queue->front)
	{
		right_child = ft_calloc_exit(1, sizeof(t_class));
		right_child->l_child = NULL;
		right_child->r_child = NULL;
		right_child->type = PIPELINE;
		right_child->envp_lst = env_lst;
		node->r_child = right_child;
		enqueue(queue, right_child);
	}
}

void	right_child_cmd(t_queue *cmd_queue, t_class *node, t_queue *queue)
{
	t_class		*right_child;
	t_dollar	*dollar_lst;
	char		*quote_lexer;

	(void)cmd_queue;
	dollar_lst = NULL;
	right_child = ft_calloc_exit(1, sizeof(t_class));
	right_child->l_child = NULL;
	right_child->r_child = NULL;
	right_child->src = node->src;
	right_child->type = SIMPLE_CMD;
	right_child->envp_lst = node->envp_lst;
	right_child->lexer = node->lexer;
	right_child->parser = ft_parser(right_child, COMMAND);
	quote_lexer = quote_info(right_child->parser, 0, REGULAR_STR, 0);
	dollar_lst = create_dollar_lst(right_child->parser, quote_lexer, 0);
	right_child->tokens = create_token_arr(right_child->parser, ' ', \
											REGULAR_STR);
	right_child->envp_lst = node->envp_lst;
	right_child->cmd_arr = cmd_expansion(right_child->tokens, dollar_lst, \
											right_child->envp_lst);
	free_str(&quote_lexer);
	dollar_lstclear(&dollar_lst, &free_str);
	node->r_child = right_child;
	enqueue(queue, right_child);
}

void	create_right_child(t_class *node, t_queue *cmd_queue, \
							t_queue *queue, t_env *env)
{
	if (node->type == PIPELINE)
		right_child_pipeline(cmd_queue, node, queue, env);
	if (node->type == CMD)
		right_child_cmd(cmd_queue, node, queue);
	if (node->type == REDIRECTS)
	{
		node->l_child = NULL;
		node->r_child = NULL;
	}
}
