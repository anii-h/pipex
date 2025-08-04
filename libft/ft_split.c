/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anihamba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:08:57 by anihamba          #+#    #+#             */
/*   Updated: 2025/02/20 14:05:18 by ani              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && (char)*s == c)
			s++;
		if (*s && (char)*s != c)
		{
			count++;
			while (*s && (char)*s != c)
				s++;
		}
	}
	return (count);
}

static void	to_free(char **matrix, int c)
{
	while (c >= 0)
		free(matrix[c--]);
	free(matrix);
}

static char	*split_word(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	if (len == 0)
		return (NULL);
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static char	**split_words(char const *s, char c, char **splitted)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && (char)*s == c)
			s++;
		if ((char)*s != c && *s)
		{
			splitted[i] = split_word(s, c);
			if (!splitted[i])
			{
				to_free(splitted, i - 1);
				return (NULL);
			}
			i++;
			while (*s && (char)*s != c)
				s++;
		}
	}
	splitted[i] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;

	if (!s)
		return (NULL);
	splitted = (char **)malloc(sizeof(char *) * (words(s, c) + 1));
	if (!splitted)
		return (NULL);
	return (split_words(s, c, splitted));
}
/*
#include <stdio.h>

static void print(char **words)
{
	int	j;

	j = 0;
	while(words[j])
	{
		printf("%s\n", words[j]);
		free(words[j]);
		j++;
	}
}

int	main(void)
{
	print(ft_split("ahaha, k   rfjvr udu, ooof, irf    , iru", ','));
}*/
