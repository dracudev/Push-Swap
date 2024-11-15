/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:31:32 by antandre          #+#    #+#             */
/*   Updated: 2024/11/15 13:07:40 by antandre         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void	rev_rot(t_stack **s)
{
	t_stack last;

	if (!*s || !(*s)->next)
		return ;
	last = f_last(*s);
	last->prev->next = NULL;
	last->next = *s;
	last->prev = NULL;
	*s = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool print)
{
	rev_rot(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print)
{
	rev_rot(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rev_rot(a);
	rev_rot(b);
	if (!print)
		ft_printf("rrr\n");
}
