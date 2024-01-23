/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:56:39 by jongolee          #+#    #+#             */
/*   Updated: 2024/01/23 22:40:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

int	do_echo(t_class *node, int i, int j)
{
	char	is_n_option;

	is_n_option = 0;
	while (*node->cmd_arr && node->cmd_arr[j] && *node->cmd_arr[j] == '-')
	{
		i = 1;
		while (node->cmd_arr[j][i] == 'n')
			i++;
		if (!node->cmd_arr[j][i])
			is_n_option = 1;
		else
			break ;
		j++;
	}
	i = j;
	while (*node->cmd_arr && node->cmd_arr[i])
	{
		printf("%s", node->cmd_arr[i]);
		if (node->cmd_arr[i + 1])
			printf(" ");
		i++;
	}
	if (!is_n_option)
		printf("\n");
	return (0);
}

int	do_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	printf("%s\n", str);
	free_str(&str);
	return (0);
}

void	env_lst_update(t_class *node, t_env *env, char *cmd, char *key)
{
	if (export_value_syntax_error(cmd))
		return ;
	while (env)
	{
		if (env->key && ft_strcmp(env->key, key) == 0)
		{
			if (cmd && is_have_equal(cmd))
			{
				if (env->value)
					free_str(&env->value);
				env->value = determine_value(cmd);
				env->is_export = TRUE;
			}
			else
				env->is_export = TRUE;
			break ;
		}
		env = env->next;
	}
	if (!env)
		env_lstadd_back(&node->envp_lst, env_lstnew(cmd));
}

void	just_export(struct s_env *envp)
{
	while (envp)
	{
		if (envp->is_export && envp->key)
		{
			printf("declare -x %s", envp->key);
			if (envp->value)
				printf("=\"%s\"\n", envp->value);
			else
				printf("\n");
		}
		envp = envp -> next;
	}
}

int	do_export(t_class *node, int is_failed)
{
	struct s_env	*envp;
	int				i;
	char			*key;

	env_lst_sort(&node->envp_lst, ft_strcmp);
	envp = node->envp_lst;
	if (!node->cmd_arr[1])
		just_export(envp);
	else
	{
		i = 1;
		while (node->cmd_arr[i])
		{
			key = determine_key(node->cmd_arr[i]);
			if (!check_key_name(key, node->cmd_arr[i], ERR_KEY_NAME))
				env_lst_update(node, node->envp_lst, node->cmd_arr[i], key);
			else
				is_failed = 1;
			i++;
			free(key);
		}
	}
	if (!is_failed)
		g_signal = 0;
	return (g_signal);
}
