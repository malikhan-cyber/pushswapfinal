/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: kmurray <kian@student.codam.nl>               +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/03/23 12:52:29 by kmurray        #+#    #+#                */
/*   Updated: 2026/04/03 13:01:47 by kmurray        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

// updates the buffer with more bytes
// returns true if there the buffer is not empty and false if it is
ssize_t	update_buffer(int fd, char	*buffer)
{
	ssize_t	bytes_read;
	size_t	i;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		i = 0;
	else
		i = (size_t)bytes_read;
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	return (bytes_read);
}

// returns the start of the string
// updates the buffer if required
// if that fails BUFFER_SIZE is returned
size_t	find_start(char *buffer, int fd)
{
	size_t	i;
	ssize_t	res;

	i = 0;
	while ((buffer[i] == '\0') && (i < BUFFER_SIZE))
		i++;
	if (i == BUFFER_SIZE)
	{
		res = update_buffer(fd, buffer);
		if (res == -1)
			return (BUFFER_SIZE);
		i = 0;
	}
	return (i);
}

// `line` is a pointer to the line being appended to
// `size` is the size of that string (capacity NOT length)
// `new` is the character that is added to it
// returns a pointer to the line or NULL on failure
// if it fails it will free *line
char	*add_char(char **line, size_t *size, char new)
{
	size_t	line_length;
	ssize_t	new_size;

	if (!*line)
	{
		*line = gnl_strdup("");
		*size = 0;
		if (!line)
			return (NULL);
	}
	line_length = gnl_strlen(*line);
	if (line_length + 1 >= *size)
	{
		new_size = gnl_expand_buffer(line);
		if (new_size == -1)
		{
			free(line);
			return (NULL);
		}
		*size = (size_t)new_size;
	}
	(*line)[line_length] = new;
	(*line)[line_length + 1] = '\0';
	return (*line);
}

char	*parse_line(char *buffer, char *line, size_t buf_i, int fd)
{
	size_t		line_size;

	line_size = 0;
	while (buffer[buf_i] != '\n')
	{
		if ((buf_i >= BUFFER_SIZE) || (buffer[buf_i] == '\0'))
		{
			if (update_buffer(fd, buffer) == -1)
			{
				free(line);
				return (NULL);
			}
			if (buffer[0] == '\0')
				return (line);
			buf_i = 0;
			continue ;
		}
		if (add_char(&line, &line_size, buffer[buf_i]) == NULL)
			return (NULL);
		buffer[buf_i++] = '\0';
	}
	if (add_char(&line, &line_size, buffer[buf_i]) == NULL)
		return (NULL);
	buffer[buf_i++] = '\0';
	return (line);
}

// gets the next line from the file descriptor
// returns NULL if there arent any lines left or allocating memory failed
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*line;
	ssize_t		buf_i;

	if (fd < 0)
		return (NULL);
	buf_i = find_start(buffer, fd);
	if ((buf_i == BUFFER_SIZE) || (buf_i == -1))
		return (NULL);
	line = NULL;
	line = parse_line(buffer, line, buf_i, fd);
	return (gnl_shrink_to_fit(line));
}
