/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:44:52 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:10:33 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stack *a, char **tokens)
{
	int		i;
	int		value;
	t_node	*node;

	if (!a || !tokens || !tokens[0])
		error_exit();
	stack_init(a);
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_syntax(tokens[i]))
			error_exit();
		if (!to_int_checked(tokens[i], &value))
			error_exit();
		if (has_duplicate(a, value))
			error_exit();
		node = node_new(value);
		if (!node)
			error_exit();
		stack_add_bottom(a, node);
		i++;
	}
}
