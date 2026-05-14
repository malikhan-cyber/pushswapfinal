/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_utils.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:24:45 by alkhan            #+#    #+#             */
/*   Updated: 2026/05/13 16:05:07 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../sorting.h"
#include "../stack/list_utils.h"
#include "../stack/position_utils.h"
#include "pivots.h"

int	find_selection_pos(t_stacks *stacks)
{
	t_list	*node;
	int		max_value;
	int		counter;

	counter = 0;
	node = stacks->b.top;
	max_value = get_content(node)->value;
	while (node)
	{
		if (node->next != NULL && get_content(node->next)->value > max_value)
			max_value = get_content(node->next)->value;
		node = node->next;
	}
	node = stacks->b.top;
	while (get_content(node)->value != max_value)
	{
		counter++;
		node = node->next;
	}
	return (counter);
}
/* 
move_to_b looks at the first and last occurrence of a numbers smaller or equal to the pivot,
and together with the information of how long your stack still is, you know how many rotations
and in which direction you make the rotations to get to the top and push.
*/
void	move_to_b(t_stacks *stacks, int first_smallest, int last_smallest, int pivot)
{
	int	listsize;
	int	rrotate;

	listsize = ft_lstsize(stacks->a.top);
	rrotate = (listsize + 1) - first_smallest;
	if (rrotate < last_smallest)
	{
		while (rrotate != 0)
		{
			if (get(&stacks->a, 0)->value <= pivot)
				opp_push(stacks, B);
			opp_rrot(stacks, A);
			rrotate--;
		}
	}
	else
	{
		while (last_smallest != 0)
		{
			if (get(&stacks->a, 0)->value <= pivot)
				opp_push(stacks, B);
			opp_rot(stacks, A);
			last_smallest--;
		}
	
	}
}

int	set_stack_a(t_stacks *stacks)
{
	while(ft_lstsize(stacks->a.top) != 3)
		opp_push(stacks, B);
	if (is_stack_sorted(&stacks->a) == true)
		return (1);
	if (get(&stacks->a, 0)->value > get(&stacks->a, 1)->value
		&& get(&stacks->a, 1)->value > get(&stacks->a, 2)->value)
		return (opp_rot(stacks, A), opp_swap(stacks, A), 1);
	else if (get(&stacks->a, 0)->value > get(&stacks->a, 2)->value
		&& get(&stacks->a, 2)->value > get(&stacks->a, 1)->value)
		return (opp_rot(stacks, A), 1);
	else if (get(&stacks->a, 1)->value > get(&stacks->a, 2)->value
		&& get(&stacks->a, 2)->value > get(&stacks->a, 0)->value)
		return (opp_rrot(stacks, A), opp_swap(stacks, A), 1);
	else if (get(&stacks->a, 2)->value > get(&stacks->a, 0)->value
		&& get(&stacks->a, 0)->value > get(&stacks->a, 1)->value)
		return (opp_swap(stacks, A), 1);
	else if (get(&stacks->a, 1)->value > get(&stacks->a, 0)->value
		&& get(&stacks->a, 0)->value > get(&stacks->a, 2)->value)
		return (opp_rrot(stacks, A), 1);
	return (-1);
}

void	quickest_quickie_pivots(t_stacks *stacks, int smallest_pivot)
{
	int		i;
	int		first_smallest;
	int		last_smallest;
	t_list	*node;

	node = stacks->a.top;
	i = 0;
	while (node && (!(get_n(node, 0)->value <= smallest_pivot)))
	{
		node = node->next;
		i++;
	}
	first_smallest = i;
	last_smallest = first_smallest;
	while (node)
	{
		if (get_n(node, 0)->value <= smallest_pivot)
			last_smallest = i;
		i++;
		node = node->next;
	}
	move_to_b(stacks, first_smallest, last_smallest, smallest_pivot);
}

void	start_quickie_pivots(t_stacks *stacks, t_list_contents *pivots,
		int pivot_count)
{
	int		i;

	i = 0;
	while (i < pivot_count)
	{
		quickest_quickie_pivots(stacks, pivots[i].value);
		i++;
	}
}
