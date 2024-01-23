/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:41:03 by marvin            #+#    #+#             */
/*   Updated: 2024/01/23 22:41:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

int	update_pwd(t_class *node)
{
	int		i;
	char	*str;
	char	*pwd;

	i = chdir(node->cmd_arr[1]);
	if (i != 0)
		return (i);
	pwd = getcwd(NULL, 0);
	str = ft_strjoin("PWD=", pwd);
	env_lst_update(node, node->envp_lst, str, "PWD");
	free_str(&str);
	free_str(&pwd);
	return (0);
}

int	do_cd(t_class *node)
{
	if (node->cmd_arr && node->cmd_arr[0] && node->cmd_arr[1])
	{
		if (ft_strcmp(node->cmd_arr[1], "~") == 0)
		{
			if (chdir(getenv("HOME")))
			{
				ft_strerror(node->cmd_arr[1], ERR_CD_DIR);
				return (g_signal);
			}
		}
		else if (update_pwd(node))
		{
			ft_strerror(node->cmd_arr[1], ERR_CD_DIR);
			return (g_signal);
		}
	}
	return (0);
}

void	unset_env_lst_sub(t_env	*now, char *key)
{
	t_env	*rear;

	while (now && now->next)
	{
		if (ft_strcmp(now->next->key, key) == 0)
		{
			rear = now->next->next;
			free_str(&now->next->src);
			free_str(&now->next->key);
			if (now->next->value)
				free_str(&now->next->value);
			free(now->next);
			now->next = rear;
			return ;
		}
		now = now->next;
	}
}

void	unset_env_lst(t_class *node, char *key)
{
	t_env	*now;

	now = node->envp_lst;
	if (now && now->key && ft_strcmp(now->key, key) == 0)
	{
		if (now->src)
			free_str(&now->src);
		if (now->key)
			free_str(&now->key);
		if (now->value)
			free_str(&now->value);
		return ;
	}
	unset_env_lst_sub(now, key);
}

int	do_unset(t_class *node)
{
	int	i;
	int	is_failed;

	i = 1;
	is_failed = 0;
	while (node->cmd_arr[i])
	{
		if (!check_key_name(node->cmd_arr[i], node->cmd_arr[i], ERR_KEY_NAME))
			unset_env_lst(node, node->cmd_arr[i]);
		else
			is_failed = 1;
		i++;
	}
	if (!is_failed)
		g_signal = 0;
	return (g_signal);
}
