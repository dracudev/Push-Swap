/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:43:12 by antandre          #+#    #+#             */
/*   Updated: 2024/11/13 15:30:33 by antandre         ###   ########.fr       */
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
		argv = ft_split(argv[1], ' '); //Update my ft_split
	init_a(&a, argv + 1); //Define function
	if (!is_sorted(a)) //Define function
	{
		if (s_len(a) == 2) //Define function
			sa(&a, false);
		else if (s_len(a) == 3)
			three_sort(&a); //Define function
		else
			s_sort(&a, &b); //Define function
	}
	s_free(&a); //Define function
	return (0);
}