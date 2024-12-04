/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:33:30 by antandre          #+#    #+#             */
/*   Updated: 2024/12/05 11:33:31 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **a)
{
	t_stack	*n_big;

	n_big = f_max(*a);
	if (n_big == *a)
		ra(a, false);
	else if ((*a)->next == n_big)
		rra(a, false);
	if ((*a)->n > (*a)->next->n)
		sa(a, false);
}

void	s_sort(t_stack **a, t_stack **b)
{
	int	a_len;

	a_len = s_len(*a);
	if (a_len-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	if (a_len-- > 3 && !is_sorted(*a))
		pb(b, a, false);
	while (a_len-- > 3 && !is_sorted(*a))
	{
		n_init_a(*a, *b);
		a_to_b(a, b);
	}
	three_sort(a);
	while (*b)
	{
		n_init_b(*a, *b);
		b_to_a(a, b);
	}
	c_index(*a);
	min_on_top(a);
}
