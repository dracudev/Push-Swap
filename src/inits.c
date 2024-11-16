/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:35:36 by antandre          #+#    #+#             */
/*   Updated: 2024/11/16 19:35:37 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_target(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*n_target;
	long			i_match;

	while (a)
	{
		i_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->n < a->n
				&& current_b->n > i_match)
			{
				i_match = current_b->n;
				n_target = current_b;
			}
			current_b = current_b->next;
		}
		if (i_match == LONG_MIN)
			a->n_target = f_max(b);
		else
			a->n_target = n_target;
		a = a->next;
	}
}

static void	b_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*n_target;
	long			i_match;

	while (b)
	{
		i_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->n > b->n
				&& current_a->n < i_match)
			{
				i_match = current_a->n;
				n_target = current_a;
			}
			current_a = current_a->next;
		}
		if (i_match == LONG_MAX)
			b->n_target = f_min(a);
		else
			b->n_target = n_target;
		b = b->next;
	}
}

static void	a_cost(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_lstsize(a);
	b_len = ft_lstsize(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->up_media))
			a->cost = a_len - (a->index);
		if (a->target->up_media)
			a->cost += a->target->index;
		else
			a->cost += b_len - (a->target->index);
		a = a->next;
	}
}

void	n_init_a(t_stack *a, t_stack *b)
{
	c_index(a);
	c_index(b);
	a_target(a, b);
	a_cost(a, b);
	set_cheapest(a);
}

void	n_init_n(t_stacke *a, t_stack *b)
{
	c_index(a);
	c_index(b);
	b_target(a, b);
}
