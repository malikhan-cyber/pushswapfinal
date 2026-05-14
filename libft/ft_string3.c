/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_string3.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/16 12:46:33 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/20 13:08:21 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft.h"

// duplicates string `s`
char	*ft_strdup(const char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(s) + 1;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s, len);
	return (new);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	strlen;

	strlen = ft_strlen(s1);
	start = 0;
	while (start < strlen)
	{
		if (ft_strchr(set, s1[start]) == NULL)
			break ;
		start++;
	}
	end = strlen;
	while (end >= 0)
	{
		if (ft_strchr(set, s1[end]) == NULL)
			break ;
		end--;
	}
	return (ft_substr(s1, start, end - start + 1));
}

static int	words(const char *str, char sep)
{
	int		c;
	int		i;
	bool	was_word;
	int		len;

	len = ft_strlen(str);
	i = 0;
	c = 0;
	was_word = false;
	while (i < len)
	{
		if (was_word && (sep == str[i]))
		{
			c++;
		}
		was_word = str[i] != sep;
		i++;
	}
	if (was_word)
		c++;
	return (c);
}

// returns a nul ptr
static char	**split_cleanup(char **strings)
{
	int	i;

	i = 0;
	while (strings[i] != NULL)
		free(strings[i++]);
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start_word;
	char	**strings;
	size_t	word_i;

	word_i = 0;
	i = 0;
	start_word = 0;
	strings = malloc((words(s, c) + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (((s[i] == c) || (s[i] == '\0')) && ((start_word) != (i)))
		{
			strings[word_i++] = ft_substr(s, start_word, i - start_word);
			if (strings[word_i - 1] == NULL)
				return (split_cleanup(strings));
		}
		if ((s[i] == c) || (s[i] == '\0'))
			start_word = i + 1;
		i++;
	}
	strings[word_i] = NULL;
	return (strings);
}
