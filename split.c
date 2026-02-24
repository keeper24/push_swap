/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:50:24 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:10:33 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(const char *s, char c)
{
	int		i;
	int		w_count;
	bool	in_word;

	i = 0;
	w_count = 0;
	while (s[i])
	{
		in_word = false;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			if (!in_word)
			{
				in_word = true;
				w_count++;
			}
			i++;
		}
	}
	return (w_count);
}

static char	*get_next_word(const char *s, char c, int *cur)
{
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[*cur] && s[*cur] == c)
		(*cur)++;
	while (s[*cur + len] && s[*cur + len] != c)
		len++;
	next_word = malloc(len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (s[*cur] && s[*cur] != c)
		next_word[i++] = s[(*cur)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(const char *str, char c)
{
	int		word_count;
	char	**result_arr;
	int		i;
	int		cur;

	if (!str)
		return (NULL);
	word_count = count_word(str, c);
	if (word_count <= 0)
		return (NULL);
	result_arr = malloc((word_count + 1) * sizeof(char *));
	if (!result_arr)
		return (NULL);
	i = 0;
	cur = 0;
	while (word_count > i)
	{
		result_arr[i] = get_next_word(str, c, &cur);
		if (!result_arr[i])
			return (NULL);
		i++;
	}
	result_arr[i] = NULL;
	return (result_arr);
}
