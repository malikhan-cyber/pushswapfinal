/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   stack.h                                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/14 12:56:55 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/12 17:41:50 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "../libft/libft.h"
# define STACK_A_NAME 0
# define STACK_B_NAME 1

typedef struct s_list_contents
{
	int	value;
	int	index;
}	t_list_contents;

// the name of a stack
typedef enum s_stack_name
{
	A,
	B,
	BOTH,
}	t_stack_name;

// a stack, the elements are linked from the top to the bottom
// `name` should be either 'a' or 'b'
typedef struct s_stack
{
	t_stack_name	name;
	t_list			*top;
	t_list			*bottom;
}	t_stack;

// the `sorting_strategy` should be statically allocated (using a literal)
typedef struct s_sorting_info
{
	float	init_disorder;
	char	*sorting_strategy;
	int		operations;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_sorting_info;

// a stack, the elements are linked from the top to the bottom
typedef struct s_stacks
{
	t_sorting_info	info;
	t_stack			a;
	t_stack			b;
}	t_stacks;

// cleanup a stack (free it)
t_stack			stack_cleanup(t_stack stack);
// create a new empty stack
t_stack			new_stack(t_stack_name name);
t_stacks		setup_stacks(int argc, char **argv);
t_list_contents	new_contents(int value, int index);
t_stack			*get_stack(t_stacks *stacks, t_stack_name name);

float			complexity(t_stack a);
#endif
