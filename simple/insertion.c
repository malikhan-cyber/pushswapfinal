/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   insertion.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/11 17:50:44 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 14:29:37 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../stack/list_utils.h"
#include "../stack/position_utils.h"

int	find_insert_pos_rev(t_stack *stack, int value)
{
	int		counter;
	t_list	*node;

	counter = 0;
	node = stack->top;
	if (value > find_max_value(stack))
		return (find_max_position(stack));
	if (value < find_min_value(stack))
	{
		if (find_min_position(stack) == ft_lstsize(stack->top))
			return (ft_lstsize(stack->top));
		return (find_min_position(stack) + 1);
	}
	while (counter != ft_lstsize(stack->top))
	{
		if (node->next && ((value < get_content(node)->value)
				&& (value > get_content(node->next)->value)))
			return (counter + 1);
		node = node->next;
		counter++;
	}
	return (counter);
}

int	find_insert_pos(t_stack *stack, int value)
{
	int		counter;
	t_list	*node;

	counter = 0;
	node = stack->top;
	if (value > find_max_value(stack))
		return (find_max_position(stack) + 1);
	if (value < find_min_value(stack))
		return (find_min_position(stack));
	while (counter != ft_lstsize(stack->top))
	{
		if (node->next && ((value > get_content(node)->value)
				&& (value < get_n(node, 1)->value)))
			return (counter + 1);
		node = node->next;
		counter++;
	}
	return (counter);
}
