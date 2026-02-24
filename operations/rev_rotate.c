/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:58:34 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/23 22:01:17 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rev_rotate(t_stack *s)
{
	t_node *x;
	t_node *y;

	if (!s || s->size < 2)
		return ;

	y = s->bottom;
	x = y->prev;

	s->bottom = x;
	x->next = NULL;

	y->prev = NULL;
	y->next = s->top;
	s->top->prev = y;
	s->top = y;
}

void	rra(t_stack *a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}
void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
