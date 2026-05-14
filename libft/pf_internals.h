/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_internals.h                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/01 15:56:09 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 16:02:20 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_INTERNALS_H
# define PF_INTERNALS_H

# include <stdarg.h>
# include <stdbool.h>

// NOTE: while this is only relevant for the bonus
// - it is always used to make implementation easier
// 
// left justified, aligns left, atleast size characters
// Not left justified, aligns right, atleast size characters
// zeroed aligns right, writes '0' up to size infront
// always sign, always include '-' and '+'
// new_sign if positive write ' ' otherwise write '-'
//		- for strings a space should also be written
// alternate
//		- for x, prefix the result with 0x
//		- for X, prefix the result with 0X
// precision, zeroed but left aligned?
typedef struct s_flags
{
	bool	left_justified;
	bool	zeroed;
	bool	always_sign;
	bool	neg_sign;
	bool	alternate;
	bool	precision_set;
	int		precision;
	int		size;
	int		fd;
}	t_flags;

// print functions for formatters
int		ft_print_char(const char c, int fd);
int		ft_print_string(const char *c, t_flags flags);
int		ft_print_hex_lower(const unsigned int i, t_flags flags);
int		ft_print_hex_upper(const unsigned int i, t_flags flags);
int		ft_print_int(const int i, t_flags flags);
int		ft_print_uint(const unsigned int uint, t_flags flags);
int		ft_print_float(const double v, t_flags flags);
int		ft_print_percent(int fd);
int		ft_print_pointer(const void *pointer, t_flags flags);

int		ft_handle_value(char **v, va_list values, int fd);

// for initializing flags
t_flags	init_flags(int fd);

// for printing and returning the printed len
// -1 for errors
int		pf_putstr(const char *s, int fd);
int		pf_putchar(const char c, int fd);

// just a max function
int		max(const int lhs, const int rhs);
int		min(const int lhs, const int rhs);

# ifdef PRINTF_BONUS

int		ft_len_char(void);
int		ft_len_string(const char *string, t_flags flags);
int		ft_len_hex_lower(const unsigned int i, t_flags flags);
int		ft_len_hex_upper(const unsigned int i, t_flags flags);
int		ft_len_int(const int i, t_flags flags);
int		ft_len_uint(const unsigned int uint, t_flags flags);
int		ft_len_float(const double v, t_flags flags);
int		ft_len_percent(void);
int		ft_len_pointer(const void *pointer);
# endif
#endif
