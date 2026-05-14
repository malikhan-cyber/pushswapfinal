/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   swap.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 14:14:24 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 16:58:07 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "unistd.h"

// swap top two elements in the stack.
// Do nothing if there is only one or no elements.
// for use in opp_sa(), opp_sb() and opp_ss()
static void	swap_top(t_stack *stack)
{
	t_list	*second;

	if (ft_lstsize(stack->top) <= 1)
		return ;
	second = stack->top->next;
	stack->top->next = second->next;
	second->next = stack->top;
	stack->top = second;
	if (ft_lstsize(stack->top) == 2)
		stack->bottom = second->next;
	return ;
}

// Swap the first two elements at the top of stack.
// Do nothing if there is only one or no elements.
// doesnt print anything
void	opp_swap_lst(t_stacks *stacks, t_stack_name name)
{
	stacks->info.operations++;
	if (name == A)
	{
		stacks->info.sa++;
		swap_top(&stacks->a);
	}
	else if (name == B)
	{
		stacks->info.sb++;
		swap_top(&stacks->b);
	}
	else
	{
		stacks->info.ss++;
		swap_top(&stacks->a);
		swap_top(&stacks->b);
	}
}

// Swap the first two elements at the top of stack.
// Do nothing if there is only one or no elements.
void	opp_swap(t_stacks *stacks, t_stack_name name)
{
	stacks->info.operations++;
	if (name == A)
		write(1, "sa\n", 3);
	else if (name == B)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
	opp_swap_lst(stacks, name);
}
