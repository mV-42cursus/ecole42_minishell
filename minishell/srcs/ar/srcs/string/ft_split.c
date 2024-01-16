/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:55 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static size_t	ft_count_wordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (!(s[i] == c || s[i] == '\0'))
		i++;
	return (i);
}

static void	ft_word_cpy(char ***res, char const *s, size_t word_len,
					size_t rotation)
{
	size_t	i;

	i = 0;
	while (i < word_len)
	{
		res[0][rotation][i] = s[i];
		i++;
	}
	res[0][rotation][i] = '\0';
}

static char	**ft_memory_manager(char **res, size_t rotation)
{
	while (rotation > 0)
	{
		rotation--;
		free(res[rotation]);
	}
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		word_cnt;
	size_t		word_len;
	size_t		rotation;
	char		**res;

	word_cnt = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (NULL);
	rotation = -1;
	while (++rotation < word_cnt)
	{
		while (*s == c || *s == '\0')
			s++;
		word_len = ft_count_wordlen(s, c);
		res[rotation] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (res[rotation] == NULL)
			return (ft_memory_manager(res, rotation));
		ft_word_cpy(&res, s, word_len, rotation);
		s = s + word_len;
	}
	res[rotation] = NULL;
	return (res);
}

// paco -s -> ("hello!", ' '); check for this later
// +norm
// #include <stdio.h>
// int main()
// {
// 	size_t idx = 0;
// 	char **res;
// 	res = ft_split("hello!", ' ');
// 	while (res[idx])
// 	{
// 		printf("[%s]\n", res[idx]);
// 		idx++;
// 	}
// }
/*
		// printf("%s\n", s);
		// printf("%zu\n", word_len);
		// printf("\n");
		res[rotation] = (char *)malloc(sizeof(char) * (word_len + 1));
		ft_word_cpy(&res[rotation], s, word_len);
		s = s + word_len;
		// puts("-------------------------------------------");
		puts(res[rotation]);
		// puts("-------------------------------------------");
*/