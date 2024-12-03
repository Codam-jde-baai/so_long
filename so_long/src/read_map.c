/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 20:42:53 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/26 00:36:19 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	count_lines(char *filename);

/* reads the file from filename and stores the lines in a 2D array */
char	**read_map(char *filename)
{
	int		fd;
	char	**map;
	int		rows;
	int		i;

	rows = count_lines(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		solong_error("Error with open() the second time, weird");
	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		solong_error("Malloc error");
	i = 0;
	while (i <= rows)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

static int	count_lines(char *filename)
{
	int		fd;
	int		i;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		solong_error("Could not open file, check name/permissions");
	i = 0;
	while (true)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		free (temp);
		i++;
	}
	close(fd);
	if (i == 0)
		solong_error("File appears empty, please check map");
	return (i);
}
