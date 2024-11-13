/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antandre <antandre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:35:19 by antandre          #+#    #+#             */
/*   Updated: 2024/11/13 16:41:16 by antandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// Algorithm

#endif
