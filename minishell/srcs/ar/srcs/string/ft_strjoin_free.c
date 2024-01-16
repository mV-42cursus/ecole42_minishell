/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:19:18 by marvin            #+#    #+#             */
/*   Updated: 2023/09/28 17:58:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat_free(char **buffer, char const *s1, char const *s2)
{
	int	idx;
	int	b_idx;

	idx = -1;
	b_idx = -1;
	buffer[0][0] = '\0';
	if (s1)
		while (s1[++idx])
			buffer[0][++b_idx] = s1[idx];
	idx = -1;
	if (s2)
		while (s2[++idx])
			buffer[0][++b_idx] = s2[idx];
}

char	*ft_strjoin_free(char *s1, char *s2, int flag)
{
	char	*buffer;
	size_t	size;

	size = ft_strlen_null(s1) + ft_strlen_null(s2);
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	ft_strcat_free(&buffer, s1, s2);
	if (flag == NONE)
		return (buffer);
	if (flag == FIRST)
		free(s1);
	if (flag == SECOND)
		free(s2);
	if (flag == BOTH)
	{
		free(s1);
		free(s2);
	}
	return (buffer);
}

// int main()
// {
// 	printf("%s\n", ft_strjoin("hello ", "world!"));
// 	printf("%s\n", ft_strjoin("", ""));
// 	printf("%s\n", ft_strjoin("hello ", ""));
// }