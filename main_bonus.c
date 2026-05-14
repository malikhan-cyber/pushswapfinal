/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main_bonus.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/05/12 17:10:30 by kmurray        #+#    #+#                */
/*   Updated: 2026/05/13 18:49:59 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "operations/operations.h"
#include "stack/position_utils.h"
#include "stack/stack.h"
#include "gnl/get_next_line.h"

static int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	apply_input(t_stacks *stacks, char *instruction)
{
	if (ft_strncmp(instruction, "pa\n", 4) == 0)
		opp_push_lst(stacks, A);
	else if (ft_strncmp(instruction, "pb\n", 4) == 0)
		opp_push_lst(stacks, B);
	else if (ft_strncmp(instruction, "sa\n", 4) == 0)
		opp_swap_lst(stacks, A);
	else if (ft_strncmp(instruction, "sb\n", 4) == 0)
		opp_swap_lst(stacks, B);
	else if (ft_strncmp(instruction, "ss\n", 4) == 0)
		opp_swap_lst(stacks, BOTH);
	else if (ft_strncmp(instruction, "ra\n", 4) == 0)
		opp_rot_lst(stacks, A);
	else if (ft_strncmp(instruction, "rb\n", 4) == 0)
		opp_rot_lst(stacks, B);
	else if (ft_strncmp(instruction, "rr\n", 4) == 0)
		opp_rot_lst(stacks, BOTH);
	else if (ft_strncmp(instruction, "rra\n", 5) == 0)
		opp_rrot_lst(stacks, A);
	else if (ft_strncmp(instruction, "rrb\n", 5) == 0)
		opp_rrot_lst(stacks, B);
	else if (ft_strncmp(instruction, "rrr\n", 5) == 0)
		opp_rrot_lst(stacks, BOTH);
	else
		return (1);
	return (0);
}

// return 0 on OK
// return 1 on KO
// return 2 on Error
int	validate_input(t_stacks *stacks)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction)
	{
		if (apply_input(stacks, instruction) == 1)
		{
			free(instruction);
			return (2);
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	if (stacks->b.top)
		return (1);
	return (!is_stack_sorted(&stacks->a));
}

// return 0 on OK
// return 1 on KO
// return 2 on Error
int	check_sorted_list(t_stacks *stacks)
{
	char	*instruction;

	instruction = get_next_line(0);
	if (!instruction)
		return (0);
	if (apply_input(stacks, instruction) == 1)
	{
		free(instruction);
		return (2);
	}
	free(instruction);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			ok;

	if (argc <= 1)
		return (0);
	stacks = setup_stacks(argc - 1, argv + 1);
	if (!stacks.a.top)
		return (print_error());
	if (!is_stack_sorted(&stacks.a))
		ok = validate_input(&stacks);
	else
		ok = check_sorted_list(&stacks);
	stack_cleanup(stacks.a);
	stack_cleanup(stacks.b);
	if (ok == 0)
		write(1, "OK\n", 3);
	else if (ok == 1)
		write(1, "KO\n", 3);
	else if (ok == 2)
		return (print_error());
	return (ok);
}
