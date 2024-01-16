/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_redirection_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:55:11 by marvin            #+#    #+#             */
/*   Updated: 2023/11/29 00:54:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

void	redirection_lstadd_back(t_redirection **lst, t_redirection *new)
{
	t_redirection	*p;

	p = redirection_lstlast(*lst);
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		p = redirection_lstlast(*lst);
		p->next = new;
	}
}

t_redirection	*redirection_lstlast(t_redirection *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		return (lst);
	}
	return (NULL);
}

t_redirection	*redirection_lstnew(t_token *type, t_token *arg, \
									char *arguments, int i)
{
	t_redirection	*ptr;

	ptr = NULL;
	ptr = ft_calloc_exit(1, sizeof(t_redirection));
	ptr->type = determine_type(type[i].str);
	ptr->argument = ft_strdup(arg[i].str);
	if (ptr->type == IN_HEREDOC)
	{
		while (*arguments == ' ')
			arguments++;
		arguments = final_arg(arguments);
		if (ft_strcmp(arguments, ptr->argument) == 0)
			ptr->contaminated = FALSE;
		else
			ptr->contaminated = TRUE;
		free_str(&arguments);
	}
	ptr->next = NULL;
	return (ptr);
}

t_redirection	*create_redirection_lst(char *redirections, char *arguments)
{
	t_redirection	*lst;
	t_token			*type;
	t_token			*arg;
	char			flag;
	int				i;

	flag = REGULAR_STR;
	type = create_token_arr(redirections, ' ', flag);
	flag = REGULAR_STR;
	arg = create_token_arr(arguments, ' ', flag);
	i = -1;
	lst = NULL;
	while (++i < type->cnt)
		redirection_lstadd_back(&lst, \
								redirection_lstnew(type, arg, arguments, i));
	free_tokens(type);
	free_tokens(arg);
	return (lst);
}

t_redirection	*redirection_lst_init(t_class *left_child)
{
	t_redirection	*lst;
	char			*redirections;
	char			*arguments;
	char			*temp;

	temp = ft_strdup(left_child->parser);
	free(left_child->parser);
	left_child->parser = NULL;
	arguments = temp;
	redirections = ft_parser(left_child, REDIRECTION);
	lst = create_redirection_lst(redirections, arguments);
	left_child->parser = ft_strdup(temp);
	free(temp);
	free(redirections);
	return (lst);
}
