/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_float_integer.c                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/22 14:08:24 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/04 17:15:52 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internals.h"

int	ft_len_integer_part(double v)
{
	int	len;

	len = 1;
	while ((v >= 10.0))
	{
		v /= 10;
		len++;
	}
	return (len);
}

// gets a character for a float in 0-9.0 range
// undefined otherwise
static char	get_char_value(double v)
{
	double	size;
	char	i;

	i = '0';
	size = 0.0;
	if (v > 10.0)
		return (-1);
	while ((size + 1.0) <= v)
	{
		i++;
		size += 1.0;
	}
	while (i > '9')
		i -= 10;
	return (i);
}

int	print_integer_part(double v, t_flags flags)
{
	int		len;
	double	size;

	size = 1.0;
	len = 0;
	if (v < 0.0)
		v = -v;
	while ((size * 10.0) <= (v))
		size *= 10.0;
	while ((size > 0.1))
	{
		pf_putchar(get_char_value(v / size), flags.fd);
		while (v > size)
			v -= size;
		size /= 10.0;
		len++;
	}
	return (len);
}
