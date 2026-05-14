/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   quicksort_utils.h                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/11 17:22:40 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 14:24:33 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_UTILS_H
# define QUICKSORT_UTILS_H
# include "../stack/stack.h"

int				set_stack_a(t_stacks *stacks);
void			start_quickie_pivots(t_stacks *stacks, t_list_contents *pivots,
					int pivot_count);
t_list_contents	*find_pivots(t_stacks *stacks, int amount);
int				find_selection_pos(t_stacks *stacks);
#endif
