/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_print_float_inner.h                              :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/22 14:15:24 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/22 15:30:17 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINT_FLOAT_INNER_H
# define PF_PRINT_FLOAT_INNER_H

int	ft_len_integer_part(double v);
int	print_fractional_part(double v, t_flags flags);

int	ft_len_fractional_part(t_flags flags);
int	print_integer_part(double v, t_flags flags);

#endif
