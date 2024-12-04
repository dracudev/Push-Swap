/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:34:54 by antandre          #+#    #+#             */
/*   Updated: 2024/12/04 17:09:33 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheap_set(t_stack *s)
{
	long	v_cheap;
	t_stack	*n_cheap;

	if (!s)
		return ;
	v_cheap = LONG_MAX;
	while (s)
	{
		if (s->cost < v_cheap)
		{
			v_cheap = s->cost;
			n_cheap = s;
		}
		s = s->next;
	}
	n_cheap->cheap = true;
}

t_stack	*cheap_get(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s)
	{
		if (s->cheap)
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	prep_push(t_stack **s, t_stack *n_top, char s_name)
{
	while (*s != n_top)
	{
		if (s_name == 'a')
		{
			if (n_top->up_media)
				ra(s, false);
			else
				rra(s, false);
		}
		else if (s_name == 'b')
		{
			if (n_top->up_media)
				rb(s, false);
			else
				rrb(s, false);
		}
	}
}

int	s_len(t_stack *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s)
	{
		s = s->next;
		len++;
	}
	return (len);
}
