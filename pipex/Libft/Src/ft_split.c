/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:22:57 by itrueba-          #+#    #+#             */
/*   Updated: 2023/05/06 14:12:03 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	ft_count_size(char *s, char c)
{
	int	count;
	int	trigger;
	int	mark;

	count = 0;
	trigger = 0;
	mark = 0;
	while (*s)
	{
		if (*s == '\'')
			mark = !mark;
		if (*s != c && trigger == 0 && !mark)
		{
			trigger = 1;
			count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static int	ft_size_word(char *s, char c, int *real_start)
{
	int	end;
	int	start;
	int	mark;

	end = 0;
	mark = 0;
	if (s[*real_start] == '\'')
	{
		mark = !mark;
		*real_start += 1;
	}
	start = *real_start;
	while ((s[start] != c || mark) && s[start])
	{
		end++;
		start += 1;
		if (s[start] == '\'')
		{
			mark = !mark;
			end--;
		}
	}
	return (end);
}

static char	**ft_free(char **split, size_t word)
{
	while (word > 0)
	{
		--word;
		free(split[word]);
	}
	free(split);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	size_t	n_word;
	size_t	word;
	int		start;
	int		end;

	n_word = ft_count_size(s, c);
	split = (char **)malloc((n_word + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	word = -1;
	start = 0;
	while (++word < n_word)
	{
		while (s[start] == c)
			start++;
		end = ft_size_word(s, c, &start);
		split[word] = ft_substr(s, start, end);
		if (!split[word])
			return (ft_free(split, word));
		start = start + end;
	}
	split[word] = 0;
	return (split);
}
