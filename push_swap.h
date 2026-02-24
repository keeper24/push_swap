/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:17:50 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/23 21:51:55 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
#include <stdbool.h>



typedef				struct s_node
{
	int				value;
	int				index;
	struct	s_node	*next;
	struct	s_node	*prev;
	//later cost, target, flags
}					t_node;

typedef struct	s_stack
{
	t_node		*top;
	t_node		*bottom;
	size_t		size;
}				t_stack;

/* operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b); /* push top of b to a */
void	pb(t_stack *a, t_stack *b); /* push top of a to b */

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* stack */
void		stack_init(t_stack *stack);
t_node		*node_new(int value);
void		stack_add_bottom(t_stack *stack, t_node *node);
void		stack_clear(t_stack *stack);


#endif
