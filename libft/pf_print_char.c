/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_char.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/31 13:48:39 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 12:52:01 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internals.h"

int	ft_print_char(const char c, int fd)
{
	return (pf_putchar(c, fd));
}

#ifdef PRINTF_BONUS

int	ft_len_char(void)
{
	return (1);
}

#endif
