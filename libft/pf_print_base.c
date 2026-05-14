/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_base.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/01 15:36:29 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:01:20 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_internals.h"

static int	print_zeroes(int amount, t_flags flags)
{
	while (amount-- > 1)
	{
		if (pf_putchar('0', flags.fd) == -1)
			return (-1);
	}
	return (0);
}

size_t	ft_len_base(unsigned int n, const unsigned int radix, const int min)
{
	size_t	chars;

	if ((min == 0) && (n == 0))
		return (0);
	chars = 1;
	while (n >= radix)
	{
		n /= radix;
		chars++;
	}
	return (max(chars, min));
}

int	put_base(const unsigned int num, const char *base,
	const unsigned int radix, const t_flags flags)
{
	unsigned int	n;
	long			size;
	int				min_amount;

	if ((flags.precision == 0) && (num == 0))
		return (0);
	n = num;
	size = 1;
	min_amount = flags.precision;
	while ((size * radix) <= n)
	{
		size *= radix;
		min_amount--;
	}
	if (print_zeroes(min_amount, flags) == -1)
		return (-1);
	while (size != 0)
	{
		if (pf_putchar(base[(int)(n / size)], flags.fd) == -1)
			return (-1);
		n %= size;
		size /= radix;
	}
	return (ft_len_base(num, radix, flags.precision));
}

int	ft_len_size_t(size_t n, const size_t radix, const int min)
{
	size_t	chars;

	if ((min == 0) && (n == 0))
		return (0);
	chars = 1;
	while (n >= radix)
	{
		n /= radix;
		chars++;
	}
	return (max(chars, min));
}

int	put_base_size_t(const size_t num, const char *base,
	const size_t radix, const t_flags flags)
{
	size_t	n;
	size_t	size;
	int		min_amount;

	if ((flags.precision == 0) && (num == 0))
		return (0);
	n = num;
	size = 1;
	min_amount = flags.precision;
	while ((size <= (n / radix)))
	{
		size *= radix;
		min_amount--;
	}
	if (print_zeroes(min_amount, flags) == -1)
		return (-1);
	while (size != 0)
	{
		if (pf_putchar(base[(n / size)], flags.fd) == -1)
			return (-1);
		n %= size;
		size /= radix;
	}
	return (ft_len_size_t(num, radix, flags.precision));
}
