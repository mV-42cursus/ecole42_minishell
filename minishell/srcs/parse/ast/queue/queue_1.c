/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongolee <jongolee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:09:04 by marvin            #+#    #+#             */
/*   Updated: 2023/10/06 15:06:52 by jongolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes_parse.h"
#include "const_macro.h"
#include "structure.h"

char	**queue_create_cmd(char *input, int *pipe_loc, \
						int pipe_cnt, char **cmd)
{
	int	rotation;
	int	data[3];
	int	i;
	int	k;

	rotation = -1;
	data[CNT] = pipe_cnt;
	cmd = ft_calloc_exit(pipe_cnt + 1 + 1, sizeof(char *));
	cmd[pipe_cnt + 1] = NULL;
	while (++rotation < pipe_cnt + 1)
	{
		k = 0;
		syntax_calculate_idx2(data, rotation, pipe_loc, input);
		cmd[rotation] = ft_calloc_exit(data[END] - data[START] + 1 + 1, \
										sizeof(char));
		i = data[START];
		while (input[i] && i <= data[END])
			cmd[rotation][k++] = input[i++];
	}
	free(input);
	return (cmd);
}

struct s_queue	*empty_pipe_error(char **input, int **pipe_loc)
{
	ft_putendl_fd("syntax error (pipeline without any command)", 2);
	g_signal = SYNTAX_ERROR;
	free(*input);
	free(*pipe_loc);
	*input = NULL;
	*pipe_loc = NULL;
	return (NULL);
}

void	queue_push(t_queue *queue, char **cmd)
{
	char	*temp;
	int		l;

	l = -1;
	temp = NULL;
	while (cmd[++l])
	{
		temp = ft_strdup(cmd[l]);
		enqueue(queue, temp);
	}
}

struct s_queue	*init_queue(char *input, int pipe_cnt)
{
	t_queue	*queue;
	int		*pipe_loc;
	char	**cmd;

	cmd = NULL;
	pipe_cnt = queue_count_pipeline(input);
	queue = ft_calloc_exit(1, sizeof(struct s_queue));
	if (pipe_cnt)
	{
		pipe_loc = ft_calloc_exit(pipe_cnt, sizeof(int));
		queue_loc_pipeline(input, pipe_loc);
		if (syntax_empty_pipeline(input, pipe_loc, pipe_cnt))
		{
			free(queue);
			return (empty_pipe_error(&input, &pipe_loc));
		}
		cmd = queue_create_cmd(input, pipe_loc, pipe_cnt, cmd);
		free(pipe_loc);
		queue_push(queue, cmd);
		free_char_double_pointer(&cmd);
	}
	else
		enqueue(queue, input);
	return (queue);
}
