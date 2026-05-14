/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   simple_sorting.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 14:42:25 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 15:14:04 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/position_utils.h"
#include "../sorting.h"

static void	rotate_to_top_in(t_stacks *stacks, int position, t_stack_name name)
{
	int	len;

	len = ft_lstsize(get_stack(stacks, name)->top);
	if ((len / 2) >= position)
	{
		while (position != 0)
		{
			opp_rot(stacks, name);
			position--;
		}
	}
	else
	{
		while (position != 0)
		{
			opp_rrot(stacks, name);
			position++;
			if (position == len)
				position = 0;
		}
	}
}

// sorts and empties the contents of non `name` to `name`
// invalid to provide "BOTH"
static void	sort_to(t_stacks *stacks, t_stack_name name)
{
	int		pos_min;
	int		len;
	t_stack	*source_stack;

	source_stack = get_stack(stacks, !name);
	len = ft_lstsize(source_stack->top);
	while (len > 1)
	{
		pos_min = find_min_position(source_stack);
		rotate_to_top_in(stacks, pos_min, !name);
		opp_push(stacks, B);
		opp_rrot(stacks, A);
		len--;
	}
}

static void	rev_move_to(t_stacks *stacks, t_stack_name name)
{
	int	len;

	len = ft_lstsize(get_stack(stacks, !name)->top);
	while (len != 0)
	{
		opp_push(stacks, name);
		len--;
	}
}

void	selection_sort(t_stacks *stacks)
{
	sort_to(stacks, B);
	rev_move_to(stacks, A);
}

int	simple_sorting(t_stacks *stacks)
{
	selection_sort(stacks);
	stacks->info.sorting_strategy = "Simple (Selection) / O(n²)";
	return (0);
}
