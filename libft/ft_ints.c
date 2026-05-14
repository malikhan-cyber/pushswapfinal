/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_ints.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/12 15:19:53 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/23 13:51:12 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

static bool	is_whitespace(char c)
{
	return ((c == ' ')
		|| (c == '\n')
		|| (c == '\v')
		|| (c == '\f')
		|| (c == '\r')
		|| (c == '\t'));
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	value;

	i = 0;
	while (is_whitespace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	value = 0;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		value = value * 10 + (nptr[i] - '0') * sign;
		i++;
	}
	return (value);
}

static size_t	int_length(int n)
{
	size_t	chars;

	chars = 1;
	if (n < 0)
		chars++;
	while ((n < -9) || (n > 9))
	{
		n /= 10;
		chars++;
	}
	return (chars);
}

static char	*ft_itoa_inner(char *number, long n)
{
	if (n >= 10)
		number = ft_itoa_inner(number, n / 10);
	number[0] = (n % (10)) + '0';
	return (number + 1);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*number;

	len = int_length(n) + 1;
	number = malloc(len);
	if (number == NULL)
		return (NULL);
	if (n == 0)
		number[0] = '0';
	else if (n < 0)
	{
		number[0] = '-';
		ft_itoa_inner(number + 1, -((long)n));
	}
	else
		ft_itoa_inner(number, n);
	number[len - 1] = '\0';
	return (number);
}
