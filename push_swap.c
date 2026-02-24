/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:58:56 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:35:52 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_tokens(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!argv[1][0])
			error_exit();
		return (split(argv[1], ' '));
	}
	return (argv + 1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**tokens;

	if (argc < 2)
		return (1);
	tokens = get_tokens(argc, argv);
	if (!tokens || !tokens[0])
		error_exit();
	stack_init(&a);
	stack_init(&b);
	init_stack_a(&a, tokens);
	if (!is_sorted(&a))
	{
		assign_index(&a);
		if (a.size == 2)
			sa(&a);
		else
			turk_sort(&a, &b);
	}
	if (argc == 2)
		free_tokens(tokens);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
