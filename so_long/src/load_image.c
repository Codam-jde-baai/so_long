/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 14:37:24 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/28 14:55:02 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	place_specials(t_game *game);
static void	place_line(t_game *game, int y, int x);

void	place_tiles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->mapstruct->height)
	{
		x = 0;
		while (x < game->mapstruct->width)
		{
			if (mlx_image_to_window(game->mlx, game->images->background,
					x * PIXEL, PIXEL + (y * PIXEL)) < 0)
				solong_error("Error mlx_image_to_window background");
			x++;
		}
		y++;
	}
	place_specials(game);
}

static void	place_specials(t_game *game)
{
	int	y;
	int	x;

	if (mlx_image_to_window(game->mlx, game->images->statusbar_left,
			(0 * PIXEL), 0) < 0)
		solong_error("Error mlx_image_to_window statusbar");
	x = 1;
	while (x < game->mapstruct->width - 1)
	{
		if (mlx_image_to_window(game->mlx, game->images->statusbar,
				(x * PIXEL), 0) < 0)
			solong_error("Error mlx_image_to_window statusbar");
		x++;
	}
	if (mlx_image_to_window(game->mlx, game->images->statusbar_right,
			(x * PIXEL), 0) < 0)
		solong_error("Error mlx_image_to_window statusbar");
	y = 0;
	while (y < game->mapstruct->height)
	{
		place_line(game, y, 0);
		y++;
	}
}

static void	place_line(t_game *game, int y, int x)
{
	while (x < game->mapstruct->width)
	{
		if (game->mapstruct->map[y][x] == '1')
			if (mlx_image_to_window(game->mlx, game->images->wall,
					(x * PIXEL), PIXEL + (y * PIXEL)) < 0)
				solong_error("Error mlx_image_to_window wall");
		if (game->mapstruct->map[y][x] == 'C')
			if (mlx_image_to_window(game->mlx, game->images->collectable,
					x * PIXEL, PIXEL + (y * PIXEL)) < 0)
				solong_error("Error mlx_image_to_window collectable");
		if (game->mapstruct->map[y][x] == 'E')
		{
			if (mlx_image_to_window(game->mlx, game->images->exit_open,
					x * PIXEL, PIXEL + (y * PIXEL)) < 0)
				solong_error("Error mlx_image_to_window exit_open");
			if (mlx_image_to_window(game->mlx, game->images->exit_closed,
					x * PIXEL, PIXEL + (y * PIXEL)) < 0)
				solong_error("Error mlx_image_to_window exit_closed");
		}
		if (game->mapstruct->map[y][x] == 'P')
			if (mlx_image_to_window(game->mlx, game->images->player,
					x * PIXEL, PIXEL + (y * PIXEL)) < 0)
				solong_error("Error mlx_image_to_window Player");
		x++;
	}
}
