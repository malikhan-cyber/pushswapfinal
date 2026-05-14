/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_string.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/31 13:52:58 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:02:21 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "pf_internals.h"

int	ft_len_string(const char *string, t_flags flags)
{
	if (!string)
	{
		if (flags.precision_set && (flags.precision < 6))
			return (0);
		return (6);
	}
	if ((string[0] == '\0') && flags.neg_sign)
		return (0);
	if (!flags.precision_set)
		flags.precision = INT_MAX;
	return (min(ft_strlen(string), flags.precision));
}

int	ft_print_string(const char *string, t_flags flags)
{
	int	len;

	if (!string)
	{
		if (flags.precision_set && (flags.precision < 6))
			return (0);
		if (pf_putstr("(null)", flags.fd) == -1)
			return (-1);
		return (6);
	}
	if ((string[0] == '\0') && flags.neg_sign)
		return (0);
	if (flags.precision_set)
		len = min(ft_strlen(string), flags.precision);
	else
		len = ft_strlen(string);
	if (pf_putstr(string, flags.fd) == -1)
		return (-1);
	return (ft_len_string(string, flags));
}
