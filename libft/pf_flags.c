/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_flags.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/08 16:39:04 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:18:55 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "pf_internals.h"
#ifdef PRINTF_BONUS
# include "libft.h"
#endif

// initializes a flag struct
// not marked as bonus to make implementation easier
t_flags	init_flags(int fd)
{
	t_flags	flags;

	flags.left_justified = false;
	flags.zeroed = false;
	flags.alternate = false;
	flags.neg_sign = false;
	flags.always_sign = false;
	flags.precision = 1;
	flags.precision_set = false;
	flags.size = 0;
	flags.fd = fd;
	return (flags);
}

#ifdef PRINTF_BONUS
// returns the precision and advances the pointer
// assumes formatter is at '.'
void	set_precision(char *formatter, t_flags *flags)
{
	flags->precision = ft_atoi(formatter + 1);
	flags->precision_set = true;
}

// gets the flags of the formatter, 
// `format_string` should be the character after the '%'
t_flags	get_flags(char *formatter, int fd)
{
	t_flags	flags;

	flags = init_flags(fd);
	while (true)
	{
		if (formatter[0] == '-')
			flags.left_justified = true;
		else if (formatter[0] == '0')
			flags.zeroed = true;
		else if (formatter[0] == '#')
			flags.alternate = true;
		else if (formatter[0] == ' ')
			flags.neg_sign = true;
		else if (formatter[0] == '+')
			flags.always_sign = true;
		else
			break ;
		formatter++;
	}
	flags.size = ft_atoi(formatter);
	while ((formatter[0] >= '0') && (formatter[0] <= '9'))
		formatter++;
	if (formatter[0] == '.')
		set_precision(formatter, &flags);
	return (flags);
}

#endif
