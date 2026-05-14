/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   adaptive_sorting.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/13 18:29:31 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/13 18:59:41 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "operations/operations.h"
#include "sorting.h"
#include "stack/list_utils.h"

int	adaptive_sorting(t_stacks *stacks)
{
	float	disorder;
	int		len;

	stacks->info.sorting_strategy = "Adaptive / Unknown";
	disorder = complexity(stacks->a);
	len = ft_lstsize(stacks->a.top);
	if (disorder < 0.2 && len <= 10)
		simple_sorting(stacks);
	else if (disorder < 0.2)
		insertion_sort(stacks);
	else if (disorder < 0.5)
		medium_sorting(stacks);
	else
		complex_sorting(stacks);
	return (0);
}
