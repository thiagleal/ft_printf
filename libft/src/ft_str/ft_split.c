/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiqueir <tsiqueir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:36:19 by tsiqueir          #+#    #+#             */
/*   Updated: 2024/12/09 17:33:52 by tsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (count);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	ft_freesplit(char **result, int i)
{
	while (i > 0)
	{
		free(result[--i]);
	}
	free(result);
}

static int	split_help(char const *s, char c, char **result, int *i)
{
	size_t	tam;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				tam = ft_strlen(s);
			else
				tam = ft_strchr(s, c) - s;
			result[*i] = ft_substr(s, 0, tam);
			if (!result[*i])
			{
				ft_freesplit(result, *i);
				return (0);
			}
			(*i)++;
			s += tam;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	if (!split_help(s, c, result, &i))
		return (NULL);
	result[i] = NULL;
	return (result);
}
