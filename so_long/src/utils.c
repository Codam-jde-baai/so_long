/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/10 13:18:39 by jde-baai      #+#    #+#                 */
/*   Updated: 2023/05/26 00:37:35 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	solong_error(char *text)
{
	ft_putstr_fd("Error\n-----\nMessage: ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n-----\n", 2);
	exit(EXIT_FAILURE);
}

/* verifies that name ends with .ber */
void	verify_name(char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
		i++;
	if (name[i - 1] != 'r' || name[i - 2]
		!= 'e' || name[i - 3] != 'b' || name[i - 4] != '.')
		solong_error("Filename does not end with .ber");
}

/* loads texture into mlx_image_t image, mlx_t=so_long, png_name=name file*/
mlx_image_t	*load_texture(mlx_t	*mlx, char *png_name)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(png_name);
	if (!texture)
		solong_error("Error loading PNG");
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		solong_error("Error converting texture to image");
	mlx_delete_texture(texture);
	return (image);
}
