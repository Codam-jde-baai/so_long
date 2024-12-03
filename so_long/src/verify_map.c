/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 12:56:44 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/26 00:40:09 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	map_length(char **map, size_t len);
static bool	map_walled(char **map, int width);
static bool	map_content(t_map *map);
static void	map_line(char *line, int y, t_map *mapstruct);

/* verifies the content of the map and returns t_map with all the map info*/
t_map	*verify_map(char **map)
{
	size_t		len;
	t_map		*mapstruct;

	len = ft_strlen(map[0]);
	if (len < 3)
		solong_error("map needs to have a minimum width of 3");
	if (!map_length(map, len))
		solong_error("Not all lines on the map are of equal length");
	if (!map_walled(map, len - 1))
		solong_error("Map is not surrounded with walls, please check map");
	mapstruct = init_map(map, len - 1);
	if (!map_content(mapstruct))
		solong_error("Map is only allowed to have 1 player and 1 exit"); // make error messages more specific by returning int and for each int a msg
	return (mapstruct);
}

/* function to check if lines are of equal length,
last line is one character shorter */
bool	map_length(char **map, size_t len)
{
	int	rows;
	int	i;

	rows = 0;
	while (map[rows] != NULL)
		rows++;
	if (rows < 2)
		solong_error("map needs to have a minimum height of 3");
	i = 1;
	while (i < rows - 1)
	{
		if (ft_strlen(map[i]) != len)
			return (false);
		i++;
	}
	if (ft_strlen(map[i]) != len - 1)
		return (false);
	return (true);
}

/* checks if the map is surrounded with walls(1 character) */
static bool	map_walled(char **map, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] == '1')
		j++;
	if (j != width)
		return (false);
	i = 1;
	while (map[i + 1] != NULL)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (false);
		i++;
	}
	j = 0;
	while (map[i][j] == '1')
		j++;
	if (j != width)
		return (false);
	return (true);
}

/* checks if the map content only contains 1-0-P-C-E 
and verifies their amounts */
static bool	map_content(t_map *mapstruct)
{
	int	y;

	y = 1;
	while (mapstruct->map[y] != NULL)
	{
		map_line(mapstruct->map[y], y, mapstruct);
		y++;
	}
	if (mapstruct->player != 1 || mapstruct->exit != 1
		|| mapstruct->collectables < 1)
		return (false);
	return (true);
}

static void	map_line(char *row, int y, t_map *mapstruct)
{
	int	x;

	x = 1;
	while (row[x] != '\0')
	{
		if (row[x] == 'P')
		{
			mapstruct->player++;
			mapstruct->player_x = x;
			mapstruct->player_y = y;
		}
		else if (row[x] == 'E')
			mapstruct->exit++;
		else if (row[x] == 'C')
			mapstruct->collectables++;
		else if (row[x] != '0' && row[x] != '1' && row[x] != '\n')
			solong_error("only characters: 1-0-P-C-E and enter");
		x++;
	}
}
