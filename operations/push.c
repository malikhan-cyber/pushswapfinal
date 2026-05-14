/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   push.c                                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 14:15:18 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 17:50:32 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../operations/operations.h"

// pushes the top node from src to dest
static void	push_to(t_stack *dest, t_stack *src)
{
	t_list	*new_top;

	if (!src->top)
		return ;
	new_top = src->top->next;
	ft_lstadd_front(&dest->top, src->top);
	dest->top = src->top;
	if (!dest->bottom)
		dest->bottom = dest->top;
	src->top = new_top;
	if (ft_lstsize(new_top) < 2)
		src->bottom = src->top;
}

// performs the actual push operation on the list
void	opp_push_lst(t_stacks *stacks, t_stack_name name)
{
	stacks->info.operations++;
	if (name == A)
	{
		stacks->info.pa++;
		push_to(&stacks->a, &stacks->b);
	}
	else if (name == B)
	{
		stacks->info.pb++;
		push_to(&stacks->b, &stacks->a);
	}
}

void	opp_push(t_stacks *stacks, t_stack_name name)
{
	if (name == A)
		write(1, "pa\n", 3);
	else if (name == B)
		write(1, "pb\n", 3);
	opp_push_lst(stacks, name);
}
