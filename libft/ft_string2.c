/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_string2.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/11 13:34:06 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/20 12:49:09 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

// finds substring `little` in `big` doesnt search for 
// more than `len` characters in `big`
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	i = 0;
	while ((i < len) && *big)
	{
		j = 0;
		while ((i + j < len) && (little[j] == big[j]))
		{
			if (little[j + 1] == '\0')
				return ((char *)big);
			j++;
		}
		big++;
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	min(const size_t l, const size_t r)
{
	if (l < r)
		return (l);
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (start >= ft_strlen(s))
	{
		new = malloc(1);
		if (new)
			new[0] = '\0';
		return (new);
	}
	if (len == SIZE_MAX)
		len--;
	new = malloc(min(len, (size_t)ft_strlen(s) - (size_t)start) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, &s[start], len + 1);
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, len);
	ft_strlcat(new, s2, len);
	return (new);
}
