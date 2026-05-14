/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_case.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/10 16:11:29 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/18 13:20:13 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

// converts the character to upper case if it is lowercase
int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	return (c);
}

// converts the character to upper case if it is lowercase
int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	return (c);
}
