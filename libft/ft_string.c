/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_string.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/10 12:49:41 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/20 16:35:59 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copies src to dst
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1 < size))
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

// concatenates src to the end of dst
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && (len < size))
		len++;
	i = 0;
	while (((len + i + 1) < size) && src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	if ((len + i) < size)
		dst[len + i] = '\0';
	return (len + ft_strlen(src));
}

// finds the *first* occurance of `1c` in `s`
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

// finds the *last* occurance of `c` in `s`
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// compare the first N characters of the string
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
