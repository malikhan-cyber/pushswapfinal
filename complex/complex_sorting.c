/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:43:05 by kmurray           #+#    #+#             */
/*   Updated: 2026/05/14 21:37:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"
#include "../simple/insertion.h"
#include "../stack/list_utils.h"
#include "../stack/position_utils.h"
#include "quicksort_utils.h"
#include <stdlib.h>

// static void	rotate_to_top(t_stacks *stacks, int index)
// {
// 	if (index < ft_lstsize(stacks->a.top) - index)
// 	{
// 		while (index != 0)
// 		{
// 			opp_rot(stacks, A);
// 			index--;
// 		}
// 	}
// 	else
// 	{
// 		while (index != ft_lstsize(stacks->a.top))
// 		{
// 			opp_rrot(stacks, A);
// 			index++;
// 		}
// 	}
// }

// // `index` is the number where the top of B should move to in A
// static void	insertion(t_stacks *stacks, int index)
// {
// 	rotate_to_top(stacks, index);
// 	opp_push(stacks, A);
// }

// static void	selection(t_stacks *stacks, int index)
// {
// 	if (index < ft_lstsize(stacks->b.top) - index)
// 	{
// 		while (index != 0)
// 		{
// 			opp_rot(stacks, B);
// 			index--;
// 		}
// 	}
// 	else
// 	{
// 		while (index != ft_lstsize(stacks->b.top) + 1)
// 		{
// 			opp_rrot(stacks, B);
// 			index++;
// 		}
// 	}
// 	opp_push(stacks, A);
// }

// static void	start_moving_back(t_stacks *stacks)
// {
// 	int	index_a;
// 	int	index_b;
// 	int	moves_a;
// 	int	moves_b;

// 	set_stack_a(stacks);
// 	while (ft_lstsize(stacks->b.top) != 0)
// 	{
// 		index_b = find_selection_pos(stacks);
// 		index_a = find_insert_pos(&stacks->a,
// 				get_content(stacks->b.top)->value);
// 		if (index_a < (ft_lstsize(stacks->a.top) - index_a))
// 			moves_a = index_a;
// 		else
// 			moves_a = ft_lstsize(stacks->a.top) - index_a;
// 		if (index_b < (ft_lstsize(stacks->b.top) - index_b))
// 			moves_b = index_b;
// 		else
// 			moves_b = ft_lstsize(stacks->b.top) - index_b;
// 		insertion(stacks, index_a);
// 	}
// }

// void	quicksort(t_stacks *stacks)
// {
// 	int				listsize;
// 	t_list_contents	*pivot_content;
// 	int				pivot_count;

// 	pivot_count = 0;
// 	listsize = ft_lstsize(stacks->a.top);
// 	if (listsize <= 0)
// 		return ;
// 	if (listsize <= 75)
// 		pivot_content = find_pivots(stacks, pivot_count += 1);
// 	else if (listsize > 75 && listsize <= 125)
// 		pivot_content = find_pivots(stacks, pivot_count += 2);
// 	else if (listsize > 125 && listsize <= 250)
// 		pivot_content = find_pivots(stacks, pivot_count += 3);
// 	else
// 		pivot_content = find_pivots(stacks, pivot_count += 4);
// 	start_quickie_pivots(stacks, pivot_content, pivot_count);
// 	start_moving_back(stacks);
// 	rotate_to_top(stacks, find_min_position(&stacks->a));
// 	free(pivot_content);
// }
// First we run trough the stack ranking al numbers f
//from smallest to largest bij changing
// index to the rank of the number.



#include <limits.h>

static int find_min_unindexed_value(t_list *node)
{
    int min = INT_MAX;

    while (node)
    {
        if (get_content(node)->index == -1
            && get_content(node)->value < min)
            min = get_content(node)->value;
        node = node->next;
    }
    return (min);
}

void rank_the_numbers(t_stacks *stacks)
{
    int n;
    int i;
    int min;
    t_list *node;

    n = ft_lstsize(stacks->a.top);
    node = stacks->a.top;
    while (node)
    {
        get_content(node)->index = -1;
        node = node->next;
    }
    i = 0;
    while (i < n)
    {
        min = find_min_unindexed_value(stacks->a.top);
        node = stacks->a.top;
        while (node)
        {
            if (get_content(node)->value == min && get_content(node)->index == -1)
                get_content(node)->index = i;
            node = node->next;
        }
        i++;
    }
}


// here we count de binary bits there are in the highst ranked number
// so for example a list of 500 numbers will have 9 bits.
int	counting_bits(t_stacks *stacks)
{
	int	bits;
	int	i;

	i = 1;
	bits = ft_lstsize(stacks->a.top)-1;
	while (bits >> 1 != 0)
	{
		i++;
		bits = bits >> 1;
	}
	return (i);
}
// now based on the ranking we are going to check the last 
// bit everytime push to B if it is 0 to stack a, 
// push everything back to A do it for one bit 
// to the left the same thing and keep doing 
// this until we have done this to as long as what 
// counting bit returned. and stack a will be sorted

void	radix_sort_ranked(t_stacks *stacks)
{
	int	i;
	int	bits;
	int	listsize;

	bits = counting_bits(stacks);
	listsize = ft_lstsize(stacks->a.top);
	i = 0;
	while (i < bits)
	{
		while (listsize != 0)
		{
			if ((get_content(stacks->a.top)->index >> i & 1) == 0)
				opp_push(stacks, B);
			else
				opp_rot(stacks, A);
			listsize--;
		}
		while (ft_lstsize(stacks->b.top) != 0)
			opp_push(stacks, A);
		listsize = ft_lstsize(stacks->a.top);
		i++;
	}
}

int	complex_sorting(t_stacks *stacks)
{
	stacks->info.sorting_strategy = "Complex (Quicksort) / O(n log n)";
	rank_the_numbers(stacks);
	radix_sort_ranked(stacks);
	return (0);
}
