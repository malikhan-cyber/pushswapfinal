/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_max.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/17 15:14:35 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/17 15:16:40 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

int	max(const int lhs, const int rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}

int	min(int lhs, int rhs)
{
	if (lhs > rhs)
		return (rhs);
	return (lhs);
}
