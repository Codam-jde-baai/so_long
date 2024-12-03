/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 13:32:26 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/28 15:37:55 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	leaktest(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	char		**map;
	t_map		*mapstruct;
	t_game		*game;
	mlx_texture_t *icon;

	atexit(leaktest);
	if (argc != 2)
		solong_error("Please input one *filename*.ber");
	verify_name(argv[1]);
	map = read_map(argv[1]);
	mapstruct = verify_map(map);
	verify_paths(mapstruct);
	game = init_game(mapstruct);
	game->mlx = mlx_init((mapstruct->width * PIXEL),
			(mapstruct->height * PIXEL) + PIXEL, "so_long", false);
	icon = mlx_load_png("images2/icon.png");
	if (!icon)
		exit(EXIT_FAILURE);
	mlx_set_icon(game->mlx, icon);
	if (!game->mlx)
		solong_error("error initializing mlx");
	game->images = load_png(game->mlx);
	place_tiles(game);
	update_game(game);
	mlx_key_hook(game->mlx, &sl_hooks, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
