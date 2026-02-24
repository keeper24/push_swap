/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:35:47 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/23 20:57:41 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack *s)
{
	t_node *x;
	t_node *y;
	t_node *b;

	if (!s || s->size < 2)
		return;
	x = s->top;
	y = x->next;
	b = s->bottom;

	s->top = y;
	y->prev = NULL;
	b->next = x;
	x->prev = b;
	x->next = NULL;
	s->bottom = x;
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1,"ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1,"rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1,"rr\n", 3);
}


