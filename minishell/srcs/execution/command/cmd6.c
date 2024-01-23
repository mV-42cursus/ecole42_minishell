/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 22:41:19 by marvin            #+#    #+#             */
/*   Updated: 2024/01/23 22:41:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

int	do_env(t_class *node)
{
	t_env	*env;

	env = node->envp_lst;
	while (env)
	{
		if (env->is_export && env->value)
			printf("%s=%s\n", env->key, env->value);
		env = env -> next;
	}
	return (0);
}

int	do_history(void)
{
	int		fd;
	char	*str;
	char	*src;
	char	*line;
	int		i;

	str = getenv("HOME");
	src = ft_strjoin(str, "/.minishell_history");
	if (access(src, O_RDONLY) < 0)
		return (0);
	else
		fd = open(src, O_RDONLY);
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("  %d  %s", i, line);
		i++;
		free_str(&line);
	}
	free_str(&src);
	return (0);
}

void	check_exit(t_class *node, int i)
{
	int	j;

	j = 0;
	while (node->cmd_arr[i] && node->cmd_arr[i][j])
	{
		if (j == 0 && node->cmd_arr[i][j] == '-')
			j++;
		if (node->cmd_arr[i][j] < '0' || node->cmd_arr[i][j] > '9')
		{
			ft_strerror(node->cmd_arr[i], ERR_EXIT_NO_NUM);
			g_signal = 255;
			exit(g_signal);
		}
		j++;
	}
}

int	do_exit(t_class *node)
{
	int	i;

	i = 1;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	while (node->cmd_arr[i])
	{
		if (i == 2)
		{
			ft_strerror(node->cmd_arr[i], ERR_EXIT_ARG);
			g_signal = 1;
			return (g_signal);
		}
		check_exit(node, i);
		g_signal = (char)ft_atoi(node->cmd_arr[i]);
		i++;
	}
	exit(g_signal);
	return (EXIT_FAILURE);
}
