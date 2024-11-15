/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:31:21 by antandre          #+#    #+#             */
/*   Updated: 2024/11/14 13:20:08 by antandre         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*n_push;

	if (!*src)
		return ;
	n_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	if (!*dst)
	{
		*dst = n_push;
		n_push->next = NULL;
	}
	else
	{
		n_push->next = *dst;
		n_push->next->prev = n_push;
		*dst = n_push;
	}
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
