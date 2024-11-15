/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:34:11 by antandre          #+#    #+#             */
/*   Updated: 2024/11/15 13:40:57 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_err(char *s)
{
	if (!(*s == '+' || *s == '-' || (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+' || *s == '-') && !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(*s >= '0' && s <= '9'))
			return (1);
	}
	return (0);
}

int	dup_err(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->n == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	s_free(t_stack **s)
{
	t_stack	aux;
	t_stack	current;

	if (!s)
		return ;
	current = *s;
	while (current)
	{
		aux = current->next;
		current->n = 0;
		free(current);
		current = aux;
	}
	*s = NULL;
}

void	free_err(t_stack **a)
{
	s_free(a);
	ft_printf("Error\n");
	exit (1);
}
