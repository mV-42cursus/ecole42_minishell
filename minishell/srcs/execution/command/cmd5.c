/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:41:29 by jongohlee         #+#    #+#             */
/*   Updated: 2023/10/10 16:45:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

int	do_set(t_class *node)
{
	int		i;
	char	*key;

	i = 0;
	while (node->cmd_arr[i])
	{
		key = determine_key(node->cmd_arr[i]);
		if (check_key_name(key, node->cmd_arr[i], ERR_NO_CMD))
			return (g_signal);
		add_key_to_env(node, node->envp_lst, i, key);
		i++;
		free_str(&key);
	}
	return (0);
}

int	check_set(t_class *node)
{
	int	i;
	int	j;

	i = 0;
	while (node->cmd_arr[i])
	{
		j = 0;
		while (node->cmd_arr[i][j] && node->cmd_arr[i][j] != '=')
			j++;
		if (node->cmd_arr[i][j] == 0 || j == 0)
			return (0);
		i++;
	}
	return (do_set(node));
}

void	fork_child(t_class *node)
{
	pid_t	c;

	set_signal(DFL, DFL);
	c = fork();
	if (c == 0)
		do_execve(node, 0, 0);
	else
		set_signal(IGN, IGN);
	wait_child();
	set_signal(SHE, SHE);
}

int	do_simple_cmd(t_class *node, int *pipe_fd)
{
	if (*pipe_fd != -1)
	{
		if (!node->cmd_arr[0])
			exit(g_signal);
		if (check_set(node))
			exit(g_signal);
		if (do_built_in(node) == -1)
			do_execve(node, 0, 0);
		wait_child();
		exit(g_signal);
	}
	else if (*pipe_fd == -1)
	{
		if (check_set(node))
			return (g_signal);
		if (!node->cmd_arr[0])
		{
			g_signal = 0;
			return (g_signal);
		}
		if (do_built_in(node) == -1)
			fork_child(node);
	}
	return (g_signal);
}
