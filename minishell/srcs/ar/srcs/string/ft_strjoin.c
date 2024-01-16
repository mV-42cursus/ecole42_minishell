/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:19:18 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char **buffer, char const *s1, char const *s2)
{
	int	idx;
	int	b_idx;

	idx = -1;
	b_idx = -1;
	buffer[0][0] = '\0';
	while (s1[++idx])
		buffer[0][++b_idx] = s1[idx];
	idx = -1;
	while (s2[++idx])
		buffer[0][++b_idx] = s2[idx];
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	buffer[size] = '\0';
	ft_strcat(&buffer, s1, s2);
	return (buffer);
}

// int main()
// {
// 	printf("%s\n", ft_strjoin("hello ", "world!"));
// 	printf("%s\n", ft_strjoin("", ""));
// 	printf("%s\n", ft_strjoin("hello ", ""));
// }