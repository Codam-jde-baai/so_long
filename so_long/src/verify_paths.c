/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   verify_paths.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:45:35 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/26 00:41:05 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	map_flood(t_map *mapstruct, int x, int y);
static void	free_mapstruct(t_map *tempmap);
static char	**copy_map(t_map *mapstruct);

void	verify_paths(t_map *mapstruct)
{
	t_map	*tempmap;
	char	**copy;

	copy = copy_map(mapstruct);
	if (!copy)
		solong_error("Failure to malloc a map copy in verify_paths");
	tempmap = init_map(copy, mapstruct->width);
	if (!tempmap)
		solong_error("Failure to init mapstruct for verify_paths");
	map_flood(tempmap, mapstruct->player_x, mapstruct->player_y);
	if (tempmap->collectables != mapstruct->collectables || tempmap->exit != 1)
		solong_error("Player can not reach collectables and or exit");
	free_mapstruct(tempmap);
}

void	map_flood(t_map *mapstruct, int x, int y)
{
	if (x < 0 || x >= mapstruct->width || y < 0 || y >= mapstruct->height)
		return ;
	if (mapstruct->map[y][x] == '1' || mapstruct->map[y][x] == 'V')
		return ;
	if (mapstruct->map[y][x] == 'C')
		mapstruct->collectables++;
	else if (mapstruct->map[y][x] == 'E')
		mapstruct->exit++;
	mapstruct->map[y][x] = 'V';
	map_flood(mapstruct, x + 1, y);
	map_flood(mapstruct, x - 1, y);
	map_flood(mapstruct, x, y + 1);
	map_flood(mapstruct, x, y - 1);
}

static void	free_mapstruct(t_map *mapstruct)
{
	int	i;

	if (mapstruct == NULL)
		return ;
	if (mapstruct->map != NULL)
	{
		i = 0;
		while (i <= mapstruct->height)
		{
			free(mapstruct->map[i]);
			i++;
		}
		free(mapstruct->map);
	}
	free(mapstruct);
}

static char	**copy_map(t_map *mapstruct)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (mapstruct->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i <= mapstruct->height - 1)
	{
		copy[i] = ft_strdup(mapstruct->map[i]);
		if (copy[i] == NULL)
		{
			while (i >= 0)
			{
				free(copy[i]);
				i--;
			}
			return (free(copy), NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
