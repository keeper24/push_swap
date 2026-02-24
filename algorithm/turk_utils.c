/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:00:00 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:25:33 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_cheapest(t_stack *b)
{
	t_node	*current;
	t_node	*cheapest;

	current = b->top;
	cheapest = current;
	while (current)
	{
		if (current->cost_total < cheapest->cost_total)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
