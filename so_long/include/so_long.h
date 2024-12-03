/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 14:47:36 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/28 14:00:53 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft_getnl/libft.h"
# define WIDTH 512
# define HEIGHT 512
# define PIXEL 64

typedef struct s_instance
{
	mlx_image_t		*background;
	mlx_image_t		*wall;
	mlx_image_t		*collectable;
	mlx_image_t		*exit_closed;
	mlx_image_t		*exit_open;
	mlx_image_t 	*statusbar;
	mlx_image_t 	*statusbar_left;
	mlx_image_t 	*statusbar_right;
	mlx_image_t 	*player;
	mlx_texture_t	*player_up;
	mlx_texture_t	*player_down;
	mlx_texture_t	*player_left;
	mlx_texture_t	*player_right;
	char			last_dir;
}	t_instance;

typedef struct s_map
{
	char	**map;
	int		collectables;
	int		exit;
	int		player;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*mapstruct;
	t_instance	*images;
	int			collected;
	bool		exit_open;
	int			player_x;
	int			player_y;
	int			moves;
	mlx_image_t	*moves_img;
	mlx_image_t *collected_img;
} t_game;

/* utils */
void	solong_error(char *text);
void	verify_name(char *name);

/* Read & verify map */
char	**read_map(char *filename);
t_map	*verify_map(char **map);
void	verify_paths(t_map *mapstruct);

/* initialize structs */
t_map	*init_map(char **mapinput, int widthinput);
t_game	*init_game(t_map *mapstruct);

/* texture */
mlx_image_t	*load_texture(mlx_t	*mlx, char *png_name);
t_instance	*load_png(mlx_t *mlx);

/* place images */
void		place_tiles(t_game *game);

/* movement */
void	sl_hooks(mlx_key_data_t keydata, void* param);
void	player_dir(t_game *game, char dir);
void	disable_collectable(t_game *game, int x, int y);
void	update_game(t_game *game);
void	finish_game(t_game *game);

#endif /* SO_LONG_H */
