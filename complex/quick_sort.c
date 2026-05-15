/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:43:26 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/15 11:07:35 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"
#include "../simple/insertion.h"
#include "../stack/list_utils.h"
#include "../stack/position_utils.h"
#include "quicksort_utils.h"
#include <stdlib.h>

static void	rotate_to_top(t_stacks *stacks, int index)
{
	if (index < ft_lstsize(stacks->a.top) - index)
	{
		while (index != 0)
		{
			opp_rot(stacks, A);
			index--;
		}
	}
	else
	{
		while (index != ft_lstsize(stacks->a.top))
		{
			opp_rrot(stacks, A);
			index++;
		}
	}
}

// `index` is the number where the top of B should move to in A
static void	insertion(t_stacks *stacks, int index)
{
	rotate_to_top(stacks, index);
	opp_push(stacks, A);
}

static void	selection(t_stacks *stacks, int index)
{
	if (index < ft_lstsize(stacks->b.top) - index)
	{
		while (index != 0)
		{
			opp_rot(stacks, B);
			index--;
		}
	}
	else
	{
		while (index != ft_lstsize(stacks->b.top) + 1)
		{
			opp_rrot(stacks, B);
			index++;
		}
	}
	opp_push(stacks, A);
}

static void	start_moving_back(t_stacks *stacks)
{
	int	index_a;
	int	index_b;
	int	moves_a;
	int	moves_b;

	set_stack_a(stacks);
	while (ft_lstsize(stacks->b.top) != 0)
	{
		index_b = find_selection_pos(stacks);
		index_a = find_insert_pos(&stacks->a,
				get_content(stacks->b.top)->value);
		if (index_a < (ft_lstsize(stacks->a.top) - index_a))
			moves_a = index_a;
		else
			moves_a = ft_lstsize(stacks->a.top) - index_a;
		if (index_b < (ft_lstsize(stacks->b.top) - index_b))
			moves_b = index_b;
		else
			moves_b = ft_lstsize(stacks->b.top) - index_b;
		insertion(stacks, index_a);
	}
}

void	quicksort(t_stacks *stacks)
{
	int				listsize;
	t_list_contents	*pivot_content;
	int				pivot_count;

	pivot_count = 0;
	listsize = ft_lstsize(stacks->a.top);
	if (listsize <= 0)
		return ;
	if (listsize <= 75)
		pivot_content = find_pivots(stacks, pivot_count += 1);
	else if (listsize > 75 && listsize <= 125)
		pivot_content = find_pivots(stacks, pivot_count += 2);
	else if (listsize > 125 && listsize <= 250)
		pivot_content = find_pivots(stacks, pivot_count += 3);
	else
		pivot_content = find_pivots(stacks, pivot_count += 4);
	start_quickie_pivots(stacks, pivot_content, pivot_count);
	start_moving_back(stacks);
	rotate_to_top(stacks, find_min_position(&stacks->a));
	free(pivot_content);
}
int find_smallest_rank(t_stacks *stacks)
{
    t_list  *node;
    int     value;
    int     found;

    node = stacks->a.top;
    found = 0;
    while (node)
    {
        if (get_content(node)->index == -1)
        {
            if (!found || get_content(node)->value < value)
            {
                value = get_content(node)->value;
                found = 1;
            }
        }
        node = node->next;
    }
    return (value);
}