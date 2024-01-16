/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:08:44 by jongohlee         #+#    #+#             */
/*   Updated: 2023/10/06 03:00:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

void	ft_perror(void)
{
	perror("minishell");
	exit(EXIT_FAILURE);
}

void	err_fd_fork_pipe_dup(int i)
{
	if (i < 0)
		ft_perror();
}

void	ft_strerror_sub2(char *str, int errno)
{
	if (errno == ERR_EXIT_NO_NUM)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_signal = 255;
	}
	else if (errno == ERR_EXIT_ARG)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		g_signal = 1;
	}
}

void	ft_strerror_sub(char *str, int errno)
{
	if (errno == ERR_NAME_LONG)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": File name too long\n", 2);
		g_signal = 1;
	}
	else if (errno == ERR_IS_DIR)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Is a directory\n", 2);
		g_signal = 1;
	}
	else if (errno == ERR_MAX_HERE_DOC)
	{
		ft_putstr_fd(str, 2);
		g_signal = 2;
	}
	else if (errno == ERR_CD_DIR)
	{
		ft_putstr_fd("cd: ", 2);
		perror(str);
		g_signal = 1;
	}
	else
		ft_strerror_sub2(str, errno);
}

void	ft_strerror(char *str, int errno)
{
	ft_putstr_fd("minishell: ", 2);
	if (errno == ERR_NO_FILE)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_signal = 127;
	}
	else if (errno == ERR_NO_CMD)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": command not found\n", 2);
		g_signal = 127;
	}
	else if (errno == ERR_KEY_NAME)
	{
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd("`", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("'", 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		g_signal = 1;
	}
	else
		ft_strerror_sub(str, errno);
}
