/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_put_fd.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/16 18:03:06 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/18 12:10:05 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	long	size;
	long	num;
	char	c;

	num = n;
	sign = -(n < 0) * 2 + 1;
	if (n < 0)
		write(fd, "-", 1);
	size = 1;
	while ((size * 10) <= (num * sign))
		size *= 10;
	while ((size > 0))
	{
		c = (num / size) * sign + '0';
		write(fd, &c, 1);
		num %= size * sign;
		size /= 10;
	}
}
