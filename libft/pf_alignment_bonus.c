/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_alignment_bonus.c                                :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/08 13:24:18 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 12:49:23 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pf_formatting_bonus.h"
#include "pf_internals.h"
#include "libft.h"

// `-` prints the value on the left, then zeroes up to the size
int	ft_left_justify(t_flags flags, t_formatter value)
{
	int	len;

	if (value.type == PERCENT)
		return (ft_print_value(value, flags));
	len = ft_print_value(value, flags);
	while (len < flags.size)
	{
		if (pf_putchar(' ', flags.fd) == -1)
			return (-1);
		len++;
	}
	return (len);
}

// the `0` padding
int	ft_right_zeroed(t_flags flags, t_formatter value)
{
	int	i;

	if (((value.type != DECIMAL)
			&& (value.type != UINT)
			&& (value.type != INTEGER)
			&& (value.type != LHEX)
			&& (value.type != UHEX))
		|| flags.precision_set)
		return (ft_right_justified(flags, value));
	flags.precision = flags.size;
	if ((value.type == DECIMAL)
		|| (value.type == INTEGER))
	{
		if ((value.value.sint < 0) || (flags.neg_sign || flags.always_sign))
			flags.precision--;
	}
	i = ft_print_value(value, flags);
	return (i);
}

// default value padding right aligned
int	ft_right_justified(t_flags flags, t_formatter value)
{
	int	len;
	int	i;

	if (value.type == PERCENT)
		return (ft_print_value(value, flags));
	len = flags.size - ft_value_len(value, flags);
	i = 0;
	while (i < len)
	{
		if (pf_putchar(' ', flags.fd) == -1)
			return (-1);
		i++;
	}
	i += ft_print_value(value, flags);
	return (i);
}
