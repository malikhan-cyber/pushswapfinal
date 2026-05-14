/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   list_utils.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/24 17:59:06 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 15:04:21 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// might return null if the index is invalid
t_list_contents	*get(t_stack *stack, int n)
{
	t_list	*node;
	int		i;

	i = 0;
	if (!stack->top)
		return (NULL);
	node = stack->top;
	while (i < n)
	{
		if (!node->next)
			node = stack->top;
		else
			node = node->next;
		i++;
	}
	return ((t_list_contents *)node->content);
}

// might return null if the index is invalid
// this does not return back to the start of the list if it needs to
t_list_contents	*get_n(t_list *list, int n)
{
	int	i;

	i = 0;
	while (i < n && list)
	{
		list = list->next;
		i++;
	}
	if (!list)
		return (NULL);
	return ((t_list_contents *)list->content);
}

// get the contents of list
t_list_contents	*get_content(t_list *list)
{
	return ((t_list_contents *)list->content);
}

// adds an ellement to the back of the list
// returns -1 on error
int	ft_lstadd_ell_back(t_list **lst, void *new)
{
	t_list	*new_element;

	new_element = ft_lstnew(new);
	if (!new_element)
		return (-1);
	ft_lstadd_back(lst, new_element);
	return (0);
}
