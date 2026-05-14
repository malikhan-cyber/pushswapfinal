/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:59:05 by kmurray           #+#    #+#             */
/*   Updated: 2026/05/13 13:36:06 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../stack/list_utils.h"

static int	find_smallest_pivot(t_list_contents *pivot_options,
		int size_pivot_list)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = 0;
	while (i != size_pivot_list)
	{
		if (pivot_options[i].value < pivot_options[smallest].value)
			smallest = i;
		i++;
	}
	return (smallest);
}

static t_list_contents	*sort_pivot_options(t_list_contents *pivot_options,
		int size_pivot_list)
{
	t_list_contents	*pivot_options_sorted;
	int				smallest;
	int				i;

	i = 0;
	pivot_options_sorted = malloc(size_pivot_list * sizeof(t_list_contents));
	if (!pivot_options_sorted)
		return (free(pivot_options), NULL);
	while (size_pivot_list != 0)
	{
		smallest = find_smallest_pivot(pivot_options, size_pivot_list);
		pivot_options_sorted[i].value = pivot_options[smallest].value;
		pivot_options_sorted[i].index = pivot_options[smallest].index;
		size_pivot_list--;
		i++;
	}
	return (free(pivot_options), pivot_options_sorted);
}

t_list_contents	*find_pivot_options(t_stacks *stacks, int amount)
{
	int				listsize;
	int				chunksize;
	int				i;
	t_list_contents	*pivots;

	i = 0;
	listsize = ft_lstsize(stacks->a.top);
	chunksize = listsize / amount;
	pivots = malloc((amount * 3) * sizeof(t_list_contents));
	if (!pivots)
		return (NULL);
	while (i < amount)
	{
		pivots[i * 3 + 0] = *get(&stacks->a, (i * chunksize));
		pivots[i * 3 + 1] = *get(&stacks->a, ((i * chunksize) + (chunksize / 2)));
		if (i == amount - 1)
			pivots[i * 3 + 2] = *get(&stacks->a, (((i + 1) * chunksize)
						+ listsize % amount));
		else
			pivots[i * 3 + 2] = *get(&stacks->a, (((i + 1) * chunksize)));
		i++;
	}
	return (sort_pivot_options(pivots, (amount * 3)));
}

t_list_contents	*find_pivots(t_stacks *stacks, int amount)
{
	t_list_contents	*pivot_options;
	t_list_contents	*final_pivots;

	final_pivots = malloc(amount * sizeof(t_list_contents));
	if (!final_pivots)
		return (NULL);
	pivot_options = find_pivot_options(stacks, amount);
	if (!pivot_options)
		return (free(final_pivots), NULL);
	if (amount >= 1)
		final_pivots[0] = pivot_options[1];
	if (amount >= 2)
		final_pivots[1] = pivot_options[4];
	if (amount >= 3)
		final_pivots[2] = pivot_options[7];
	if (amount == 4)
		final_pivots[3] = pivot_options[10];
	return (free(pivot_options), final_pivots);
}
