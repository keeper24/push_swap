/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:48:56 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:10:33 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *s)
{
	t_node	*x;
	t_node	*y;
	t_node	*z;

	if (!s || s->size < 2)
		return ;
	x = s->top;
	y = x->next;
	z = y->next;
	y->prev = NULL;
	y->next = x;
	x->prev = y;
	x->next = z;
	if (z)
		z->prev = x;
	else
		s->bottom = x;
	s->top = y;
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
