/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:45:00 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:25:33 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotation_cost(t_stack *stack, t_node *target)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->top;
	while (current && current != target)
	{
		i++;
		current = current->next;
	}
	if (i > (int)stack->size / 2)
		return (i - (int)stack->size);
	return (i);
}

int	find_target_in_a(t_stack *a, int value)
{
	t_node	*current;
	int		target_index;
	int		min_index;

	min_index = INT_MAX;
	target_index = INT_MAX;
	current = a->top;
	while (current)
	{
		if (current->index > value && current->index < target_index)
			target_index = current->index;
		if (current->index < min_index)
			min_index = current->index;
		current = current->next;
	}
	if (target_index == INT_MAX)
		return (min_index);
	return (target_index);
}

int	get_position_by_index(t_stack *stack, int index)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->top;
	while (current)
	{
		if (current->index == index)
			return (i);
		i++;
		current = current->next;
	}
	return (0);
}

static void	set_node_cost(t_node *b_node)
{
	b_node->cost_total = abs(b_node->cost_b) + abs(b_node->cost_a);
	if ((b_node->cost_b > 0 && b_node->cost_a > 0)
		|| (b_node->cost_b < 0 && b_node->cost_a < 0))
	{
		if (abs(b_node->cost_b) > abs(b_node->cost_a))
			b_node->cost_total = abs(b_node->cost_b);
		else
			b_node->cost_total = abs(b_node->cost_a);
	}
}

void	calculate_costs(t_stack *a, t_stack *b)
{
	t_node	*b_node;
	int		target_index;
	int		target_pos;

	b_node = b->top;
	while (b_node)
	{
		b_node->cost_b = get_rotation_cost(b, b_node);
		target_index = find_target_in_a(a, b_node->index);
		target_pos = get_position_by_index(a, target_index);
		b_node->target = target_index;
		b_node->cost_a = target_pos;
		if (target_pos > (int)a->size / 2)
			b_node->cost_a = target_pos - (int)a->size;
		set_node_cost(b_node);
		b_node = b_node->next;
	}
}
