/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_printf.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/30 18:20:19 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/04 17:21:39 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "pf_internals.h"

// prints a section of pattern, both the bit between start and end
// and the value at end
// `end` MUST be at `%`, it will be incremented 
//	to the end of the formatting value
static int	print_pattern(char *start, char **end, va_list values, int fd)
{
	int	len;

	if (*end)
	{
		len = *end - start;
		if (write(fd, start, *end - start) == -1)
			return (-1);
		len += ft_handle_value(end, values, fd);
	}
	else
	{
		len = ft_strlen(start);
		return (write(fd, start, ft_strlen(start)));
	}
	return (len);
}

// prints a pattern and formatted values
// returns the length of the string it printed
int	ft_printf(const char *pattern, ...)
{
	va_list	values;
	char	*pattern_cur;
	char	*pattern_prev;
	int		len;
	int		added_len;

	len = 0;
	pattern_prev = (char *)pattern;
	pattern_cur = (char *)pattern;
	va_start(values, pattern);
	if (!pattern)
		return (-1);
	while (pattern_cur)
	{
		pattern_cur = ft_strchr(pattern_prev, '%');
		added_len = print_pattern(pattern_prev, &pattern_cur, values, 1);
		if (added_len == -1)
			return (-1);
		len += added_len;
		pattern_prev = pattern_cur + 1;
	}
	va_end(values);
	return (len);
}

// prints a pattern and formatted values
// returns the length of the string it printed
int	ft_fprintf(int fd, const char *pattern, ...)
{
	va_list	values;
	char	*pattern_cur;
	char	*pattern_prev;
	int		len;
	int		added_len;

	len = 0;
	pattern_prev = (char *)pattern;
	pattern_cur = (char *)pattern;
	va_start(values, pattern);
	if (!pattern)
		return (-1);
	while (pattern_cur)
	{
		pattern_cur = ft_strchr(pattern_prev, '%');
		added_len = print_pattern(pattern_prev, &pattern_cur, values, fd);
		if (added_len == -1)
			return (-1);
		len += added_len;
		pattern_prev = pattern_cur + 1;
	}
	va_end(values);
	return (len);
}
