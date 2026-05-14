/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_base.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/01 15:57:25 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:03:06 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINT_BASE_H
# define PF_PRINT_BASE_H
# include <stddef.h>
# include "pf_internals.h"

int	put_base(const unsigned int num, const char *base,
		const int radix, const t_flags flags);
int	put_base_size_t(const size_t num, const char *base,
		const size_t radix, const t_flags flags);

// an integer length function
int	ft_len_base(unsigned int num, const int radix, const int min);
int	ft_len_size_t(size_t num, const size_t radix, const int min);

// just because its useful
int	max(int lhs, int rhs);
#endif
