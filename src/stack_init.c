/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:35:36 by antandre          #+#    #+#             */
/*   Updated: 2024/12/01 09:00:37 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

static void	n_append(t_stack **s, int n)
{
	t_stack	*node;
	t_stack	*n_last;

	if (!s)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->n = n;
	node->cheap = 0;
	if (!(*s))
	{
		*s = node;
		node->prev = NULL;
	}
	else
	{
		n_last = f_last(*s);
		n_last->next = node;
		node->prev = n_last;
	}
}

void	s_init_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_err(argv[i]))
			free_err(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_err(a);
		if (dup_err(*a, (int)n))
			free_err(a);
		n_append(a, (int)n);
		i++;
	}
}
