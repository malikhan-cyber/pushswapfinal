/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_float.c                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/21 15:54:21 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/22 15:29:55 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pf_internals.h"
#include "pf_print_float_inner.h"

int	ft_len_float(double v, t_flags flags)
{
	int	sign_length;

	if (v != v)
		return (3);
	if (!flags.precision_set)
		flags.precision = 6;
	sign_length = 0;
	if ((v < 0.0) || flags.always_sign || flags.neg_sign)
		sign_length += 1;
	if (flags.precision != 0 || flags.alternate)
		sign_length += 1;
	if (v < 0.0)
		v = -v;
	return (sign_length + ft_len_integer_part(v)
		+ ft_len_fractional_part(flags));
}

static int	print_sign(double v, t_flags flags)
{
	if (v < 0.0)
	{
		if (pf_putchar('-', flags.fd) == -1)
			return (-1);
	}
	else if (flags.always_sign)
	{
		if (pf_putchar('+', flags.fd) == -1)
			return (-1);
	}
	else if (flags.neg_sign)
	{
		if (pf_putchar(' ', flags.fd) == -1)
			return (-1);
	}
	return (0);
}

// supports #0- +.
int	ft_print_float(const double v, t_flags flags)
{
	int	len;
	int	new_len;

	if (!flags.precision_set)
		flags.precision = 6;
	if (v != v)
		return (pf_putstr("nan", flags.fd));
	len = print_sign(v, flags);
	if (len == -1)
		return (-1);
	new_len = print_integer_part(v, flags);
	if (new_len == -1)
		return (-1);
	len += new_len;
	if (flags.precision != 0 || flags.alternate)
		new_len = pf_putchar('.', flags.fd);
	if (new_len == -1)
		return (-1);
	len += new_len;
	new_len = print_fractional_part(v, flags);
	if (new_len == -1)
		return (-1);
	len += new_len;
	return (ft_len_float(v, flags));
}
