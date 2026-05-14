/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   medium_sorting.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/11 16:45:32 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 14:31:02 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../stack/list_utils.h"
#include "../operations/operations.h"
#include "medium_sort_merge.h"

// moves a chunk into view (top of the stack)
// returns how much it was moved by
static void	move_to(t_stacks *stacks, t_stack_name stack, int position)
{
	int	length;

	length = ft_lstsize(get_stack(stacks, stack)->top);
	while (position != 0)
	{
		if (position >= (length / 2))
			opp_rrot(stacks, stack);
		else if (position != 0)
			opp_rot(stacks, stack);
		position += (position >= length / 2) * 2 - 1;
		position %= length;
	}
}

static int	move_to_right_position(t_stacks *stacks,
		int value, int top, int chunk_len)
{
	while (true)
	{
		if (value < get(&stacks->b, 0)->value && top > -chunk_len)
		{
			top--;
			if (ft_lstsize(stacks->b.top) == 1)
				break ;
			opp_rot(stacks, B);
		}
		else if (value > get_content(stacks->b.bottom)->value
			&& top < 0)
		{
			if (ft_lstsize(stacks->b.top) == 1)
				break ;
			top++;
			opp_rrot(stacks, B);
		}
		else
			break ;
	}
	return (top);
}

// an insertion sort to B (doesnt loop)
static void	sort_section(t_stacks *stacks, int len)
{
	int	i;
	int	top;
	int	value;

	top = 0;
	i = 0;
	while (i < len)
	{
		value = get(&stacks->a, 0)->value;
		if (stacks->b.top)
			top = move_to_right_position(stacks, value, top, i);
		opp_push(stacks, B);
		i++;
	}
	if (top < 0)
		top += ft_lstsize(stacks->b.top);
	move_to(stacks, B, top);
}

static void	chunk_sort(t_stacks *stacks)
{
	int	section_length;
	int	a_length;
	int	i;

	a_length = ft_lstsize(stacks->a.top);
	section_length = squaroot(a_length);
	i = 0;
	while (i < section_length)
	{
		if (i == section_length - 1)
			sort_section(stacks, ft_lstsize(stacks->a.top));
		else
			sort_section(stacks, section_length);
		i++;
	}
}

// divides A into sqrt(N) chunks
// sorts each of them into B in an insertion sort manner (high to low)
// so the chunks are sorted as sqrt(N) high to low sections
// then merges them one by one into A
// by reverse rotating A untill the bottom value is lower than the top in B
// then pushes to B repeating until the top B chunk is empty
// and after that reverse rotating back to the top of A
// and repeating that with the next chunk
int	medium_sorting(t_stacks *stacks)
{
	chunk_sort(stacks);
	merge(stacks);
	stacks->info.sorting_strategy = "Medium (Custom) / O(n√n̅)";
	return (0);
}
