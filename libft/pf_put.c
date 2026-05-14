/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   pf_put.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kmurray@student.codam.nl>            +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/17 13:22:44 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/21 12:47:00 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	pf_putstr(const char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}

int	pf_putchar(const char c, int fd)
{
	return (write(fd, &c, 1));
}
