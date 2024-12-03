/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 19:32:18 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/28 14:55:47 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	display_moves(t_game *game);
static void	display_collected(t_game *game);

void	update_game(t_game *game)
{
	display_moves(game);
	display_collected(game);
	if (game->collected == game->mapstruct->collectables
		&& game->exit_open == false)
	{
		game->images->exit_closed->instances[0].enabled = false;
		game->exit_open = true;
	}
}

static void	display_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	if (game->moves_img)
		mlx_delete_image(game->mlx, game->moves_img);
	game->moves_img = mlx_put_string(game->mlx, moves, (0.2 * PIXEL),
			(0.5 * PIXEL));
	free(moves);
	moves = NULL;
}

static void	display_collected(t_game *game)
{
	char	*collected;

	collected = ft_itoa(game->collected);
	if (game->collected_img)
		mlx_delete_image(game->mlx, game->collected_img);
	game->collected_img = mlx_put_string(game->mlx, collected, PIXEL,
			(0.5 * PIXEL));
	free(collected);
	collected = NULL;
}
