/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:48:50 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/19 21:31:04 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void		stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}

t_node		*node_new(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void		stack_add_bottom(t_stack *stack, t_node *node)
{
	if(!stack || !node)
		return ;
	if(stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->prev = stack->bottom;
		stack->bottom->next = node;
		stack->bottom = node;
	}
	stack->size++;
}

void		stack_clear(t_stack *stack)
{
	t_node *curr;
	t_node *next;

	if (!stack)
		return ;

	curr = stack->top;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
