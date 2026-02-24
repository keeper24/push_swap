/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekaraca <reaphenn@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:17:50 by mekaraca          #+#    #+#             */
/*   Updated: 2026/02/24 19:25:33 by mekaraca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>



typedef				struct s_node
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	int				cost_total;
	int				target;
	struct	s_node	*next;
	struct	s_node	*prev;
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
int			is_sorted(t_stack *a);

/* utils */
char **split(const char *str, char c);
int is_valid_syntax(const char *s);
int to_int_checked(const char *s, int *out);
int  has_duplicate(t_stack *a, int value);
void free_tokens(char **tokens);
void error_exit(void);

void init_stack_a(t_stack *a, char **tokens);
void assign_index(t_stack *a);

/* turk algorithm */
void	turk_sort(t_stack *a, t_stack *b);
int	get_rotation_cost(t_stack *stack, t_node *target);
int	find_target_in_a(t_stack *a, int value);
int	get_position_by_index(t_stack *stack, int index);

#endif
