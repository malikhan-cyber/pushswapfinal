/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   stack.c                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 12:55:34 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 14:35:18 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../sorting.h"
#include "parsing.h"

// returns a new stack because this is usually used for parsing erros
// (this doesnt allocate anything)
t_stack	stack_cleanup(t_stack stack)
{
	ft_lstclear(&stack.top, free);
	return (new_stack(stack.name));
}

t_stack	new_stack(t_stack_name name)
{
	t_stack	stack;

	stack.name = name;
	stack.top = NULL;
	stack.bottom = NULL;
	return (stack);
}

t_sorting_info	new_info(t_stack stack_a)
{
	t_sorting_info	info;

	info.init_disorder = complexity(stack_a);
	info.sorting_strategy = NULL;
	info.operations = 0;
	info.sa = 0;
	info.sb = 0;
	info.ss = 0;
	info.pa = 0;
	info.pb = 0;
	info.ra = 0;
	info.rb = 0;
	info.rr = 0;
	info.rra = 0;
	info.rrb = 0;
	info.rrr = 0;
	return (info);
}

t_stacks	setup_stacks(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.a = parse_stack_a(argc, argv);
	stacks.b = new_stack('b');
	stacks.info = new_info(stacks.a);
	return (stacks);
}

t_stack	*get_stack(t_stacks *stacks, t_stack_name name)
{
	if (name == A)
		return (&stacks->a);
	else
		return (&stacks->b);
}
