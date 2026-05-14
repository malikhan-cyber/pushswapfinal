/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_is_char.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/09 17:32:46 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/18 13:20:16 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

// checks if c is an alphanumeric character
int	ft_isalpha(int c)
{
	return (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')));
}

// checks if c is a digit
int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

// checks if c is a digit or an alphanumeric character
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// checks if c is ascii
int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 127));
}

// checks if c is printable
int	ft_isprint(int c)
{
	return ((c >= ' ') && (c <= '~'));
}
