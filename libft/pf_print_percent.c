/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_percent.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/31 13:50:09 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 12:55:18 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_internals.h"

int	ft_print_percent(int fd)
{
	return (pf_putchar('%', fd));
}

#ifdef PRINTF_BONUS

int	ft_len_percent(void)
{
	return (1);
}

#endif
