/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 19:00:00 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:25:33 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min_index_node(t_stack *stack);
t_node	*find_cheapest(t_stack *b);
void	calculate_costs(t_stack *a, t_stack *b);
void	execute_rotations(t_stack *a, t_stack *b, t_node *cheapest);

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->bottom->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	turk_sort(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		calculate_costs(a, b);
		cheapest = find_cheapest(b);
		execute_rotations(a, b, cheapest);
		pa(a, b);
	}
	while (a->top->index != 0)
		ra(a);
}
