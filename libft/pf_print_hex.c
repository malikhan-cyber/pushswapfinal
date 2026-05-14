/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_hex.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/31 13:49:07 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 16:16:33 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_print_base.h"
#include "pf_internals.h"
#define HEXLOWER "0123456789abcdef"
#define HEXUPPER "0123456789ABCDEF"
#define RADIX 16

int	ft_len_hex_lower(const unsigned int n, t_flags flags)
{
	int	len;

	if (!flags.precision_set && flags.precision < 1)
		flags.precision = 1;
	len = 0;
	if (flags.alternate && (n != 0))
		len += 2;
	return (ft_len_base(n, RADIX, flags.precision) + len);
}

int	ft_len_hex_upper(const unsigned int n, t_flags flags)
{
	int	len;

	if (!flags.precision_set && flags.precision < 1)
		flags.precision = 1;
	len = 0;
	if (flags.alternate && (n != 0))
		len += 2;
	return (ft_len_base(n, RADIX, flags.precision) + len);
}

int	ft_print_hex_lower(const unsigned int n, t_flags flags)
{
	int	len;

	if (!flags.precision_set && flags.precision < 1)
		flags.precision = 1;
	if (flags.alternate && (n != 0))
	{
		flags.precision -= 2;
		if (pf_putstr("0x", flags.fd) == -1)
			return (-1);
	}
	len = ft_len_base(n, RADIX, flags.precision);
	while (len++ < flags.precision)
	{
		if (pf_putchar('0', flags.fd) == -1)
			return (-1);
	}
	if (put_base(n, HEXLOWER, RADIX, flags) == -1)
		return (-1);
	return (ft_len_hex_lower(n, flags));
}

int	ft_print_hex_upper(const unsigned int n, t_flags flags)
{
	int	len;

	if (!flags.precision_set && flags.precision < 1)
		flags.precision = 1;
	if (flags.alternate && (n != 0))
	{
		flags.precision -= 2;
		if (pf_putstr("0X", flags.fd) == -1)
			return (-1);
	}
	len = ft_len_base(n, RADIX, flags.precision);
	while (len++ < flags.precision)
	{
		if (pf_putchar('0', flags.fd))
			return (-1);
	}
	if (put_base(n, HEXUPPER, RADIX, flags) == -1)
		return (-1);
	return (ft_len_hex_lower(n, flags));
}
