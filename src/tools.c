/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:34:54 by antandre          #+#    #+#             */
/*   Updated: 2024/11/16 12:32:33 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*f_last(t_stack *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

bool	is_sorted(t_stack *s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if (s->n > s->next->n)
			return (false);
		s = s->next;
	}
	return (true);
}

t_stack	*f_min(t_stack *s)
{
	long	min;
	t_stack	*n_min;

	if (!s)
		return (NULL);
	min = LONG_MAX;
	while (s)
	{
		if (s->n < min)
		{
			min = s->n;
			n_min = s;
		}
		s = s->next;
	}
	return (n_min);
}

t_stack	*f_max(t_stack *s)
{
	long	max;
	t_stack	*n_max;

	if (!s)
		return (NULL);
	max = LONG_MIN;
	while (s)
	{
		if (s->n > max)
		{
			max = s->n;
			n_max = s;
		}
		s = s->next;
	}
	return (n_max);
}

void	c_index(t_stack *s)
{
	int	i;
	int	media;

	i = 0;
	if (!s)
		return ;
	media = s_len(s) / 2;
	while (s)
	{
		s->index = i;
		if (i <= media)
			s->up_media = true;
		else
			s->up_media = false;
		s = s->next;
		++i;
	}
}
