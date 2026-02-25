/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:44:52 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/25 18:33:45 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_and_add_token(t_stack *a, const char *token)
{
	int		value;
	t_node	*node;

	if (!is_valid_syntax(token))
		return (0);
	if (!to_int_checked(token, &value))
		return (0);
	if (has_duplicate(a, value))
		return (0);
	node = node_new(value);
	if (!node)
		return (0);
	stack_add_bottom(a, node);
	return (1);
}

void	init_stack_a(t_stack *a, char **tokens)
{
	int	i;

	if (!a || !tokens || !tokens[0])
		error_exit();
	stack_init(a);
	i = 0;
	while (tokens[i])
	{
		if (!validate_and_add_token(a, tokens[i]))
		{
			stack_clear(a);
			error_exit();
		}
		i++;
	}
}
