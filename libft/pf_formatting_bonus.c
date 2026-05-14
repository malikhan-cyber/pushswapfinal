/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_formatting_bonus.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/03 17:58:08 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:19:33 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "pf_internals.h"
#include "pf_formatting_bonus.h"
#include "pf_value_types.h"
#include "libft.h"

// align and format the value
// `v` is the pattern from after the %
// first set
// * (nothing) for right justified
// '-' for left justified
// '0' right justified with '0' padding
// '.' max number of digits for 'x' 'X' 'i' 'd' 's' formatters
//
// second set
// '#' .0 values?
// ' ' if no sign is displayed a blank space is written
// '+' always display sign
int	print_value_formatted(char *v, t_formatter value, int fd)
{
	t_flags	flags;

	flags = get_flags(v, fd);
	if (flags.left_justified)
		return (ft_left_justify(flags, value));
	else if (flags.zeroed)
		return (ft_right_zeroed(flags, value));
	return (ft_right_justified(flags, value));
}
