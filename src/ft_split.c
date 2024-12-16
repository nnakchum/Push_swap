/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnakchum <nnakchum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:45:16 by nnakchum          #+#    #+#             */
/*   Updated: 2023/10/28 22:57:30 by nnakchum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../ft_printf/ft_printf.h"
#include <limits.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sl;

	sl = ft_strlen(src);
	if (dstsize == 0)
		return (sl);
	i = 0;
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (sl);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sl;
	char	*sub;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	if (start > sl)
	{
		start = sl;
		len = 0;
	}
	else if (len >= sl - start)
		len = sl - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

static char	**ft_freetab(char **s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
		free(s2[i++]);
	free (s2);
	return (NULL);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			|| (i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	size_t	i;
	size_t	j;
	size_t	mem;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	s2 = malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!s2)
		return (NULL);
	while (s[i] && j < ft_countword(s, c))
	{
		while (s[i] == c)
			i++;
		mem = i;
		while (s[i] && s[i] != c)
			i++;
		s2[j] = ft_substr(s, mem, i - mem);
		if (s2[j++] == NULL)
			return (ft_freetab(s2));
	}
	s2[j] = NULL;
	return (s2);
}
