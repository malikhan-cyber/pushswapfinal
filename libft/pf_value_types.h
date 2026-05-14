/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_value_types.h                                    :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/06 14:50:20 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 16:01:31 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_VALUE_TYPES_H
# define PF_VALUE_TYPES_H

// these three types are used in ft_values.c
typedef enum e_format_type
{
	CHAR,
	STRING,
	LHEX,
	UHEX,
	DECIMAL,
	INTEGER,
	UINT,
	PERCENT,
	POINTER,
	FLOAT,
	NONE,
}	t_format_type;

typedef union u_format_value
{
	int				character;
	char			*string;
	int				sint;
	unsigned int	uint;
	void			*pointer;
	double			floating;
}	t_format_value;

typedef struct s_formatter
{
	t_format_type	type;
	t_format_value	value;
}	t_formatter;

#endif
