/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_formatting_bonus.h                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/07 18:00:17 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 13:19:04 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FORMATTING_BONUS_H
# define PF_FORMATTING_BONUS_H
# include <stdbool.h>
# include "pf_value_types.h"
# include "pf_internals.h"

// formatting
int		print_value_formatted(char *v, t_formatter value, int fd);

// alignment_bonus.c
int		ft_left_justify(t_flags flags, t_formatter value);
int		ft_right_justified(t_flags flags, t_formatter value);
int		ft_right_zeroed(t_flags flags, t_formatter value);

// format_variants.c
int		print_variant(t_flags flags, t_formatter value);

t_flags	get_flags(char *formatter, int fd);

// these exist anyway but only need to be public if its bonus
int		ft_print_value(t_formatter formatter, t_flags flags);
int		ft_value_len(t_formatter formatter, t_flags flags);

#endif
