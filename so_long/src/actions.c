/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/24 11:34:08 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/28 14:43:30 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* changes the texture loaded to the image player */
void	player_dir(t_game *game, char dir)
{
	if (dir != game->images->last_dir)
	{
		if (dir == 'u')
		{
			game->images->player->pixels = game->images->player_up->pixels;
			game->images->last_dir = 'u';
		}
		else if (dir == 'd')
		{
			game->images->player->pixels = game->images->player_down->pixels;
			game->images->last_dir = 'd';
		}
		else if (dir == 'l')
		{
			game->images->player->pixels = game->images->player_left->pixels;
			game->images->last_dir = 'l';
		}
		else
		{
			game->images->player->pixels = game->images->player_right->pixels;
			game->images->last_dir = 'r';
		}
	}
}

/* disables the instance of the collectable on coordinates x and y */
void	disable_collectable(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->images->collectable->count)
	{
		if ((game->images->collectable->instances[i].x == (x * PIXEL))
			&& (game->images->collectable->instances[i].y
				== (PIXEL + (y * PIXEL))))
		{
			game->images->collectable->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

/* finishes the game */
void	finish_game(t_game *game)
{
	char	*moves;
	char	*collected;

	update_game(game);
	collected = ft_itoa(game->collected);
	moves = ft_itoa(game->moves);
	mlx_close_window(game->mlx);
	ft_putstr_fd("-------------\nGame Finished\n-------------\nCollected:", 2);
	ft_putstr_fd(collected, 2);
	ft_putstr_fd("\n-------------\nMoves:", 2);
	ft_putstr_fd(moves, 2);
	ft_putstr_fd("\n-------------\nThanks for playing\n", 2);
	free(collected);
	free(moves);
	mlx_close_window(game->mlx);
}
