/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   medium_sort_merge.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/11 16:23:17 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 14:30:33 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "../stack/list_utils.h"
#include "../operations/operations.h"

int	squaroot(int n)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) < n)
		i++;
	return (i);
}

static void	merge_section(t_stacks *stacks, int len)
{
	int	i;
	int	length_left;

	i = 0;
	length_left = ft_lstsize(stacks->a.top);
	while (i < len)
	{
		if (stacks->a.bottom)
		{
			while (get_content(stacks->a.bottom)->value
				> get_content(stacks->b.top)->value
				&& ft_lstsize(stacks->a.top) > 1
				&& length_left > 0)
			{
				length_left--;
				opp_rrot(stacks, A);
			}
		}
		opp_push(stacks, A);
		i++;
	}
	while (get_content(stacks->a.bottom)->value
		< get_content(stacks->a.top)->value)
		opp_rrot(stacks, A);
}

void	merge(t_stacks *stacks)
{
	int	section_length;
	int	length;
	int	i;

	length = ft_lstsize(stacks->b.top);
	section_length = squaroot(length);
	i = 0;
	while (i < section_length)
	{
		if (i == 0)
			merge_section(stacks, ft_lstsize(stacks->b.top)
				- section_length * section_length + section_length);
		else
			merge_section(stacks, section_length);
		i++;
	}
}
