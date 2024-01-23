/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:41:10 by marvin            #+#    #+#             */
/*   Updated: 2024/01/23 22:41:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

void	do_absolute_path(char *cmd, char **args, char **envp)
{
	char	**new_args;
	char	*cwd;

	if (!is_path(cmd))
		return ;
	cwd = getcwd(NULL, 0);
	new_args = make_new_args(args, cmd, 0, 0);
	execve(cmd, new_args, envp);
	free_char_double_pointer(&new_args);
	free_str(&cwd);
}

void	do_execve(t_class *node, int i, int j)
{
	char	**paths;
	char	**envp;
	char	*arg;

	paths = NULL;
	reset_term();
	if (path_value_exists(node->envp_lst))
		paths = ft_split(path_value_exists(node->envp_lst), ':');
	envp = set_envp(node->envp_lst);
	push_equal_cmd(node, &i);
	if (node->cmd_arr[i])
	{
		do_absolute_path(node->cmd_arr[i], node->cmd_arr + i, envp);
		while (paths && paths[j])
		{
			arg = ft_strjoin_free(ft_strjoin(paths[j], "/"), \
			node->cmd_arr[i], FIRST);
			execve(arg, node->cmd_arr + i, envp);
			free_str(&arg);
			j++;
		}
		ft_strerror(node->cmd_arr[i], ERR_NO_CMD);
		exit(g_signal);
	}
	exit(EXIT_SUCCESS);
}

int	do_built_in(t_class *node)
{
	if (!str_cmp(node->tokens->str, "echo"))
		g_signal = do_echo(node, 1, 1);
	else if (!str_cmp(node->tokens->str, "cd"))
		g_signal = do_cd(node);
	else if (!str_cmp(node->tokens->str, "pwd"))
		g_signal = do_pwd();
	else if (!str_cmp(node->tokens->str, "export"))
		g_signal = do_export(node, 0);
	else if (!str_cmp(node->tokens->str, "unset"))
		g_signal = do_unset(node);
	else if (!str_cmp(node->tokens->str, "env"))
		g_signal = do_env(node);
	else if (!str_cmp(node->tokens->str, "exit"))
		g_signal = do_exit(node);
	else if (!str_cmp(node->tokens->str, "history"))
		g_signal = do_history();
	else
		return (-1);
	return (g_signal);
}

int	check_key_name(char *key, char *cmd, int errno)
{
	int	i;

	i = 0;
	if (!(key && key[i]))
	{
		ft_strerror(cmd, errno);
		return (1);
	}
	while (key && key[i])
	{
		if (i == 0 && !(ft_isalpha(key[i]) || key[i] == '_'))
		{
			ft_strerror(cmd, errno);
			return (1);
		}
		if (!(ft_isalnum(key[i]) || key[i] == '_'))
		{
			ft_strerror(cmd, errno);
			return (1);
		}
		i++;
	}
	return (0);
}

void	add_key_to_env(t_class *node, t_env *env, int i, char *key)
{
	while (env)
	{
		if (env->key && ft_strcmp(env->key, key) == 0)
		{
			free_str(&env->value);
			env->value = determine_value(node->cmd_arr[i]);
			break ;
		}
		env = env->next;
	}
	if (env == 0)
	{
		env = env_lstnew(node->cmd_arr[i]);
		env->is_export = FALSE;
		env_lstadd_back(&node->envp_lst, env);
	}
}
