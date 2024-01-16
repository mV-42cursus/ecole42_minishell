/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:00:02 by jongolee          #+#    #+#             */
/*   Updated: 2023/10/10 16:41:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

char	*expand_str(char *str, t_class *node)
{
	t_dollar	*dollar_lst;
	t_dollar	*begin;
	char		*quote_lexer;

	(void)str;
	dollar_lst = NULL;
	quote_lexer = NULL;
	quote_lexer = quote_info(str, 0, REGULAR_STR, 0);
	dollar_lst = create_dollar_lst(str, quote_lexer, 0);
	begin = dollar_lst;
	free_str(&quote_lexer);
	str = heredoc_str_expansion(str, &dollar_lst, node->envp_lst);
	dollar_lst = begin;
	dollar_lstclear(&dollar_lst, &free_str);
	return (str);
}

void	get_input(int fd, t_redirection *red, t_class *node)
{
	char	*str;
	char	*join;

	while (1 && g_signal != SIGUSR1)
	{
		str = readline("> ");
		if (str == NULL)
			break ;
		if (syntax_unclosed_quote(str) || syntax_white_space(str) \
		|| double_dollar(str))
		{
			free_str(&str);
			continue ;
		}
		if (ft_strcmp(str, red->argument) == 0)
			break ;
		if (!red->contaminated)
			str = expand_str(str, node);
		join = ft_strjoin(str, "\n");
		write(fd, join, ft_strlen(join));
		free_str(&str);
		free_str(&join);
	}
	free_str(&str);
	close(fd);
}

void	make_here_doc_file(t_redirection *red, t_class *node)
{
	int		fd;
	pid_t	child;

	make_here_doc_file_sub(&fd, red);
	child = fork();
	if (child == 0)
	{
		set_signal(HEREDOC, SHE);
		get_input(fd, red, node);
		exit(EXIT_SUCCESS);
	}
	wait_heredoc();
}

int	find_here_doc(t_class *node)
{
	t_redirection	*_red;

	_red = node->redirection_lst;
	set_signal(IGN, IGN);
	while (_red && g_signal != SIGUSR1)
	{
		if (_red->type == IN_HEREDOC)
		{
			make_dir(node);
			make_here_doc_file(_red, node);
		}
		_red = _red ->next;
	}
	set_signal(SHE, SHE);
	return (0);
}

int	get_here_doc(t_class *node)
{
	if (node)
	{
		if (node->type == PIPELINE)
		{
			get_here_doc(node->l_child);
			get_here_doc(node->r_child);
		}
		else if (node->type == CMD)
			get_here_doc(node->l_child);
		else if (node->type == REDIRECTS)
			return (find_here_doc(node));
	}
	return (0);
}
