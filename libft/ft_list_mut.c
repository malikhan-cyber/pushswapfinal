/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_list_mut.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/17 17:49:13 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/23 12:13:26 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// deletes the content of one node (doesnt delete the next or reorder anything)
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

// deletes the content of one node (doesnt delete the next or reorder anything)
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*current;

	current = *lst;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		ft_lstdelone(prev, del);
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current_new;
	void	*content;

	new = NULL;
	if (f == NULL || del == NULL || lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		content = f(lst->content);
		current_new = ft_lstnew(content);
		if (current_new == NULL)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, current_new);
		lst = lst->next;
	}
	return (new);
}
