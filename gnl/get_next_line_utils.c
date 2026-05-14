/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line_utils.c                               :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kian@student.codam.nl>               +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/23 12:52:56 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/03 13:02:43 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

// the rate at which buffer expansions are done
#define EXPANSIONRATE 2

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
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
	return (gnl_strlen(src));
}

char	*gnl_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = gnl_strlen(s) + 1;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	gnl_strlcpy(new, s, len);
	return (new);
}

// expands the buffer of string (by two) and returns the new length
// if allocating the new buffer fails, nothing is done and -1 is returned
ssize_t	gnl_expand_buffer(char **string)
{
	size_t	len;
	char	*new;

	if (*string == NULL)
		return (0);
	len = gnl_strlen(*string) + 1;
	new = malloc(len * EXPANSIONRATE);
	if (new == NULL)
		return (-1);
	gnl_strlcpy(new, *string, len);
	free(*string);
	*string = new;
	return (len * EXPANSIONRATE);
}

// copies the string into a different string with an exact size, 
// then frees the old one
char	*gnl_shrink_to_fit(char *string)
{
	char	*new;

	if (string == NULL)
		return (NULL);
	new = gnl_strdup(string);
	if (new == NULL)
		return (string);
	free(string);
	return (new);
}
