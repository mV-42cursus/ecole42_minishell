/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:27:51 by marvin            #+#    #+#             */
/*   Updated: 2024/01/23 22:39:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	free_pipe(t_class **node)
{
	pre_order_free(&((*node)->l_child));
	pre_order_free(&((*node)->r_child));
	free(*node);
	(*node) = NULL;
}

void	free_cmd(t_class **node)
{
	free_str(&((*node)->src));
	free((*node)->lexer);
	pre_order_free(&((*node)->l_child));
	pre_order_free(&((*node)->r_child));
	free(*node);
	*node = NULL;
}

void	free_redirect(t_class **node)
{
	t_redirection	*_red;

	_red = (*node)->redirection_lst;
	free_str(&((*node)->parser));
	while (_red && _red->src)
	{
		if (_red->src)
			free_str(&(_red->src));
		_red = _red->next;
	}
	if ((*node)->redirection_lst)
		redirection_lstclear(&((*node)->redirection_lst), &free_str);
	pre_order_free(&((*node)->l_child));
	pre_order_free(&((*node)->r_child));
	free(*node);
	*node = NULL;
}

void	free_simple_cmd(t_class **node)
{
	free((*node)->parser);
	free_tokens((*node)->tokens);
	free_char_double_pointer(&((*node)->cmd_arr));
	pre_order_free(&((*node)->l_child));
	pre_order_free(&((*node)->r_child));
	free(*node);
	*node = NULL;
}

void	pre_order_free(t_class **node)
{
	if (*node)
	{
		if ((*node)->type == PIPELINE)
			free_pipe(node);
		else if ((*node)->type == CMD)
			free_cmd(node);
		else if ((*node)->type == REDIRECTS)
			free_redirect(node);
		else if ((*node)->type == SIMPLE_CMD)
			free_simple_cmd(node);
	}
	*node = NULL;
}
