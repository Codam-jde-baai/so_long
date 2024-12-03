/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:55:24 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/26 01:16:37 by juliusdebaa   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	sl_move_up(t_game *game);
static void	sl_move_down(t_game *game);
static void	sl_move_left(t_game *game);
static void	sl_move_right(t_game *game);

void	sl_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		sl_move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		sl_move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		sl_move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		sl_move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
}

static void	sl_move_up(t_game *game)
{
	player_dir(game, 'u');
	if (game->mapstruct->map[game->player_y - 1][game->player_x] == '1'
		|| (game->mapstruct->map[game->player_y - 1][game->player_x]
			== 'E' && game->exit_open == false))
		return ;
	else
	{
		game->moves++;
		game->player_y--;
		if (game->mapstruct->map[game->player_y][game->player_x] == 'C')
		{
			game->mapstruct->map[game->player_y][game->player_x] = '0';
			disable_collectable(game, game->player_x, game->player_y);
			game->collected++;
		}
		if (game->mapstruct->map[game->player_y][game->player_x] ==
			'E' && game->exit_open == true)
			finish_game(game);
		game->images->player->instances[0].y -= (1 * PIXEL);
		update_game(game);
	}
}

static void	sl_move_down(t_game *game)
{
	player_dir(game, 'd');
	if (game->mapstruct->map[game->player_y + 1][game->player_x] == '1'
		|| (game->mapstruct->map[game->player_y + 1][game->player_x]
			== 'E' && game->exit_open == false))
		return ;
	else
	{
		game->moves++;
		game->player_y++;
		if (game->mapstruct->map[game->player_y][game->player_x] == 'C')
		{
			game->mapstruct->map[game->player_y][game->player_x] = '0';
			disable_collectable(game, game->player_x, game->player_y);
			game->collected++;
		}
		if (game->mapstruct->map[game->player_y][game->player_x] ==
			'E' && game->exit_open == true)
			finish_game(game);
		game->images->player->instances[0].y += (1 * PIXEL);
		update_game(game);
	}
}

static void	sl_move_left(t_game *game)
{
	player_dir(game, 'l');
	if (game->mapstruct->map[game->player_y][game->player_x - 1] == '1'
		|| (game->mapstruct->map[game->player_y][game->player_x - 1] ==
			'E' && game->exit_open == false))
		return ;
	else
	{
		game->moves++;
		game->player_x--;
		if (game->mapstruct->map[game->player_y][game->player_x] == 'C')
		{
			game->mapstruct->map[game->player_y][game->player_x] = '0';
			disable_collectable(game, game->player_x, game->player_y);
			game->collected++;
		}
		if (game->mapstruct->map[game->player_y][game->player_x] ==
			'E' && game->exit_open == true)
			finish_game(game);
		game->images->player->instances[0].x -= 1 * PIXEL;
		update_game(game);
	}
}

static void	sl_move_right(t_game *game)
{
	player_dir(game, 'r');
	if (game->mapstruct->map[game->player_y][game->player_x + 1] == '1'
		|| (game->mapstruct->map[game->player_y][game->player_x + 1] ==
			'E' && game->exit_open == false))
		return ;
	else
	{
		game->moves++;
		game->player_x++;
		if (game->mapstruct->map[game->player_y][game->player_x] == 'C')
		{
			game->mapstruct->map[game->player_y][game->player_x] = '0';
			disable_collectable(game, game->player_x, game->player_y);
			game->collected++;
		}
		if (game->mapstruct->map[game->player_y][game->player_x] ==
			'E' && game->exit_open == true)
			finish_game(game);
		game->images->player->instances[0].x += 1 * PIXEL;
		update_game(game);
	}
}
