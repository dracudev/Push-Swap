/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:35:19 by antandre          #+#    #+#             */
/*   Updated: 2024/11/14 13:23:13 by antandre         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../lib/Libft/include/libft.h"

typedef struct s_stack
{
	int							n;
	int							index;
	int							cost;
	bool						up_media;
	bool						cheap;
	struct s_stack				*target;
	struct s_stack				*next;
	struct s_stack				*prev;
}	t_stack;

// Errors

// Inits

// Utils

// Operations
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

// Algorithm

#endif
