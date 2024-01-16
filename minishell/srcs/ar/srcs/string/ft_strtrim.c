/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:20:07 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	find_trim_size(char const *s1, char const *set)
{
	size_t		size;

	size = 0;
	while (is_set(*s1, set))
	{
		size++;
		s1++;
	}
	while (*s1)
		s1++;
	s1--;
	while (is_set(*s1, set))
	{
		size++;
		s1--;
	}
	return (size);
}

static void	ft_create_buffer(char **buffer, char const *s1, char const *set)
{
	size_t	i;
	size_t	buffer_i;
	size_t	last_i;

	i = 0;
	buffer_i = 0;
	last_i = 0;
	while (s1[last_i])
		last_i++;
	last_i--;
	while (is_set(s1[last_i], set))
		last_i--;
	while (is_set(s1[i], set))
		i++;
	while (i < last_i + 1)
	{
		buffer[0][buffer_i] = s1[i];
		buffer_i++;
		i++;
	}
	buffer[0][buffer_i] = '\0';
}

static int	is_all_set(char const *s1, char const *set)
{
	while (*s1)
	{
		if (!is_set(*s1, set))
			return (0);
		s1++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buffer;
	size_t	str_size;
	size_t	trim_size;
	size_t	buffer_size;

	if (is_all_set(s1, set))
	{
		buffer_size = 0;
		buffer = (char *)malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	else
	{
		str_size = ft_strlen(s1);
		trim_size = find_trim_size(s1, set);
		buffer_size = str_size - trim_size;
		buffer = (char *)malloc(sizeof(char) * (buffer_size + 1));
		if (!buffer)
			return (NULL);
		ft_create_buffer(&buffer, s1, set);
	}
	return (buffer);
}

// int main()
// {
// 	printf("%s\n", ft_strtrim(" t\nHello \tPlease\n Trim me !\n ", " \n\t"));
// }