/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_float_fractional.c                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/22 14:13:29 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/22 15:29:52 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internals.h"

int	ft_len_fractional_part(t_flags flags)
{
	return (flags.precision);
}

// gets the 'one' digit as a double of the index
static double	get_local_one(int index)
{
	int		curr_index;
	double	one;

	one = 0.1;
	curr_index = 0;
	while (curr_index < index)
	{
		curr_index++;
		one /= 10;
	}
	return (one);
}

static bool	rounds_up(double v, double size, int index, int precision)
{
	char	digit;
	double	one;

	index++;
	one = get_local_one(index);
	while (index < precision)
	{
		digit = '0';
		if ((size + one * 9.0) > v)
		{
			return (false);
		}
		size += one * 9.0;
		one /= 10;
		index++;
	}
	if (v - size > one * 5.0)
		return (true);
	return (false);
}

static char	get_fractional_digit(double v, int index, int precision)
{
	char	digit;
	double	size;
	double	curr_one;
	int		curr_index;

	curr_index = -1;
	curr_one = 0.1;
	size = 0.0;
	while (++curr_index < index)
	{
		while ((size + curr_one) <= v)
			size += curr_one;
		curr_one /= 10;
	}
	digit = '0';
	while ((size + curr_one) <= v)
	{
		size += curr_one;
		digit++;
	}
	if (rounds_up(v, size, index, precision))
		digit++;
	while (digit > '9')
		digit -= 10;
	return (digit);
}

int	print_fractional_part(double v, t_flags flags)
{
	int		len;

	len = 0;
	if (v < 0.0)
		v = -v;
	while (v > 1.0)
		v -= 1.0;
	while (len < flags.precision)
	{
		if (len > 14)
			pf_putchar('0', flags.fd);
		else
			pf_putchar(get_fractional_digit(v, len, flags.precision), flags.fd);
		len++;
	}
	return (len);
}
