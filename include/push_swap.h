/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:35:19 by antandre          #+#    #+#             */
/*   Updated: 2024/11/16 12:45:22 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../lib/Libft/include/libft.h"

typedef struct s_stack
{
	int							n;
	int							index;
	int							cost;
	bool						up_media;
	bool						cheap;
	struct s_stack				*target;
	struct s_stack				*next;
	struct s_stack				*prev;
}	t_stack;

// Errors
int		syntax_err(char *s);
int		dup_err(t_stack *a, int nbr);
int		s_free(t_stack **s);
void	free_err(t_stack **a);

// Inits
void	s_init_a(t_stack **a, char **argv);
void	n_init_a(t_stack *a, t_stack *b);
void	n_init_b(t_stacke *a, t_stack *b);

// Utils
void	cheap_set(t_stack *s);
void	cheap_get(t_stack *s);
void	prep_push(t_stack **s, t_stack *n_top, char s_name);

// Tools
t_stack	*f_last(t_stack *s);
t_stack	*f_min(t_stack *s);
t_stack	*f_max(t_stack *s);
bool	is_sorted(t_stack *s);
void	c_index(t_stack *s);

// Operations
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack *bb, bool print);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

// Algorithm
void	a_to_b(t_stack **a, t_stack **b);
void	b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);

#endif
