/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:55:25 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 03:04:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	left_child_pipeline(t_queue *cmd_queue, t_class *node, t_queue *queue)
{
	t_class	*left_child;
	char	*quote_lexer;
	int		removed;

	removed = 0;
	left_child = ft_calloc_exit(1, sizeof(t_class));
	left_child->l_child = NULL;
	left_child->r_child = NULL;
	left_child->type = CMD;
	left_child->src = dequeue(cmd_queue);
	quote_lexer = quote_info(left_child->src, 0, REGULAR_STR, 0);
	left_child->src = dollar_removal(left_child->src, -1, &quote_lexer, \
									&removed);
	free_str(&quote_lexer);
	left_child->lexer = idx_info(left_child->src);
	left_child->envp_lst = node->envp_lst;
	node->l_child = left_child;
	enqueue(queue, left_child);
}

void	left_child_cmd(t_queue *cmd_queue, t_class *node, t_queue *queue)
{
	t_class		*left_child;
	t_dollar	*dollar_lst;
	char		*quote_lexer;

	(void)cmd_queue;
	left_child = ft_calloc_exit(1, sizeof(t_class));
	left_child->src = node->src;
	left_child->type = REDIRECTS;
	left_child->lexer = node->lexer;
	left_child->redirection_lst = NULL;
	left_child->parser = ft_parser(left_child, ARGUMENT);
	quote_lexer = quote_info(left_child->parser, 0, REGULAR_STR, 0);
	left_child->envp_lst = node->envp_lst;
	dollar_lst = NULL;
	if (!no_redirection(left_child))
	{
		left_child->redirection_lst = redirection_lst_init(left_child);
		dollar_lst = create_dollar_lst(left_child->parser, quote_lexer, 0);
		redirection_expansion(left_child->redirection_lst, \
								dollar_lst, left_child->envp_lst);
		dollar_lstclear(&dollar_lst, &free_str);
	}
	free_str(&quote_lexer);
	node->l_child = left_child;
	enqueue(queue, left_child);
}

void	create_left_child(t_class *node, t_queue *cmd_queue, t_queue *queue)
{
	if (node->type == PIPELINE)
		left_child_pipeline(cmd_queue, node, queue);
	if (node->type == CMD)
		left_child_cmd(cmd_queue, node, queue);
	if (node->type == REDIRECTS)
	{
		node->l_child = NULL;
		node->r_child = NULL;
	}
}
