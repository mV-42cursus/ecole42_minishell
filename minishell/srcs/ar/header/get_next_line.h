/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:11:46 by marvin            #+#    #+#             */
/*   Updated: 2023/07/22 15:06:24 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef ULIMIT_N
#  define ULIMIT_N 49152
# endif

int		found_newline(char *buffer);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *data_line, char *buffer);
char	*concat(char *str, char *data_line, int *idx);
char	*solve(int fd, char *buffer, char *next_line, int rd_bytes);
size_t	find_size(char *data_line);
size_t	ft_strlen_gnl(const char *str);

#endif