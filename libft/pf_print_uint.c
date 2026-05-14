/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_uint.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/31 13:53:46 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:16:03 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_internals.h"
#include "pf_print_base.h"
#define DECIMAL "0123456789"
#define RADIX 10

int	ft_len_uint(const unsigned int uint, t_flags flags)
{
	if (!flags.precision_set && flags.precision < 1)
		flags.precision = 1;
	return (ft_len_base(uint, RADIX, flags.precision));
}

// print unsigned integer, in decimal
int	ft_print_uint(const unsigned int num, t_flags flags)
{
	int	len;

	if (!flags.precision_set && flags.precision < 1)
		flags.precision = 1;
	len = ft_len_base(num, RADIX, flags.precision);
	while (len++ < flags.precision)
	{
		if (pf_putstr("0", flags.fd) == -1)
			return (-1);
	}
	if (put_base(num, DECIMAL, RADIX, flags) == -1)
		return (-1);
	return (ft_len_uint(num, flags));
}
