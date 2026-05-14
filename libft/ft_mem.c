/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_mem.c                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/09 18:07:33 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/23 14:54:12 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((dest == NULL) && (src == NULL))
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// breaks if dest overlaps the end of source
// if src is within dest move backwards
void	*ft_memmove(void *dest, void *src, size_t n)
{
	int	i;

	if ((dest == NULL) && (src == NULL))
		return (dest);
	if ((dest > src))
	{
		i = n - 1;
		while (i >= 0)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i--;
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}
