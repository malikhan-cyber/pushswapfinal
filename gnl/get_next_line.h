/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kian@student.codam.nl>               +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/23 12:53:08 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/03 13:05:00 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

// utils
size_t	gnl_strlen(const char *s);
char	*gnl_strdup(const char *s);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
int		gnl_expand_buffer(char **string);
char	*gnl_shrink_to_fit(char *string);
#endif
