/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_mem_cmp.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/17 18:39:00 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/23 12:40:37 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// scan the first `n` bytes of `s` for `c`
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

// compare the first `n` bytes of `s1` and `s2`
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s1)[i] != ((char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// allocates a buffer of size elements of nmemb
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	buf_size;
	void	*buf;

	buf_size = nmemb * size;
	if ((size != 0) && (nmemb != 0))
	{
		if (((buf_size / size) != nmemb))
		{
			return (NULL);
		}
	}
	buf = malloc(buf_size);
	if (buf == NULL)
		return (NULL);
	if (buf_size > 0)
		ft_bzero(buf, buf_size);
	return (buf);
}
