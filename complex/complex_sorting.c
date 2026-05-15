/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:43:05 by kmurray           #+#    #+#             */
/*   Updated: 2026/05/15 11:32:52 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../operations/operations.h"
#include "../simple/insertion.h"
#include "../stack/list_utils.h"
#include "../stack/position_utils.h"
#include "quicksort_utils.h"
#include <stdlib.h>

// First we run trough the stack ranking al numbers 
//from smallest to largest bij changing
// index to the rank of the number.

int find_smallest_rank(t_stacks *stacks)
{
    t_list *node; 
    int value;

    node = stacks->a.top;
    while(node)
    {
        if(get_content(node)->index == -1)
        {
            value = get_content(node)->value;
            break;
        }
        node = node->next;
    }
    while(node)
    {
        if(get_content(node)->index == -1 && get_content(node)->value < value)
        {
            value = get_content(node)->value;
        }       
        node = node->next;
    }
    return(value);
}
void    set_nodes_neg(t_stacks *stacks)
{
    t_list  *node;
    
    node = stacks->a.top;
    while (node)
    {
        get_content(node)->index = -1;
        node = node->next;
    }
}

void    rank_the_numbers(t_stacks *stacks)
{   
    int     i;
    int     value;
    t_list *node;
    
    set_nodes_neg(stacks);
    i = 0;
    while (i < ft_lstsize(stacks->a.top))
    {
        value = find_smallest_rank(stacks);
        node = stacks->a.top;
        while (node)
        {
            if (get_content(node)->value == value
                && get_content(node)->index == -1)
                get_content(node)->index = i;
            node = node->next;
        }
        i++;
    }
}

// here we count the binary bits there are in the highst ranked number
// so for example a list of 500 numbers, we will have 9 bits.
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
	stacks->info.sorting_strategy = "Complex (Radixsort) / O(n log n)";
	rank_the_numbers(stacks);
	radix_sort_ranked(stacks);
	return (0);
}
