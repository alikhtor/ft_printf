/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:31:28 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/22 17:04:37 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count_words(const char *s, char c)
{
	size_t		words;

	words = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

static char		*ft_make_word(const char *s, char c)
{
	char		*word;
	size_t		word_len;

	word_len = 0;
	while (s[word_len] != c && *s)
		word_len++;
	if (!(word = (char*)malloc(sizeof(char) * (word_len + 1))))
		return (NULL);
	word_len = 0;
	while (s[word_len] != c && *s)
	{
		word[word_len] = s[word_len];
		word_len++;
	}
	word[word_len] = '\0';
	return (word);
}

static char		**ft_res_del(char **res, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
		free(res[i]);
	free(res);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**res;
	size_t		i;

	if (!s)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			res[i] = ft_make_word(s, c);
			if (res[i] == NULL)
				return (ft_res_del(res, i));
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	res[i] = NULL;
	return (res);
}
