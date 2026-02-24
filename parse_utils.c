/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:21:29 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:10:33 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_syntax(const char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while ((s[i]))
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	to_int_checked(const char *s, int *out)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s)
	{
		result = result * 10 + (*s - '0');
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (0);
		s++;
	}
	*out = (int)(sign * result);
	return (1);
}

int	has_duplicate(t_stack *a, int value)
{
	t_node	*cur;

	if (!a)
		return (0);
	cur = a->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
