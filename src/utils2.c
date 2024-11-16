/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:34:54 by antandre          #+#    #+#             */
/*   Updated: 2024/11/16 18:09:33 by antandre         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

void	cheap_get(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s)
	{
		if  (s->cheap)
			return (s);
		s = s->next;
	}
	return (NULL);
}


//prep_push
