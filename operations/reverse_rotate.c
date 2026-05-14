/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   reverse_rotate.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 14:18:32 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 17:22:43 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "operations.h"

static t_list	*second_to_last_ell(t_list *lst)
{
	if (ft_lstsize(lst) <= 1)
		return (lst);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

// Shift down all elements of the stack by one.
// The last element becomes the first one
// for use in opp_rra(), opp_rrb() and opp_rrr()
// top = end
// end = second to last
// set second to last -> next = NULL
// set old last -> top
static void	rev_rotate_stack(t_stack *stack)
{
	t_list	*second_to_last;

	if (!stack->top)
		return ;
	second_to_last = second_to_last_ell(stack->top);
	ft_lstadd_front(&stack->top, stack->bottom);
	stack->top = stack->bottom;
	stack->bottom = second_to_last;
	stack->bottom->next = NULL;
}

// Shift down all elements of a stack by one.
// The last element becomes the first one.
// doesnt print anything
void	opp_rrot_lst(t_stacks *stacks, t_stack_name name)
{
	stacks->info.operations++;
	if (name == A)
	{
		stacks->info.rra++;
		rev_rotate_stack(&stacks->a);
	}
	else if (name == B)
	{
		stacks->info.rrb++;
		rev_rotate_stack(&stacks->b);
	}
	else
	{
		stacks->info.rrr++;
		rev_rotate_stack(&stacks->a);
		rev_rotate_stack(&stacks->b);
	}
}

// Shift down all elements of stack by one.
// The last element becomes the first one.
void	opp_rrot(t_stacks *stacks, t_stack_name name)
{
	if (name == A)
		write(1, "rra\n", 4);
	else if (name == B)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
	opp_rrot_lst(stacks, name);
}
