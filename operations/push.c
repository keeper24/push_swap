/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:57:53 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/23 20:35:08 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_top(t_stack *dst, t_stack *src)
{
	t_node *x;

	if (!dst || !src || src->size == 0)
		return ;

	x = src->top;
	src->top = x->next;
	if (src->top == NULL)
		src->bottom = NULL;
	else
		src->top->prev = NULL;
	src->size--;

	x->prev = NULL;
	x->next = dst->top;
	if (dst->size != 0)
		dst->top->prev = x;
	else
		dst->bottom = x;
	dst->top = x;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push_top(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push_top(b, a);
	write(1, "pb\n", 3);
}
