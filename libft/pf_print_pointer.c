/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_pointer.c                                  :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/31 13:52:40 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:15:22 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "pf_internals.h"
#include "pf_print_base.h"
#define DECIMAL "0123456789abcdef"
#define RADIX 16

int	ft_print_pointer(const void *pointer, t_flags flags)
{
	if (pointer == NULL)
	{
		if (pf_putstr("(nil)", flags.fd) == -1)
			return (-1);
		return (5);
	}
	else
	{
		if (pf_putstr("0x", flags.fd) == -1)
			return (-1);
		flags.precision = 0;
		return (put_base_size_t((size_t)pointer, DECIMAL, RADIX, flags) + 2);
	}
}

#ifdef PRINTF_BONUS

int	ft_len_pointer(const void *pointer)
{
	if (pointer == NULL)
		return (5);
	return (ft_len_size_t((size_t)pointer, RADIX, 0) + 2);
}

#endif
