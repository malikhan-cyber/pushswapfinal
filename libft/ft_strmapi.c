/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strmapi.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/16 16:46:58 by kmurray        #+#    #+#                */
/*   Updated: 2026/03/20 12:56:37 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	int		i;

	temp = ft_strdup(s);
	if (temp == NULL)
		return (NULL);
	i = -1;
	while (temp[++i])
		temp[i] = f(i, temp[i]);
	return (temp);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = -1;
	while (s[++i])
		f(i, s + i);
}
