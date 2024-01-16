/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:22:29 by jongolee          #+#    #+#             */
/*   Updated: 2023/10/10 20:41:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

void	add_local_history(char *input)
{
	int		fd;
	char	*str;
	char	*src;

	str = getenv("HOME");
	if (!str)
		return ;
	src = ft_strjoin(str, "/.minishell_history");
	if (access(src, O_RDONLY) < 0)
		fd = open(src, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else
		fd = open(src, O_APPEND | O_WRONLY, 0644);
	write(fd, input, ft_strlen(input));
	write(fd, "\n", 1);
	free(src);
}

void	push_equal_cmd(t_class *node, int *i)
{
	int	j;

	while (node->cmd_arr[*i])
	{
		j = 0;
		while (node->cmd_arr[*i][j] && node->cmd_arr[*i][j] != '=')
			j++;
		if (node->cmd_arr[*i][j] == 0 || j == 0)
			break ;
		(*i)++;
	}
}

void	wait_child(void)
{
	int		status;
	int		signum;
	int		i;

	i = 0;
	while (wait(&status) != -1)
	{
		if (WIFSIGNALED(status))
		{
			signum = WTERMSIG(status);
			if (signum == SIGINT && i++ == 0)
				ft_putstr_fd("\n", STDERR_FILENO);
			else if (signum == SIGQUIT && i++ == 0)
				ft_putstr_fd("Quit: 3\n", STDERR_FILENO);
			g_signal = 128 + signum;
		}
		else
			g_signal = WEXITSTATUS(status);
	}
}

void	wait_heredoc(void)
{
	int	status;

	while (wait(&status) != -1)
	{
		if (WEXITSTATUS(status) == SIGUSR1)
			g_signal = SIGUSR1;
	}
}
