/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:05:29 by skarayil          #+#    #+#             */
/*   Updated: 2025/06/10 13:33:25 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**malloc_free(char **arr, size_t i)
{
	while (arr[i])
		free(arr[i++]);
	return (free(arr), NULL);
}

static int	word_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	return (i);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	if (!*s)
		return (0);
	while (*s && *s++ != c)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		j;
	int		i;

	j = -1;
	i = 0;
	split = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !split)
		return (NULL);
	while (++j < word_count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		split[j] = ft_substr(s, i, word_len(&s[i], c));
		if (!split[j])
			return (malloc_free(split, 0));
		i += word_len(&s[i], c);
	}
	return (split[j] = NULL, split);
}
