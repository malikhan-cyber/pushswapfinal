/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_int.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/31 13:49:36 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 12:55:01 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_internals.h"
#include "pf_print_base.h"

static int	int_length(int n, const int radix)
{
	int	chars;

	chars = 1;
	if (n < 0)
		chars++;
	while ((n < -(radix - 1)) || (n > (radix - 1)))
	{
		n /= radix;
		chars++;
	}
	return (chars);
}

int	ft_len_int(const int i, t_flags flags)
{
	int	len;
	int	precision_len;

	if (!flags.precision_set && flags.precision < 1)
		flags.precision = 1;
	len = 0;
	if ((flags.always_sign || flags.neg_sign) && (i >= 0))
		len++;
	precision_len = flags.precision;
	if ((precision_len == 0) && (i == 0))
		return (0);
	if (i < 0)
		precision_len++;
	return (len + max(int_length(i, 10), precision_len));
}

static int	putnbr_inner(long n, long size, int sign, int fd)
{
	while ((size > 0))
	{
		if (pf_putchar((n / size) * sign + '0', fd) == -1)
			return (-1);
		n %= size * sign;
		size /= 10;
	}
	return (0);
}

// returns 0 on success and -1 on error
static int	putnbr(long n, int min, int fd)
{
	int		sign;
	long	size;

	if ((min == 0) && (n == 0))
		return (0);
	sign = -(n < 0) * 2 + 1;
	if (n < 0)
	{
		if (pf_putchar('-', fd) == -1)
			return (-1);
	}
	size = 1;
	while ((size * 10) <= (n * sign))
	{
		size *= 10;
		min--;
	}
	while (min-- > 1)
	{
		if (pf_putchar('0', fd) == -1)
			return (-1);
	}
	return (putnbr_inner(n, size, sign, fd));
}

// print integer, in decimal
int	ft_print_int(const int num, t_flags flags)
{
	if (!flags.precision_set && flags.precision < 1)
		flags.precision = 1;
	if ((flags.always_sign) && (num >= 0))
	{
		if (pf_putchar('+', flags.fd) == -1)
			return (-1);
	}
	else if ((flags.neg_sign) && (num >= 0))
	{
		if (pf_putchar(' ', flags.fd) == -1)
			return (-1);
	}
	if (putnbr((long)num, flags.precision, flags.fd) == -1)
		return (-1);
	return (ft_len_int(num, flags));
}
