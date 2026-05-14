/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_values.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/03 18:00:16 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 16:03:03 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "pf_value_types.h"
#include "pf_internals.h"
#ifdef PRINTF_BONUS
# include "pf_formatting_bonus.h"
#endif

// gets the next value, as the right type and returned as a null pointer
t_formatter	ft_get_value(char v, va_list values)
{
	if (v == 'c')
		return ((t_formatter){CHAR, .value.character = va_arg(values, int)});
	else if (v == 's')
		return ((t_formatter){STRING, .value.string = va_arg(values, char *)});
	else if (v == 'x')
		return ((t_formatter){LHEX, .value.sint = va_arg(values, int)});
	else if (v == 'X')
		return ((t_formatter){UHEX, .value.sint = va_arg(values, int)});
	else if (v == 'd')
		return ((t_formatter){DECIMAL, .value.sint = va_arg(values, int)});
	else if (v == 'i')
		return ((t_formatter){INTEGER, .value.sint = va_arg(values, int)});
	else if (v == 'u')
		return ((t_formatter){
			UINT, .value.uint = va_arg(values, unsigned int)});
	else if (v == '%')
		return ((t_formatter){.type = PERCENT});
	else if (v == 'f')
		return ((t_formatter){FLOAT, .value.floating = va_arg(values, double)});
	else if (v == 'p')
		return ((t_formatter){
			POINTER, .value.pointer = va_arg(values, void *)});
	else
		return ((t_formatter){.type = NONE});
}

// print the values, according to the formatter
int	ft_print_value(t_formatter formatter, t_flags flags)
{
	if (formatter.type == CHAR)
		return (ft_print_char(formatter.value.character, flags.fd));
	else if (formatter.type == STRING)
		return (ft_print_string(formatter.value.string, flags));
	else if (formatter.type == LHEX)
		return (ft_print_hex_lower(formatter.value.sint, flags));
	else if (formatter.type == UHEX)
		return (ft_print_hex_upper(formatter.value.sint, flags));
	else if (formatter.type == DECIMAL)
		return (ft_print_int(formatter.value.sint, flags));
	else if (formatter.type == INTEGER)
		return (ft_print_int(formatter.value.sint, flags));
	else if (formatter.type == UINT)
		return (ft_print_uint(formatter.value.uint, flags));
	else if (formatter.type == FLOAT)
		return (ft_print_float(formatter.value.floating, flags));
	else if (formatter.type == PERCENT)
		return (ft_print_percent(flags.fd));
	else if (formatter.type == POINTER)
		return (ft_print_pointer(formatter.value.pointer, flags));
	else
		return (-1);
}

// print a value according to the formatter
// `v` is at the percentage sign
// 
//
// "where the stacks diverge"
// two functions of which one gets compiled based on if it is the bonus
// this exists to have a common interface in print_pattern() 
// while the code diverges
#ifdef PRINTF_BONUS
// the bonus variant, calls the print_value_formatted() function
// which will do formatting 
int	ft_handle_value(char **v, va_list values, int fd)
{
	t_formatter	value;
	char		*format_start;

	(*v)++;
	format_start = *v;
	while (((*v[0] >= '0') && (*v[0] <= '9'))
		|| (*v[0] == '-')
		|| (*v[0] == '0')
		|| (*v[0] == '.')
		|| (*v[0] == '#')
		|| (*v[0] == ' ')
		|| (*v[0] == '+'))
		(*v)++;
	value = ft_get_value(*v[0], values);
	return (print_value_formatted(format_start, value, fd));
}
#else

// this function does NOT handle the alignment character
int	ft_handle_value(char **v, va_list values, int fd)
{
	t_formatter	value;

	(*v)++;
	value = ft_get_value(*v[0], values);
	return (ft_print_value(value, init_flags(fd)));
}
#endif

#ifdef PRINTF_BONUS
// print a value according to the formatter
// `v` is the character that says whay the formatter is
// this function does NOT handle the alignment character
// `value` SHOULD be the right type for `v`
int	ft_value_len(t_formatter formatter, t_flags flags)
{
	if (formatter.type == CHAR)
		return (ft_len_char());
	else if (formatter.type == STRING)
		return (ft_len_string(formatter.value.string, flags));
	else if (formatter.type == LHEX)
		return (ft_len_hex_lower(formatter.value.sint, flags));
	else if (formatter.type == UHEX)
		return (ft_len_hex_upper(formatter.value.sint, flags));
	else if (formatter.type == DECIMAL)
		return (ft_len_int(formatter.value.sint, flags));
	else if (formatter.type == INTEGER)
		return (ft_len_int(formatter.value.sint, flags));
	else if (formatter.type == UINT)
		return (ft_len_uint(formatter.value.uint, flags));
	else if (formatter.type == FLOAT)
		return (ft_len_float(formatter.value.floating, flags));
	else if (formatter.type == PERCENT)
		return (ft_len_percent());
	else if (formatter.type == POINTER)
		return (ft_len_pointer(formatter.value.pointer));
	else
		return (-1);
}
#endif
