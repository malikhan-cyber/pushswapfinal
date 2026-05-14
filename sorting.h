/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   sorting.h                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 14:26:02 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 17:36:24 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H
# include "operations/operations.h"

// starts the simple sorting algorithm
// todo: the actual algorithm is not here
int		simple_sorting(t_stacks *stacks);
void	insertion_sort(t_stacks *stacks);

typedef struct s_moves
{
	int				dst;
	int				src;
	t_stack_name	srcname;
}	t_moves;

// starts the medium sorting algorithm
// todo: the actual algorithm is not here
int		medium_sorting(t_stacks *stacks);

// starts the complex sorting algorithm
// todo: the actual algorithm is not here
int		complex_sorting(t_stacks *stacks);

// starts the adaptive sorting algorithm
// todo: the actual algorithm is not here
int		adaptive_sorting(t_stacks *stacks);
#endif
