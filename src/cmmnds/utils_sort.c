/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:33:24 by antandre          #+#    #+#             */
/*   Updated: 2024/11/27 21:39:26 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_both(t_stack **a, t_stack **b, t_stack *n_cheap)
{
	while (*b != n_cheap->target && *a != n_cheap)
		rr(a, b, false);
	c_index(*a);
	c_index(*b);
}

static void	rev_rot_both(t_stack **a, t_stack **b, t_stack *n_cheap)
{
	while (*b != n_cheap->target && *a != n_cheap)
		rrr(a, b, false);
	c_index(*a);
	c_index(*b);
}

void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack *n_cheap;

	n_cheap = cheap_get(*a);
	if (n_cheap->up_media && n_cheap->target->up_media)
		rot_both(a, b, n_cheap);
	else if (!(n_cheap->up_media) && !(n_cheap->target->up_media))
		rev_rot_both(a, b, n_cheap);
	prep_push(a, n_cheap, 'a');
	prep_push(b, n_cheap->target, 'b');
	pb(b, a, false);
}

void	b_to_a(t_stack **a, t_stack **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack **a)
{
	while ((*a)->n != f_min(*a)->n)
	{
		if (f_min(*a)->up_media)
			ra(a, false);
		else
			rra(a, false);
	}
}

