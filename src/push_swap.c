/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:43:12 by antandre          #+#    #+#             */
/*   Updated: 2024/12/01 19:30:33 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_a(&a, argv + 1);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			sa(&a, false);
		else if (ft_lstsize(a) == 3)
			three_sort(&a);
		else
			s_sort(&a, &b);
	}
	s_free(&a);
	return (0);
}
