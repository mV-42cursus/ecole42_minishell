/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:18:55 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:21:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words_quotation(char *s, char c)
{
	size_t	cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (s[i])
	{		
		if (s[i] == '\"')
		{
			quote(&i, &cnt, s, 2);
			if (!s[i])
				break ;
			i++;
		}
		if (s[i] == '\'')
		{
			quote(&i, &cnt, s, 1);
			if (!s[i])
				break ;
			i++;
		}
		delimeter(s, &i, c, &cnt);
	}
	return (cnt);
}

static size_t	ft_count_wordlen_quotation(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s[i] == '"')
	{
		if (!s[i + 1])
			return (0);
		while (s[++i] != '\"')
			;
		return (i - 1);
	}
	if (s[i] == '\'')
	{
		if (!s[i + 1])
			return (0);
		while (s[++i] != '\'')
			;
		return (i - 1);
	}
	else
		while (!(s[i] == c || s[i] == '\0'))
			i++;
	return (i);
}

static void	ft_word_cpy_quotation(char ***res, char *s, size_t word_len,
					size_t rotation)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (i < word_len)
	{
		while (s[k] == '\'' || s[k] == '\"')
			k++;
		res[0][rotation][i] = s[k++];
		i++;
	}
	res[0][rotation][i] = '\0';
}

static char	**ft_memory_manager_quotation(char **res, size_t rotation)
{
	while (rotation > 0)
	{
		rotation--;
		free(res[rotation]);
	}
	free(res);
	return (NULL);
}

char	**ft_split_quotation(char *s, char c)
{
	size_t		word_cnt;
	size_t		word_len;
	size_t		rotation;
	char		**res;

	word_cnt = ft_count_words_quotation(s, c);
	res = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!res)
		return (NULL);
	rotation = -1;
	while (++rotation < word_cnt)
	{
		while (*s == c || *s == '\0')
			s++;
		word_len = ft_count_wordlen_quotation(s, c);
		res[rotation] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (res[rotation] == NULL)
			return (ft_memory_manager_quotation(res, rotation));
		ft_word_cpy_quotation(&res, s, word_len, rotation);
		s = s + word_len;
	}
	res[rotation] = NULL;
	return (res);
}
