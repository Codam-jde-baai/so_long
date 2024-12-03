/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 14:41:58 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/12/03 10:18:07 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define OPEN_MAX 1024

static char	*first_read(int fd);
static char	*getnl_loop(int fd, char *save, int readout);
static char	*getnl_save(char *buffer, char **save);
static int	find_n(const char *buffer);

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;

	if ((OPEN_MAX < fd || fd < 0) || BUFFER_SIZE < 1)
		return (NULL);
	if (save)
	{
		buffer = getnl_copy(save, getnl_strlen(save), &save);
		if (!buffer)
			return (NULL);
		if (find_n(buffer) == -1)
			buffer = getnl_loop(fd, buffer, BUFFER_SIZE);
	}
	else
		buffer = first_read(fd);
	if (!buffer)
		return (NULL);
	buffer = getnl_save(buffer, &save);
	if (!buffer)
		return (NULL);
	return (buffer);
}

/* initial read() */
static char	*first_read(int fd)
{
	int		nl;
	int		readout;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readout = read(fd, buffer, BUFFER_SIZE);
	if (readout == -1 || readout == 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[readout] = '\0';
	nl = find_n(buffer);
	if (nl != -1)
		return (buffer);
	return (getnl_loop(fd, buffer, BUFFER_SIZE));
}

/*loops through read() to find \n or NULL return */
static char	*getnl_loop(int fd, char *buffer, int readout)
{
	char	*new;

	new = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!new)
		return (free_return(&buffer));
	while (find_n(buffer) == -1 && readout == BUFFER_SIZE)
	{
		readout = read(fd, new, BUFFER_SIZE);
		if (readout == -1)
		{
			free(buffer);
			return (free_return(&new));
		}
		new[readout] = '\0';
		buffer = getnl_join(buffer, new, &buffer);
		if (!buffer)
			return (free_return(&new));
	}
	free(new);
	return (buffer);
}

/* saves remaining string past \n to save */
static char	*getnl_save(char *buffer, char **save)
{
	int	nl;

	nl = find_n(buffer);
	if (nl == -1 || (nl != -1 && buffer[nl + 1] == '\0'))
		return (buffer);
	*save = getnl_strdup(&buffer[nl + 1]);
	if (!*save)
		return (free_return(&buffer));
	return (getnl_copy(buffer, nl + 1, &buffer));
}

/* finds the first \n in a string, returns -1 otherwise */
static int	find_n(const char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (i);
	else
		return (-1);
}
