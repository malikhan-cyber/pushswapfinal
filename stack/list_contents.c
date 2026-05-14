/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   list_contents.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/22 17:20:13 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 17:36:56 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "list_utils.h"

t_list_contents	new_contents(int value, int index)
{
	t_list_contents	contents;

	contents.value = value;
	contents.index = index;
	return (contents);
}

float	complexity(t_stack a)
{
	t_list	*i;
	t_list	*j;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = a.top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs += 1;
			if (get_content(i)->value > get_content(j)->value)
				mistakes += 1;
			j = j->next;
		}
		i = i->next;
	}
	return ((float)mistakes / (float)total_pairs);
}
