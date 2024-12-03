/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_structs.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 14:37:24 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/28 14:11:27 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_instance	*load_player(mlx_t *mlx, t_instance *images);

t_map	*init_map(char **mapinput, int widthinput)
{
	t_map	*mapstruct;
	int		i;

	mapstruct = malloc(sizeof(t_map));
	if (!mapstruct)
		solong_error("Mapstruct malloc failure");
	mapstruct->map = mapinput;
	mapstruct->collectables = 0;
	mapstruct->exit = 0;
	mapstruct->player = 0;
	mapstruct->player_x = 0;
	mapstruct->player_y = 0;
	mapstruct->width = widthinput;
	if (mapinput != NULL)
	{
		i = 0;
		while (mapstruct->map[i] != NULL)
			i++;
		mapstruct->height = i;
	}
	return (mapstruct);
}

t_game	*init_game(t_map *mapstruct)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		solong_error("malloc error init-game");
	game->mlx = NULL;
	game->mapstruct = mapstruct;
	game->images = NULL;
	game->collected = 0;
	game->exit_open = false;
	game->player_x = mapstruct->player_x;
	game->player_y = mapstruct->player_y;
	game->moves = 0;
	game->moves_img = NULL;
	game->collected_img = NULL;
	return (game);
}

t_instance	*load_png(mlx_t *mlx)
{
	t_instance	*images;

	images = malloc(sizeof(t_instance));
	if (!images)
		solong_error("t_instance Malloc error");
	images->background = load_texture(mlx, "images/background.png");
	images->collectable = load_texture(mlx, "images/collectable.png");
	images->exit_closed = load_texture(mlx, "images/exit_closed.png");
	images->exit_open = load_texture(mlx, "images/exit_open.png");
	images->wall = load_texture(mlx, "images/wall.png");
	images->statusbar = load_texture(mlx, "images/statusbar.png");
	images->statusbar_left = load_texture(mlx, "images/statusbar_left.png");
	images->statusbar_right = load_texture(mlx, "images/statusbar_right.png");
	load_player(mlx, images);
	return (images);
}

t_instance	*load_player(mlx_t *mlx, t_instance *images)
{
	images->player_up = mlx_load_png("images/player_up.png");
	if (!images->player_up)
		solong_error("mlx_load_png error");
	images->player_down = mlx_load_png("images/player_down.png");
	if (!images->player_down)
		solong_error("mlx_load_png error");
	images->player_left = mlx_load_png("images/player_left.png");
	if (!images->player_left)
		solong_error("mlx_load_png error");
	images->player_right = mlx_load_png("images/player_right.png");
	if (!images->player_right)
		solong_error("mlx_load_png error");
	images->player = mlx_texture_to_image(mlx, images->player_up);
	if (!images->player)
		solong_error("Error converting texture to image");
	free(images->player->pixels);
	images->player->pixels = images->player_up->pixels;
	images->last_dir = 'u';
	return (images);
}
