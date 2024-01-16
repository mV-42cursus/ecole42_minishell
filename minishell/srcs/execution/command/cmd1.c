/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:36:14 by jongolee          #+#    #+#             */
/*   Updated: 2023/10/10 16:43:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_execution.h"
#include "const_macro.h"
#include "structure.h"

char	**set_envp(t_env *lst)
{
	t_env	*p;
	int		size;
	char	**ret;
	int		i;

	p = lst;
	size = 0;
	while (p)
	{
		size++;
		p = p->next;
	}
	ret = ft_calloc_exit(size + 1, sizeof(char *));
	i = 0;
	p = lst;
	while (i < size && p)
	{
		if (!p)
			break ;
		ret[i] = p->src;
		p = p->next;
		i++;
	}
	return (ret);
}

char	*path_value_exists(t_env *env_lst)
{
	while (env_lst)
	{
		if (env_lst->key && !ft_strcmp(env_lst->key, "PATH"))
			return (env_lst->value);
		env_lst = env_lst->next;
	}
	return (NULL);
}

char	**make_new_args(char **args, char *cmd, int size, int j)
{
	char	**result;
	int		i;

	result = 0;
	while (args[size])
		size++;
	if (size)
	{
		result = ft_calloc_exit(size + 1, sizeof(char *));
		j = 0;
		while (j <= size)
		{
			result[j] = ft_strdup(args[j]);
			j++;
		}
		result[size] = 0;
		free_str(&result[0]);
		i = 0;
		while (cmd[i])
			i++;
		while (i >= 0 && cmd[i] != '/')
			i--;
		result[0] = ft_strdup(cmd + i + 1);
	}
	return (result);
}

int	is_path(char *cmd)
{
	int	i;
	int	path_flag;

	i = 0;
	path_flag = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			path_flag = 1;
		i++;
	}
	if (i >= 1 && cmd[i - 1] == '/')
		path_flag = 0;
	return (path_flag);
}
