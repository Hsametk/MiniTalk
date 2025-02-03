/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakotu <hakotu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:04:24 by hakotu            #+#    #+#             */
/*   Updated: 2024/10/21 16:27:13 by hakotu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	*allocate_word(const char *s, char c, int *j)
{
	int	start;
	int	index;

	start = *j;
	index = start;
	while (s[index] && s[index] != c)
		index++;
	*j = index;
	return (ft_substr(s, start, index - start));
}

static char	**fill_word(char **str, const char *s, char c, int w_count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < w_count)
	{
		while (s[j] && s[j] == c)
			j++;
		str[i] = allocate_word(s, c, &j);
		if (!str[i])
		{
			ft_freeall(str);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

static int	word_count(const char *s, char c)
{
	size_t	count;
	int		inside_word;

	count = 0;
	inside_word = 0;
	while (*s)
	{
		if (*s != c && inside_word == 0)
		{
			count++;
			inside_word = 1;
		}
		else if (*s == c)
			inside_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!str)
		return (NULL);
	if (!fill_word(str, s, c, w_count))
		return (NULL);
	return (str);
}
