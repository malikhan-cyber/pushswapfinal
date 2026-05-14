/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   position_utils.h                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: alkhan <alkhan@student.42.fr>                 +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/12 12:45:01 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 15:05:20 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "stack.h"

int		find_min_value(t_stack *stack);
int		find_min_position(t_stack *stack);
int		find_max_position(t_stack *stack);
int		find_max_value(t_stack *stack);
bool	is_stack_sorted(t_stack *stack);
