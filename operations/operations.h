/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   operations.h                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 14:13:10 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 17:08:39 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "../stack/stack.h"

// swap.c
// Swap the first two elements at the top of stack.
void	opp_swap(t_stacks *stacks, t_stack_name name);

// push.c
// push from src to dest
// Do nothing if `name` is empty.
void	opp_push(t_stacks *stacks, t_stack_name name);

// rotate.c
// Shift up all elements of stack by one.
// The first element becomes the last one.
void	opp_rot(t_stacks *stacks, t_stack_name name);

// reverse_rotate.c
// Shift down all elements of stack by one.
// The last element becomes the first one.
void	opp_rrot(t_stacks *stacks, t_stack_name name);

# ifdef CHECKER_BONUS

// same as opp_swap but doesnt print to std out
void	opp_swap_lst(t_stacks *stacks, t_stack_name name);
// same as opp_push but doesnt print to std out
void	opp_push_lst(t_stacks *stacks, t_stack_name name);
// same as opp_rot but doesnt print to std out
void	opp_rot_lst(t_stacks *stacks, t_stack_name name);
// same as opp_rrot but doesnt print to std out
void	opp_rrot_lst(t_stacks *stacks, t_stack_name name);
# endif
#endif
