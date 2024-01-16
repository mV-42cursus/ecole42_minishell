/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:39:20 by marvin            #+#    #+#             */
/*   Updated: 2023/10/10 19:11:34 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

int	g_signal = 0;

void	on_exit_signal(void)
{
	printf("\033[1A");
	printf("\033[10C");
	printf(" exit\n");
	exit(EXIT_SUCCESS);
}

int	is_input(char *input)
{
	int	is_input;

	is_input = 1;
	if (*input == 0)
	{
		free_str(&input);
		is_input = 0;
	}
	return (is_input);
}

int	is_syntax(char *input)
{
	int	is_ok;

	is_ok = 1;
	if (syntax_unclosed_quote(input) || syntax_error(input) || \
			syntax_redirection_error(input) || syntax_white_space(input) \
			|| double_dollar(input))
	{
		free_str(&input);
		g_signal = SYNTAX_ERROR;
		is_ok = 0;
	}
	return (is_ok);
}

void	minishell(char *input, t_queue *queue, t_env *env)
{
	while (1)
	{
		init_term();
		input = readline("minishell$ ");
		if (input)
		{
			add_history(input);
			add_local_history(input);
			if (!is_input(input) || !is_syntax(input))
				continue ;
			queue = init_queue(input, 0);
			if (!queue)
				continue ;
			init_ast(ft_calloc_exit(1, sizeof(t_class)), &queue, env);
			free(queue);
			queue = NULL;
			input = NULL;
		}
		else
			on_exit_signal();
	}
}

int	main(int ac, char **av, char **envp)
{
	t_queue	*queue;
	t_env	*env;
	char	*input;

	(void)ac;
	(void)av;
	input = NULL;
	queue = NULL;
	env = NULL;
	set_signal(SHE, SHE);
	env = create_environment_lst(envp);
	minishell(input, queue, env);
	return (g_signal);
}
