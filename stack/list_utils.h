/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   list_utils.h                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/24 17:59:19 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 12:45:35 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H
# include "stack.h"

// might return null if the index is invalid
t_list_contents	*get(t_stack *stack, int n);

// might return null if the index is invalid
// this does not return back to the start of the list if it needs to
t_list_contents	*get_n(t_list *list, int n);

// get the contents of list
t_list_contents	*get_content(t_list *list);

// adds an ellement to the end of a list
int				ft_lstadd_ell_back(t_list **lst, void *new);
#endif
